#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

class FileReader
{
public:
    FileReader();                               // default constructor
    std::string read(const std::string& path);  // read method that accepts path
};

#endif // FILE_READER_H
