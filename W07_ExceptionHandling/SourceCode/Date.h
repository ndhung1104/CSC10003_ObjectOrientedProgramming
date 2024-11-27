#include <iostream>
#include <exception>
#include <string>

class DateFormatException : public std::exception
{
private:
    int value;
    std::string reason;
public:
    DateFormatException(int value, const std::string& reason);
    const char* what() const throw();
};

class Date
{
private:
    int dd, mm, yy;
    bool isLeapYear(int year);

public:
    Date(int dd, int mm, int yy);
};