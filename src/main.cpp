#include <iostream>
#include <string>
#include "Ascii85.h"

int main(int argc, char* argv[]) {
    bool decodeMode = false;

    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "-d") {
            decodeMode = true;
        } else if (arg != "-e") {
            std::cerr << "Usage: ascii85 [-e] [-d]" << std::endl;
            return 1;
        }
    }

    try {
        if (decodeMode) {
            std::string ascii85Data;
            char ch;
            while (std::cin.get(ch)) {
                ascii85Data += ch;
            }
            auto decodedData = decodeFromAscii85(ascii85Data);
            std::cout.write(reinterpret_cast<const char*>(decodedData.data()), decodedData.size());
        } else {
            std::vector<unsigned char> data;
            char ch;
            while (std::cin.get(ch)) {
                data.push_back(ch);
            }
            auto encoded = encodeToAscii85(data);
            std::cout << encoded << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
