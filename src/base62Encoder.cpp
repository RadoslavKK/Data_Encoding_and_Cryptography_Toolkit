#include "base62Encoder.h"

#include <iostream>
#include <bitset>
#include <string>

std::string base62Encoder(const std::string &data, const std::string &key)
{
    std::string inputText = data;

    // Logs Switch
    bool userLogs = false;
    bool adminLogs = false;

    char inputCharacther = ' ';
    std::string binaryStream = "";

 // Convert each character to its binary (ASCII) representation
    for (unsigned short i = 0; i < inputText.length(); ++i)
    {
        inputCharacther = inputText[i];
        if (adminLogs) std::cout << inputCharacther << "\n";

        std::bitset<8> binary(inputCharacther);
        if (adminLogs) std::cout << binary << "\n";

        binaryStream += binary.to_string();
    }

    if (userLogs){
        std::cout << binaryStream << "\n";
    }
    // Make the binary stream length a multiple of 6
    unsigned short padCount = 6;
    unsigned short paddingCount = binaryStream.length() % padCount;

    if (paddingCount > 0)
    {
        unsigned short bitsToPad = padCount - paddingCount;
        binaryStream.append(bitsToPad, '0');

        if (userLogs)
        {
            std::cout << "\nBinary Padding: " << bitsToPad << " bit"
                      << (bitsToPad > 1 ? "s" : "") << "\n";
            std::cout << "Padded Binary: " << binaryStream << "\n\n";
        }
    }

    std::string finalStream = "";
    std::string shortBinaryStream = "";
    unsigned short binaryStreamSize = 6;
    unsigned int decimalNumber = 0;
    char app = ' ';

    for (unsigned short i = 0; i < binaryStream.length(); i += 6)
    {
        shortBinaryStream = binaryStream.substr(i, binaryStreamSize);

        if (adminLogs)
        {
            std::cout << " = " << shortBinaryStream << "\n";
        }

        decimalNumber = std::stoi(shortBinaryStream, nullptr, 2);

        if (adminLogs)
        {
            std::cout << " == " << decimalNumber << "\n\n";
        }

        // Clamp to 62-character set (in case decimal exceeds 61)
        if (decimalNumber < key.length())
        {
            app = key[decimalNumber];
        }
        else
        {
            app = key[decimalNumber % key.length()]; // fallback safety
        }

        finalStream += app;
    }

    return finalStream;
}