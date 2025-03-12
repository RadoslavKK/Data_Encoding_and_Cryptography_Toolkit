#include "base64Encoding.h"
#include "getRandomNumberInMinMaxScope.h"
#include "readBase64CharacterSet.h" // ...
#include <iostream>

std::string base64EncodingTest()
{
    std::string base64CharacterSet = readBase64CharacterSet();
    std::string randomData = "";
    char randomDataChar = ' ';
    unsigned short randomNumberForChar = 0;

    // Random Test Encode Values Settings
    unsigned short numberOfCharactersInTestEncoding = getRandomNumberInMinMaxScope(5, 20);

    for (unsigned short randomNumberGenerationCounter = 0; randomNumberGenerationCounter < numberOfCharactersInTestEncoding; randomNumberGenerationCounter++)
    {
        randomNumberForChar = getRandomNumberInMinMaxScope(0, 63);
        randomDataChar = base64CharacterSet[randomNumberForChar];
        randomData.append(1, randomDataChar);
    }

    std::cout << "Base64 Encoded Test Input \"" << randomData << "\"\n"
              << std::endl;

    randomData = base64Encoding(randomData);

    base64CharacterSet = "";

    return randomData;
}