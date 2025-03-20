#include <iostream>
#include <string>
#include "isValidBinary.h"

bool isValidBinary(const std::string binaryString)
{
    for (int i = 0; i < binaryString.size(); i++)
    {
        if (binaryString[i] != '0' && binaryString[i] != '1')
        {
            return false;
        }
    }
    return true;
}