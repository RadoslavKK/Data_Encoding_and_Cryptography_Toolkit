#include "readBase64CharacterSet.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string readBase64CharacterSet()
{
    std::string content = "";

    try
    {
        std::ifstream file("data.txt"); // Open the file
        if (!file)
        {
            throw std::runtime_error("Error opening file!");
        }

        std::stringstream buffer;
        buffer << file.rdbuf(); // Read file contents into a buffer
        content = buffer.str();

        file.close(); // Explicitly close the file

        unsigned short contentLength = content.length();

        switch (contentLength)
        {
        case 64:
            return content;

        case 0:
            return "Error: Key not found";

        default:
            if (contentLength != 64)
            {
                return "Error: Not a valid key length";
            }

            return "Error: File contains incorrect data";
        }
    }
    catch (const std::exception &e)
    {
        return std::string("Exception: ") + e.what();
    }
    catch (...)
    {
        return "Unknown error occurred!";
    }
}
