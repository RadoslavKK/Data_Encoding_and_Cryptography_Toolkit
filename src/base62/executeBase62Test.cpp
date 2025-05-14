#include "base62/executeBase62Test.h"

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

// Validate the Base62 Key
#include "base62/base62KeyValidator.h"

// ______________________________________________________________________________________

// Base62 Encoder
#include "base62/base62Encoder.h"

// Base62 Decoder
#include "base62/base62Decoder.h"

// Generate a Random Number in the [5 - 20] & [0 - 61] scope's
#include "getRandomNumberInMinMaxScope.h"

void executeBase62Test()
{

    std::string inputText = "";
    std::string outputText = "";
    std::string result = "";
    std::string filePath = "";
    bool key = false;

    filePath = FilePathManager::getInstance().getBase62KeyPath();
    // std::cout << "File  Path : \"" << filePath << "\"" << std::endl;

    FileReader reader;
    result = reader.read(filePath);
    // std::cout << "Base62 File Contents : \"" << result << "\"" << std::endl;

    // Create obj to Remove White Space
    StringFormatter remover;
    result = remover.removeSpaces(result);
    // std::cout << "Base62 File Contents : \"" << result << "\"" << std::endl;

    Base62KeyValidator keyValidator62;
    key = keyValidator62.validate62(result);

    if (key)
    {
        std::cout << "\nValid Base62 Key\n";
    }
    else
    {
        std::cout << "\nNot a Valid Base62 Key\n";
    }

    std::string randomData = "";
    char randomDataChar = ' ';
    unsigned short randomNumberForChar = 0;

    // Random Test Encode Values Settings
    unsigned short numberOfCharactersInTestEncoding = getRandomNumberInMinMaxScope(5, 20);

    for (unsigned short randomNumberGenerationCounter = 0; randomNumberGenerationCounter < numberOfCharactersInTestEncoding; randomNumberGenerationCounter++)
    {
        randomNumberForChar = getRandomNumberInMinMaxScope(0, 61); // Base62 range
        randomDataChar = result[randomNumberForChar];
        randomData.append(1, randomDataChar);
    }

    inputText = randomData;

    // Encode to Base62
    outputText = base62Encoder(inputText, result);
    std::cout << "\n[Random String]   Original Text            : \"" << inputText << "\"\n"
              << "\n[Base62 Encoding] Encoded to Base62        : \"" << outputText << "\"\n"
              << std::endl;

    // Decode from Base62
    outputText = base62Decoder(outputText, result);

    std::cout << "[Base62 Decoding] Decoded to Readable Text : \"" << outputText << "\"\n"
              << std::endl;

    if (inputText == outputText)
    {
        std::cout << "Base62 Encoder/Decoder Test: \033[32mPassed\033[0m.\n"
                  << std::endl; // Green for Passed
    }
    else
    {
        std::cout << "Base62 Encoder/Decoder Test: \033[31mFailed\033[0m.\n"
                  << std::endl; // Red for Failed
    }

    inputText.clear();
    outputText.clear();
    result.clear();
    filePath.clear();
    key = false;
}