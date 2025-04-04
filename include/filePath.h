#ifndef FILE_PATH_H
#define FILE_PATH_H

#include <string>

class FilePath
{
private:
    std::string base64KeyPath;
    std::string base62KeyPath;

public:
    FilePath();

    void setBase64KeyPath(const std::string &path);
    void setBase62KeyPath(const std::string &path);

    std::string getBase64KeyPath() const;
    std::string getBase62KeyPath() const;
};

#endif