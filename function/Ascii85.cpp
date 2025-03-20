#include "Ascii85.h"
#include <stdexcept>
#include <algorithm>

std::string encodeToAscii85(const std::vector<unsigned char>& data) {
    std::string result;
    size_t i = 0;

    while (i < data.size()) {
        uint32_t value = 0;
        int count = 0;

        for (int j = 0; j < 4; j++) {
            if (i < data.size()) {
                value |= static_cast<uint32_t>(data[i]) << (8 * (3 - j));
                i++;
                count++;
            }
        }

        if (value == 0 && count == 4) {
            result += 'z';
        } else {
            std::string ascii85;
            for (int j = 4; j >= 0; j--) {
                ascii85 += '!' + (value % 85);
                value /= 85;
            }
            std::reverse(ascii85.begin(), ascii85.end());
            if (count < 4) {
                ascii85.resize(count + 1);
            }
            result += ascii85;
        }
    }
    return result;
}

std::vector<unsigned char> decodeFromAscii85(const std::string& input) {
    std::vector<unsigned char> result;
    uint32_t value = 0;
    int count = 0;

    for (char ch : input) {
        if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t')  {
            continue; // Пропуск пробельных символов
        } else if (ch == 'z' && count == 0) {
            // Специальный случай: "z" представляет 4 нулевых байта
            result.insert(result.end(), 4, 0);
        } else if (ch >= '!' && ch <= 'u') {
            value = value * 85 + (ch - '!');
            count++;

            if (count == 5) {
                for (int i = 3; i >= 0; i--) {
                    result.push_back(static_cast<unsigned char>((value >> (8 * i)) & 0xFF));
                }
                value = 0;
                count = 0;
            }
        } else {
            throw std::runtime_error("Invalid ASCII85 character");
        }
    }

    if (count > 0) {
        for (int i = 0; i < 5 - count; i++) {
            value = value * 85 + 84; // Дополняем 'u' (84)
        }
        for (int i = 3; i > 4 - count; i--) {
            result.push_back(static_cast<unsigned char>((value >> (8 * i)) & 0xFF));
        }
    }

    return result;
}
