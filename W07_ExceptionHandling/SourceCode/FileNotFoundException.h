#include <iostream>
#include <exception>
#include <string>

class FileNotFoundException : public std::exception
{
private:
    std::string filePath;
public:
    FileNotFoundException(std::string filePath);
    const char* what() const throw();
};