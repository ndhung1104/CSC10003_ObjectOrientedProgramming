#include "StringToInteger.h"

IntegerFormatException::IntegerFormatException(char errorChar, int index) : errorChar(errorChar), index(index) {};

const char* IntegerFormatException::what() const throw()
{
    std::stringstream stream;
    stream << "Exception: Invalid character\n";
    stream << "Detail: character = " << errorChar << ", index = " << index << "\n";

    return stream.str().c_str();
}

int stringToInt(const std::string& str)
{
    int ans = 0, start = 0; 
    int sign = 1;
    if (str[0] == '-')
    {
        sign = -1;
        start = 1;
    }
    else if (str[0] == '+')
        start = 1;

    for (int i = start; i < str.size(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            throw IntegerFormatException(str[i], i);
        ans = ans * 10 + str[i] - '0';
    }

    return ans;

}