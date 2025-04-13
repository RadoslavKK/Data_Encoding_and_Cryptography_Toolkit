#include <iostream>
#include <string>
#include "executeBinary.h"

// Remove white space from key
#include "removeSpaces.h"

// Binary Code Validation
#include "binaryValidator.h"

// Convert Binary to Oct, Dec, Hex
#include "binaryToConverter.h"

void executeBinary()
{
    std::string inputText = "";

    std::cout << "\nEnter a binary string (without spaces) : ";

    // Capture user input
    std::getline(std::cin, inputText);

    StringFormatter remover;
    inputText = remover.removeSpaces(inputText);

    if (isValidBinary(inputText))
    {
        std::cout << ("\nValid Binary\n\n");
    }
    else
    {
        std::cout << ("\nNot a Valid Binary\n\n");
    }

    binaryConvertor(inputText);

    inputText.clear();
}