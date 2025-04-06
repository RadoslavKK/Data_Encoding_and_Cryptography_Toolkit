#include "binaryValidator.h"

bool isValidBinary(const std::string &binaryString)
{
    size_t start = 0;

    // Check for and skip optional "0x" or "0X" prefix
    if (binaryString.length() >= 2 && binaryString[0] == '0' &&
        (binaryString[1] == 'b' || binaryString[1] == 'B'))
    {
        start = 2;
    }

    // Check that remaining characters are 0 or 1
    for (size_t i = start; i < binaryString.size(); ++i)
    {
        if (binaryString[i] != '0' && binaryString[i] != '1')
        {
            return false;
        }
    }

    // Return false if prefix exists but no binary digits follow
    return binaryString.size() > start;
}