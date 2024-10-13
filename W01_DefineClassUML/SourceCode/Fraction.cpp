#include <iostream>
#include "Fraction.h"

using namespace std;

void Fraction::setValue()
{
    int num, denom;
    cout << "Enter numerator: ";
    cin >> num;

    cout << "Enter denomerator: ";
    cin >> denom;

    this->numerator = num;
    this->denominator = denom;
}

void Fraction::printOnScreen()
{
    cout << this->numerator << "/" << this->denominator << endl;
    double num = this->numerator, denom = this->denominator, value = num / denom;
    cout << value << endl;
}

Fraction Fraction::addFraction(Fraction a)
{
    Fraction c;
    c.numerator = a.numerator * this->denominator + this->numerator * a.denominator;
    c.denominator = a.denominator * this->denominator;

    return c;
}

Fraction Fraction::subtractFraction(Fraction a)
{
    Fraction c;
    c.numerator = this->numerator * a.denominator - a.numerator * this->denominator;
    c.denominator = a.denominator * this->denominator;

    return c;
}

Fraction Fraction::multiplyFraction(Fraction a)
{
    Fraction c;
    c.numerator = this->numerator * a.numerator;
    c.denominator = this->denominator * a.denominator;

    return c;
}

Fraction Fraction::divideFraction(Fraction a)
{
    Fraction c;
    c.numerator = this->numerator * a.denominator;
    c.denominator = this->denominator * a.numerator;

    return c;
}

