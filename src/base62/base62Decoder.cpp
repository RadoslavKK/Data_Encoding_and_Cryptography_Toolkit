#include "base62/base62Decoder.h"

#include <iostream>
#include <bitset>
#include <string>

std::string base62Decoder(const std::string &encodedData, const std::string &key)
{
    std::string inputText = encodedData;

    // Logs Switch
    bool userLogs = false;
    bool adminLogs = false;

    std::string binaryStream = "";
    char currentChar = ' ';
    size_t charIndex = 0;

    // Convert each Base62 character to 6-bit binary
    for (unsigned short i = 0; i < inputText.length(); ++i)
    {
        currentChar = inputText[i];

        charIndex = key.find(currentChar);
        if (charIndex == std::string::npos)
        {
            std::cerr << "Invalid character in encoded string: " << currentChar << "\n";
            continue;
        }

        if (adminLogs)
        {
            std::cout << currentChar << " -> " << charIndex << "\n";
        }

        std::bitset<6> binary(charIndex);
        if (adminLogs)
        {
            std::cout << "Binary: " << binary << "\n";
        }

        binaryStream += binary.to_string();
    }

    if (userLogs)
    {
        std::cout << "Full binary stream: " << binaryStream << "\n";
    }

    std::string finalText = "";
    std::string byteString = "";
    unsigned int byteValue = 0;

    // Split binary stream into bytes (8 bits)
    for (unsigned short i = 0; i + 8 <= binaryStream.length(); i += 8)
    {
        byteString = binaryStream.substr(i, 8);
        byteValue = std::stoi(byteString, nullptr, 2);

        if (adminLogs)
        {
            std::cout << byteString << " -> " << byteValue << " -> " << static_cast<char>(byteValue) << "\n";
        }

        finalText += static_cast<char>(byteValue);
    }

    return finalText;
}