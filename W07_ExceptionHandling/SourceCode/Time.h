#include <iostream>
#include <exception>
#include <string>

class TimeFormatException : public std::exception
{
private:
    int value;
    std::string reason;
public:
    TimeFormatException(int value, const std::string& reason);
    const char* what() const throw();
};

class Time
{
private:
    int h, m, s;

public:
    Time(int h, int m, int s);
};