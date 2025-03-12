#include "base64Decoding.h"
#include "readBase64CharacterSet.h" // Fro getting the Base64 character set used for encoding
#include <iostream>
#include <string>
#include <bitset>

std::string base64Decoding(std::string data)
{
    std::string inputText = data;
    // std::cout << "\nUser Input : \"" << inputText << "\"\n";
    // std::cout << "Number of Characters : " << inputText.length() << "\n\n";

    std::string base64CharacterSet = readBase64CharacterSet();
    std::string base64CharactherStream = "";
    unsigned short buffCounter = 0;

    // Convert Base64 input to binary representation
    for (size_t i = 0; i < inputText.length(); i++)
    {
        char inputCharacther = inputText[i];

        if (inputCharacther != '=')
        {
            size_t index = base64CharacterSet.find(inputCharacther);
            if (index != std::string::npos)
            {
                std::bitset<6> binary(index);
                base64CharactherStream += binary.to_string();
            }
        }
        else
        {
            buffCounter++; // Count padding
        }
    }

    // Remove extra bits due to padding
    if (buffCounter > 0)
    {
        base64CharactherStream = base64CharactherStream.substr(0, base64CharactherStream.length() - (buffCounter * 2));
    }

    // Convert binary stream to ASCII text
    std::string decodedString = "";
    for (size_t i = 0; i < base64CharactherStream.length(); i += 8)
    {
        if (i + 8 > base64CharactherStream.length())
            break;
        std::bitset<8> binary(base64CharactherStream.substr(i, 8));
        decodedString += static_cast<char>(binary.to_ulong());
    }

    base64CharacterSet = "";

    return decodedString;
}