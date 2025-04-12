#include <iostream>
#include <string>

// Base64 and Base62 Key File's Path
#include "FilePathManager.h"

// Open and Read Files
#include "fileReader.h"

// Remove white space from key
#include "removeSpaces.h"

// Validate the Base64 Key
#include "base64KeyValidator.h"

// Base64 Encoder
#include "base64Decoder.h"

void executeBase64Decoder()
{
    std::string inputText = "";
    std::string outputText = "";
    std::string result = "";
    std::string filePath = "";
    bool key = false;

    filePath = FilePathManager::getInstance().getBase64KeyPath();

    FileReader reader;
    result = reader.read(filePath);
    // std::cout << "Base64 File Contents : \"" << result << "\"" << std::endl;

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

    std::cout << "\nDecode a Base64 String (Simply enter your data then push the Enter/Return button) : ";

    // Capture user input
    std::getline(std::cin, inputText);

    outputText = base64Decoder(inputText, result);
    std::cout << "\nFrom Base64 : \"" << inputText << "\" to Readable : \"" << outputText << "\"\n"
              << std::endl;

    result = "";
    outputText = "";
    inputText = "";
    filePath = "";
    key = false;
}