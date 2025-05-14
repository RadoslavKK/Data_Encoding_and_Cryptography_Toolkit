#include <iostream>
#include <string>

// Base64 and Base62 Key File's Path
#include "filePathManager.h"

// Open and Read Files
#include "fileReader.h"

// Remove white space from key
#include "removeSpaces.h"

// Validate the Base64 Key
#include "base62/base62KeyValidator.h"

// Base62 Decoder
#include "base62/base62Decoder.h"

void executeBase62Decoder()
{

    std::string inputText = "";
    std::string outputText = "";
    std::string result = "";
    std::string filePath = "";
    bool key = false;

    filePath = FilePathManager::getInstance().getBase62KeyPath();

    FileReader reader;
    result = reader.read(filePath);
    // std::cout << "Base62 File Contents : \"" << result << "\"" << std::endl;

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

    std::cout << "\nDecode a Base62 String (Simply enter your Base62 text then push the Enter/Return button) : ";

    // Capture user input
    std::getline(std::cin, inputText);

    outputText = base62Decoder(inputText, result);
    std::cout << "\nBase62 \"" << inputText << "\" to Text : \"" << outputText << "\"\n"
              << std::endl;

    result.clear();
    inputText.clear();
    outputText.clear();
    filePath.clear();
    key = false;
}