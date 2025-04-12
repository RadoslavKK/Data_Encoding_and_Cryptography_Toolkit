#include <iostream>
#include <string>
#include "executeHex.h"

// Remove white space from key
#include "removeSpaces.h"

// Hex Code Valitation
#include "hexValidator.h"

// Convert Hexadecimal to Bin, Oct, Dec
#include "hexToConverter.h"

void executeHex()
{
    std::string inputText = "";
    std::cout << "\nEnter a hexadecimal string (without spaces) : ";

    // Capture user input
    std::getline(std::cin, inputText);

    StringFormatter remover;
    inputText = remover.removeSpaces(inputText);

    if (isValidHex(inputText))
    {
        std::cout << ("\nValid Hex\n\n");
    }
    else
    {
        std::cout << ("\nNot a Valid Hex\n\n");
    }

    hexConverter(inputText);

    inputText = "";
}