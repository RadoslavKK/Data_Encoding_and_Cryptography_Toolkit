#include <iostream>
#include <string>
#include "removeSpaces.h"

std::string removeSpaces(std::string numberString)
{
    std::string result;
    
    for (int i = 0; i < numberString.size(); i++)
    {
        if (numberString[i] != ' ')
        {
            result += numberString[i]; // Append non-space characters to result
        }
    }

    return result;
}