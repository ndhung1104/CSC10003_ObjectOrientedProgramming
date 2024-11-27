#include <iostream>
#include <exception>
#include <string>

class DividedByZeroException : public std::exception
{
public:
    const char* what() const throw();
    
};

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    void setValue(int numerator, int denominator);
};
