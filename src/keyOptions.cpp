#include "keyOptions.h"

// Remove White Space
#include "removeSpaces.h"

#include <iostream>
#include <string>

void KeyOptions::keyComapare()
{
    std::cout << "\nKey Comparison Utility (ignores leading/trailing whitespace)\n";

    std::string firstKey = "";
    std::string secondKey = "";

    // Create obj to Remove White Space
    StringFormatter remover;

    std::cout << "\n";

    do
    {
        std::cout << "Enter the first key: ";
        std::getline(std::cin, firstKey);
        firstKey = remover.removeSpaces(firstKey);
    } while (firstKey.empty());

    std::cout << "\n";

    do
    {
        std::cout << "Enter the second key: ";
        std::getline(std::cin, secondKey);
        secondKey = remover.removeSpaces(secondKey);
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
}
