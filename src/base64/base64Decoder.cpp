#include "base64/base64Decoder.h"

#include <bitset>
#include <string>

std::string base64Decoder(const std::string &data, const std::string &key)
{
    std::string inputText = data;
    std::string base64CharacterSet = key;
    std::string base64CharacterStream = "";
    unsigned short paddingCounter = 0;

    // Convert Base64 input to binary representation
    for (size_t i = 0; i < inputText.length(); i++)
    {
        char inputCharacter = inputText[i];

        if (inputCharacter != '=')
        {
            size_t index = base64CharacterSet.find(inputCharacter);
            if (index != std::string::npos)
            {
                std::bitset<6> binary(index);
                base64CharacterStream += binary.to_string();
            }
        }
        else
        {
            paddingCounter++; // Count padding characters
        }
    }

    // Remove extra bits caused by '=' padding
    if (paddingCounter > 0)
    {
        size_t bitsToRemove = paddingCounter * 2;
        if (base64CharacterStream.length() >= bitsToRemove)
        {
            base64CharacterStream = base64CharacterStream.substr(0, base64CharacterStream.length() - bitsToRemove);
        }
    }

    // Convert 8-bit binary chunks to ASCII characters
    std::string decodedString = "";
    for (size_t i = 0; i + 8 <= base64CharacterStream.length(); i += 8)
    {
        std::bitset<8> binary(base64CharacterStream.substr(i, 8));
        decodedString += static_cast<char>(binary.to_ulong());
    }

    return decodedString;
}
