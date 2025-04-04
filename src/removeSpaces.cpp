#include "removeSpaces.h"

std::string StringFormatter::removeSpaces(const std::string& input)
{
    std::string result;

    for (size_t i = 0; i < input.size(); ++i)
    {
        if (input[i] != ' ')
        {
            result += input[i]; 
        }
    }

    return result;
}