#include "Fraction.h"

const char* DividedByZeroException::what() const throw()
{   
    return "Exception: Cannot divide by zero!\n";
}

void Fraction::setValue(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw DividedByZeroException();
    }
    this->numerator = numerator;
    this->denominator = denominator;
}