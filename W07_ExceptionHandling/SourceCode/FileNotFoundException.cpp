#include "FileNotFoundException.h"

FileNotFoundException::FileNotFoundException(std::string filePath): filePath(filePath) {};

const char* FileNotFoundException::what() const throw()
{
    std::string tmp;
    tmp += "Cannot find file with path: " + filePath + "\n";
    return tmp.c_str();
}