#include "keyOptions.h"

// Remove White Space
#include "removeSpaces.h"

// To Lower Case String
#include "toLowerCase.h"

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
