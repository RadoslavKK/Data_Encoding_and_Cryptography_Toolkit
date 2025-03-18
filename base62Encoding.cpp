#include "base62Encoding.h"
#include "readBase62CharacterSet.h" // For getting the Base62 character set used for encoding
#include <iostream>
#include <bitset>

std::string base62Encoding(std::string data)
{
    std::string inputText = data;

    // Logs Switch
    bool userLogs = false;
    bool adminLogs = false;

    std::cout << "\nUser Input : \"" << inputText << "\"\n";
    std::cout << "Number of Characters : " << inputText.length() << "\n\n";

    char inputCharacter = ' ';

    // Store the binary representation of the input text
    std::string binaryStream = "";

    // Convert each character in the inputText to its binary (ASCII) representation
    for (unsigned short counterLength = 0; counterLength < inputText.length(); counterLength++)
    {
        inputCharacter = inputText[counterLength];

        // Print Admin Log
        if (adminLogs == true)
        {
            std::cout << inputCharacter << "\n";
        }

        std::bitset<8> binary(inputCharacter);

        // Print Admin Log
        if (adminLogs == true)
        {
            std::cout << binary << "\n";
        }

        binaryStream += binary.to_string();
    }

    // Print User Log
    if (userLogs == true)
    {
        std::cout << binaryStream << "\n";
    }

    unsigned short paddingCount = 0;
    unsigned short padCount = 6;

    // Calculate necessary padding to make the binary stream length a multiple of 6
    paddingCount = binaryStream.length() % 6;
    unsigned short charPadding = paddingCount;

    if (paddingCount > 0)
    {
        // Print User Log
        if (userLogs == true)
        {
            if ((padCount - paddingCount) > 1)
            {
                std::cout << "\nBinary Padding is : " << padCount - paddingCount << " bit's\n";
            }
            else
            {
                std::cout << "\nBinary Padding is : " << padCount - paddingCount << " bit\n";
            }
        }

        for (; paddingCount < padCount; paddingCount++)
        {
            binaryStream.append("0");
        }

        // Print User Log
        if (userLogs == true)
        {
            std::cout << "\n"
                      << binaryStream << "\n\n";
        }
    }

    unsigned short binaryStreamSize = 6;
    std::string shortBinaryStream = "";
    unsigned int decimalNumber = 0;

    // Base62 character set used for encoding
    std::string base62CharacterSet = readBase62CharacterSet();
    std::string finalStream = "";
    char app = ' ';

    // Loop through the binaryStream in 6-bit chunks
    for (unsigned short startPoint = 0; startPoint < binaryStream.length(); startPoint += 6)
    {
        shortBinaryStream = binaryStream.substr(startPoint, binaryStreamSize);

        // Print Admin Log
        if (adminLogs == true)
        {
            std::cout << " = " << shortBinaryStream << "\n";
        }

        decimalNumber = std::stoi(shortBinaryStream, nullptr, 2);

        // Print Admin Log
        if (adminLogs == true)
        {
            std::cout << " == " << decimalNumber << "\n\n";
        }

        app = base62CharacterSet[decimalNumber % 62];
        finalStream.append(1, app);
    }

    base62CharacterSet = "";

    return finalStream;
}