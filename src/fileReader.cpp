#include "fileReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

FileReader::FileReader() {}

std::string FileReader::read(const std::string& path)
{
    std::string content = "";

    try
    {
        std::ifstream file(path.c_str());
        if (!file)
        {
            throw std::runtime_error("Error opening file!");
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        content = buffer.str();

        file.close();
        return content;
    }
    catch (const std::exception& e)
    {
        return std::string("Exception: ") + e.what();
    }
    catch (...)
    {
        return "Unknown error occurred!";
    }
}
