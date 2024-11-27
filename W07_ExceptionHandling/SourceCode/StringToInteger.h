#include <iostream>
#include <exception>
#include <sstream>
#include <cstring>

class IntegerFormatException : public std::exception
{
private:
    int index;
    char errorChar;
public:
    IntegerFormatException(char errorChar, int index);
    const char* what() const throw();
};

int stringToInt(const std::string& str);