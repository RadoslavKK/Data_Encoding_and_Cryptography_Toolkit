#include "toLowerCase.h"
#include <string>

std::string toLowerCase(const std::string &str)
{
    std::string lowerStr = str; // Make a copy of the input string
    for (size_t i = 0; i < lowerStr.length(); ++i)
    {
        // Convert each character to lowercase if it's an uppercase letter
        if (lowerStr[i] >= 'A' && lowerStr[i] <= 'Z')
        {
            lowerStr[i] = lowerStr[i] + ('a' - 'A');
        }
    }
    return lowerStr;
}