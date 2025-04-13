#include <iostream>
#include <string>

// Base64 and Base62 Key File's Path
#include "filePathManager.h"

// Open and Read Files
#include "fileReader.h"

// Remove white space from key
#include "removeSpaces.h"

// Validate the Base64 Key
#include "base64KeyValidator.h"

// Base64 Encoder
#include "base64Encoder.h"

void executeBase64Encoder()
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

    std::cout << "\nEncode a String to Base64 (Simply enter your data then push the Enter/Return button) : ";

    // Capture user input
    std::getline(std::cin, inputText);

    outputText = base64Encoder(inputText, result);
    std::cout << "\n\"" << inputText << "\" to Base64 : \"" << outputText << "\"\n"
              << std::endl;

    inputText.clear();
    outputText.clear();
    result.clear();
    filePath.clear();
    key = false;
}