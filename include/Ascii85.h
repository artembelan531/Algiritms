#ifndef ASCII85_H
#define ASCII85_H

#include <vector>
#include <string>

// Функция для кодирования данных в ASCII85
std::string encodeToAscii85(const std::vector<unsigned char>& data);

// Функция для декодирования ASCII85
std::vector<unsigned char> decodeFromAscii85(const std::string& input);

#endif
