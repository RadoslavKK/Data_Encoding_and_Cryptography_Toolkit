#include "base64KeyValidator.h"
#include <iostream>
#include <stdexcept>

Base64KeyValidator::Base64KeyValidator() {}

bool Base64KeyValidator::validate64(const std::string& key)
{
    try
    {
        unsigned short contentLength = static_cast<unsigned short>(key.length());

        // std::cout << "Base64 Key Contents  : \"" << key << "\"" << std::endl;

        switch (contentLength)
        {
        case 64:
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
