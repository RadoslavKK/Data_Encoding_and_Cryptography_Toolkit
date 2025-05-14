#include "keyOptions.h"

// Remove White Space
#include "removeSpaces.h"

// To Lower Case String
#include "toLowerCase.h"

// ______________________________________________________________________________________

// Base64 and Base62 Key File's Path
#include "filePathManager.h"

// Open and Read Files
#include "fileReader.h"

// ______________________________________________________________________________________

// Validate the Base64 Key
#include "base64/base64KeyValidator.h"

// Validate the Base62 Key
#include "base62/base62KeyValidator.h"

// ______________________________________________________________________________________

// Generate a Random Number in the [5 - 20] & [0 - 63] scope's
#include "getRandomNumberInMinMaxScope.h"

// ______________________________________________________________________________________

#include <iostream>
#include <string>

void KeyOptions::keyComapare()
{
    std::cout << "\nKey Comparison Utility (ignores leading/trailing whitespace)\n";

    std::string firstKey = "";
    std::string secondKey = "";
    std::string inputText = "";
    bool removeWhiteSpace = false;

    // Create obj to Remove White Space
    StringFormatter remover;

    std::cout << "\n";

    do
    {
        std::cout << "Would you like to remove white spaces from the key string? (yes/no): ";
        std::getline(std::cin, inputText);

        inputText = remover.removeSpaces(inputText);
        inputText = toLowerCase(inputText);

        if (inputText != "yes" && inputText != "no")
        {
            std::cout << "\nInvalid input. Please enter 'yes' or 'no'.\n\n";
        }
    } while (inputText != "yes" && inputText != "no");

    // Set the removeWhiteSpace flag based on user's input
    if (inputText == "yes")
    {
        removeWhiteSpace = true;
        std::cout << "\nWhite spaces will be removed from the key string.\n\n";
    }
    else
    {
        std::cout << "\nWhite spaces will not be removed from the key string.\n\n";
    }

    do
    {
        std::cout << "Enter the first key: ";
        std::getline(std::cin, firstKey);
        if (removeWhiteSpace)
        {
            firstKey = remover.removeSpaces(firstKey);
        }
    } while (firstKey.empty());

    std::cout << "\n";

    do
    {
        std::cout << "Enter the second key: ";
        std::getline(std::cin, secondKey);
        if (removeWhiteSpace)
        {
            secondKey = remover.removeSpaces(secondKey);
        }
    } while (secondKey.empty());

    std::cout << "\n";

    if (firstKey == secondKey)
    {
        std::cout << "\033[1;32mThe keys match.\033[0m" << "\n"
                  << std::endl;
    }
    else
    {
        std::cout << "\033[1;31mThe keys do not match.\033[0m" << "\n"
                  << std::endl;
    }

    firstKey.clear();
    secondKey.clear();
    inputText.clear();
    removeWhiteSpace = false;
}

void KeyOptions::generateRandomKey()
{
    unsigned short keyLength = 0;
    std::string input = "";
    std::string result = "";
    std::cout << "\n";

    do
    {
        std::cout << "Enter Key Length [1 < LENGTH <= 100]: ";
        std::getline(std::cin, input);

        try
        {
            keyLength = static_cast<unsigned short>(std::stoi(input));
        }
        catch (const std::exception &e)
        {
            keyLength = 0;
        }

    } while (keyLength <= 1 || keyLength > 100);

    std::cout << "\nAccepted Key Length : \033[1;32m" << keyLength << "\033[0m" << std::endl;

    std::string randomData = "";
    std::string filePath = "";

    filePath = FilePathManager::getInstance().getBase64KeyPath();

    FileReader reader;
    result = reader.read(filePath);

    // Create obj to Remove White Space
    StringFormatter remover;
    result = remover.removeSpaces(result);

    for (unsigned short i = 0; i < keyLength; ++i)
    {
        unsigned short randomNumberForChar = getRandomNumberInMinMaxScope(0, result.size() - 1);
        char randomDataChar = result[randomNumberForChar];
        randomData.append(1, randomDataChar);
    }

    if (randomData.length() == keyLength)
    {
        std::cout << "\nGenerated Key : \"\033[1;32m" << randomData << "\033[0m\"\n"
                  << std::endl;
    }
    else
    {
        std::cerr << "\nError: Failed to generate key with the correct length (expected "
                  << keyLength << ", got " << randomData.length() << ").\n"
                  << std::endl;
    }

    keyLength = 0;
    input.clear();
    result.clear();
    randomData.clear();
    filePath.clear();
}

void KeyOptions::generateBaseCodeKey(const unsigned short &baseCode)
{
    const unsigned short keyLength = baseCode;

    std::string input = "";
    std::string result = "";
    std::string randomData = "";
    std::string filePath = "";

    // Retrieve the path for the Base64 key from FilePathManager
    filePath = FilePathManager::getInstance().getBase62KeyPath();

    // Read the content from the file
    FileReader reader;
    result = reader.read(filePath);

    // Remove any unnecessary whitespace from the read data
    StringFormatter formatter;
    result = formatter.removeSpaces(result);

    // Generate a random key of the specified length using characters from the processed result
    for (unsigned short i = 0; i < keyLength; ++i)
    {
        unsigned short randomIndex = getRandomNumberInMinMaxScope(0, result.size() - 1);
        randomData += result[randomIndex]; // Append the random character to the key
    }

    // Output the result, ensuring the key length matches the expectation

    if (baseCode == 62)
    {
        if (randomData.length() == keyLength)
        {
            std::cout << "\nGenerated Base62 Key: \"\033[1;32m" << randomData << "\033[0m\"\n"
                      << std::endl;
        }
        else
        {
            std::cerr << "\nError: Failed to generate a Base62 key with the expected length (expected "
                      << keyLength << ", got " << randomData.length() << ").\n"
                      << std::endl;
        }
    }

    // Output the result, ensuring the key length matches the expectation

    if (baseCode == 64)
    {

        if (randomData.length() == keyLength)
        {
            std::cout << "\nGenerated Base64 Key: \"\033[1;32m" << randomData << "\033[0m\"\n"
                      << std::endl;
        }
        else
        {
            std::cerr << "\nError: Failed to generate a Base64 key with the expected length (expected "
                      << keyLength << ", got " << randomData.length() << ").\n"
                      << std::endl;
        }
    }

    // Clear sensitive data

    input.clear();
    result.clear();
    randomData.clear();
    filePath.clear();
}