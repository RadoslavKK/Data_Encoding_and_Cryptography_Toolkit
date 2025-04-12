#include "filePathManager.h"

// Private constructor
FilePathManager::FilePathManager() : base64KeyPath(""), base62KeyPath("") {}

// Get the one and only instance
FilePathManager& FilePathManager::getInstance()
{
    static FilePathManager instance;
    return instance;
}

// Setters
void FilePathManager::setBase64KeyPath(const std::string& path)
{
    base64KeyPath = path;
}

void FilePathManager::setBase62KeyPath(const std::string& path)
{
    base62KeyPath = path;
}

// Getters
std::string FilePathManager::getBase64KeyPath() const
{
    return base64KeyPath;
}

std::string FilePathManager::getBase62KeyPath() const
{
    return base62KeyPath;
}
