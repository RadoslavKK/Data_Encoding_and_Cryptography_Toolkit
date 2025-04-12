#ifndef FILE_PATH_MANAGER_H
#define FILE_PATH_MANAGER_H

#include <string>

class FilePathManager
{
private:
    std::string base64KeyPath;
    std::string base62KeyPath;

    // Private constructor to prevent direct instantiation
    FilePathManager();

    // Copy constructor and assignment operator
    FilePathManager(const FilePathManager &other);            // Declared but not defined (disallowed in C++98)
    FilePathManager &operator=(const FilePathManager &other); // Declared but not defined (disallowed in C++98)

public:
    // Access the singleton instance
    static FilePathManager &getInstance();

    // Setters
    void setBase64KeyPath(const std::string &path);
    void setBase62KeyPath(const std::string &path);

    // Getters
    std::string getBase64KeyPath() const;
    std::string getBase62KeyPath() const;
};

#endif