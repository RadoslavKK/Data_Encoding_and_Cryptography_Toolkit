#include "hexValidator.h"
#include <cctype>

bool isValidHex(const std::string &hexString)
{
    size_t start = 0;

    // Check for and skip optional "0x", "0X", "0h", "0H" prefix
    if (hexString.length() >= 2 && hexString[0] == '0' &&
        (hexString[1] == 'x' || hexString[1] == 'X' || hexString[1] == 'h' || hexString[1] == 'H'))
    {
        start = 2;
    }

    // The string must have at least one valid hex digit after "0..."
    if (hexString.size() <= start)
    {
        return false;
    }

    for (size_t i = start; i < hexString.size(); ++i)
    {
        char c = hexString[i];
        if (!std::isdigit(c) &&
            !(c >= 'a' && c <= 'f') &&
            !(c >= 'A' && c <= 'F'))
        {
            return false;
        }
    }

    return true;
}