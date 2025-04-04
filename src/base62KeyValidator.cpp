#include "base62KeyValidator.h"
#include <iostream>
#include <stdexcept>

Base62KeyValidator::Base62KeyValidator() {}

bool Base62KeyValidator::validate62(const std::string& key)
{
    try
    {
        unsigned short contentLength = static_cast<unsigned short>(key.length());

        // std::cout << "Base62 Key Contents  : \"" << key << "\"" << std::endl;

        switch (contentLength)
        {
        case 62:
            return true;

        case 0:
            std::cout << "Error: Key not found\n";
            return false;

        default:
            if (contentLength != 64)
            {
                std::cout << "Error: Not a valid key length\n";
                return false;
            }

            std::cout << "Error: File contains incorrect data\n";
            return false;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
        return false;
    }
    catch (...)
    {
        std::cout << "Unknown error occurred!\n";
        return false;
    }
}
