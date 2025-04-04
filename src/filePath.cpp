#include "filePath.h"

FilePath::FilePath() {}

void FilePath::setBase64KeyPath(const std::string& path)
{
    base64KeyPath = path;
}

void FilePath::setBase62KeyPath(const std::string& path)
{
    base62KeyPath = path;
}

std::string FilePath::getBase64KeyPath() const
{
    return base64KeyPath;
}

std::string FilePath::getBase62KeyPath() const
{
    return base62KeyPath;
}
