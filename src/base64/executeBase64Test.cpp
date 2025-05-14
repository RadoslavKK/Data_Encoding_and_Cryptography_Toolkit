#include "base64/executeBase64Test.h"

#include <iostream>
#include <string>

// ______________________________________________________________________________________

// Base64 and Base62 Key File's Path
#include "filePathManager.h"

// Open and Read Files
#include "fileReader.h"

// Remove white space from key
#include "removeSpaces.h"

// ______________________________________________________________________________________

// Validate the Base64 Key
#include "base64/base64KeyValidator.h"

// ______________________________________________________________________________________

// Base64 Encoder
#include "base64/base64Encoder.h"

// Base64 Encoder
#include "base64/base64Decoder.h"

// Generate a Random Number in the [5 - 20] & [0 - 63] scope's
#include "getRandomNumberInMinMaxScope.h"

void executeBase64Test()
{

    std::string inputText = "";
    std::string outputText = "";
    std::string result = "";
    std::string filePath = "";
    bool key = false;

    filePath = FilePathManager::getInstance().getBase64KeyPath();
    // std::cout << "File  Path : \"" << filePath << "\"" << std::endl;

    FileReader reader;
    result = reader.read(filePath);
    // std::cout << "Base64 File Contents : \"" << result << "\"" << std::endl;

    // Create obj to Remove White Space
    StringFormatter remover;
    result = remover.removeSpaces(result);
    // std::cout << "Base64 File Contents : \"" << result << "\"" << std::endl;

    Base64KeyValidator keyValidator64;
    key = keyValidator64.validate64(result);

    if (key)
    {
        std::cout << "\nValid Base64 Key\n";
    }
    else
    {
        std::cout << "\nNot a Valid Base64 Key\n";
    }

    std::string randomData = "";
    char randomDataChar = ' ';
    unsigned short randomNumberForChar = 0;

    // Random Test Encode Values Settings
    unsigned short numberOfCharactersInTestEncoding = getRandomNumberInMinMaxScope(5, 20);

    for (unsigned short randomNumberGenerationCounter = 0; randomNumberGenerationCounter < numberOfCharactersInTestEncoding; randomNumberGenerationCounter++)
    {
        randomNumberForChar = getRandomNumberInMinMaxScope(0, 63);
        randomDataChar = result[randomNumberForChar];
        randomData.append(1, randomDataChar);
    }

    inputText = randomData;

    // Encode to Base64
    outputText = base64Encoder(inputText, result);
    std::cout << "\n[Random String]   Original Text            : \"" << inputText << "\"\n"
              << "\n[Base64 Encoding] Encoded to Base64        : \"" << outputText << "\"\n"
              << std::endl;

    // Decode from Base64
    outputText = base64Decoder(outputText, result);

    std::cout << "[Base64 Decoding] Decoded to Readable Text : \"" << outputText << "\"\n"
              << std::endl;

    if (inputText == outputText)
    {
        std::cout << "Base64 Encoder/Decoder Test: \033[32mPassed\033[0m.\n"
                  << std::endl; // Green for Passed
    }
    else
    {
        std::cout << "Base64 Encoder/Decoder Test: \033[31mFailed\033[0m.\n"
                  << std::endl; // Red for Failed
    }

    inputText.clear();
    outputText.clear();
    result.clear();
    filePath.clear();
    key = false;
}