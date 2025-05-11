#include "cursorOptions.h"
#include <iostream>

std::string changeCursor(const std::string& oldCursor)
{
    std::string newCursor;

    std::cout << "\nCurrent cursor: \"" << oldCursor << "\"" << std::endl;

    do
    {
        std::cout << "\nPlease enter a new cursor value (max 15 characters) : ";
        std::getline(std::cin, newCursor);

        if (newCursor.length() > 15)
        {
            std::cout << "\nError: Cursor value must not exceed 15 characters.\n";
        }
        else if (newCursor.empty())
        {
            std::cout << "\nError: Cursor value cannot be empty.\n";
        }

    } while (newCursor.empty() || newCursor.length() > 15);

    newCursor.append(" ");

    std::cout << std::endl;

    return newCursor;
}