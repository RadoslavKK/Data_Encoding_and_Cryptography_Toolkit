#include "base64Encoding.h"
#include "readBase64CharacterSet.h" // Fro getting the Base64 character set used for encoding
#include <iostream>
// #include <bitset>

std::string base64Encoding(std::string data)
{
    std::string inputText = data;

    // Logs Switch
    bool userLogs = false;
    bool adminLogs = false;

    char inputCharacther = ' ';

    // Store the binary representation of the input text
    std::string binaryStream = "";

    // Convert each character in the inputText to its binary (ASCII) representation
    for (unsigned short counterLength = 0; counterLength < inputText.length(); counterLength++)
    {
        inputCharacther = inputText[counterLength];

        // Print Admin Log
        if (adminLogs == true)
        {
            std::cout << inputCharacther << "\n";
        }

        std::bitset<8> binary(inputCharacther);

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
    std::string shortBinaryStrem = "";
    unsigned int decimalNumber = 0;

    // Base64 character set used for encoding
    std::string base64CharacterSet = readBase64CharacterSet();
    std::string finalStream = "";
    char app = ' ';

    // Loop through the binaryStream in 6-bit chunks
    for (unsigned short startPoint = 0; startPoint < binaryStream.length(); startPoint += 6)
    {
        shortBinaryStrem = binaryStream.substr(startPoint, binaryStreamSize);

        // Print Admin Log
        if (adminLogs == true)
        {
            std::cout << " = " << shortBinaryStrem << "\n";
        }

        decimalNumber = std::stoi(shortBinaryStrem, nullptr, 2);

        // Print Admin Log
        if (adminLogs == true)
        {
            std::cout << " == " << decimalNumber << "\n\n";
        }

        app = base64CharacterSet[decimalNumber];
        finalStream.append(1, app);
    }

    // Append '=' padding based on the original padding count
    if (charPadding == 2)
    {
        finalStream.append("==");
    }
    else if (charPadding == 4)
    {
        finalStream.append("=");
    }

    base64CharacterSet = "";

    return finalStream;
}