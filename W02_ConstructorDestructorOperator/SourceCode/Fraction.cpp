#include <iostream>
#include "Fraction.h"

using namespace std;

int Fraction::gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

void Fraction::simplify(Fraction& f)
{
    int g = gcd(abs(f.numerator), abs(f.denominator));
    int sign = (double(f.numerator) / double(f.denominator) >= 0) ? 1 : -1;

    f.numerator = abs(f.numerator) / g * sign;
    f.denominator = abs(f.denominator) / g;
}

Fraction::Fraction() : numerator(0), denominator(1) {};
Fraction::Fraction(int num) : numerator(num), denominator(1) {};
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) 
{
    simplify(*this);
}
Fraction::Fraction(const Fraction& f) : numerator(f.numerator), denominator(f.denominator) {};
Fraction& Fraction::operator=(const Fraction& f)
{
    if (this == &f)
        return *this;

    numerator = f.numerator;
    denominator = f.denominator;

    return *this;
}
Fraction Fraction::operator+(const Fraction& f)
{
    Fraction tmp(this->numerator * f.denominator + this->denominator * f.numerator, this->denominator * f.denominator);
    simplify(tmp);
    return tmp;
}
Fraction Fraction::operator+(int x)
{
    Fraction d(*this);
    d.numerator += x * d.denominator;
    simplify(d);
    return d;
}
Fraction operator+(int x, const Fraction& f)
{
    Fraction d(x);
    d = d + f;
    return d;
}
Fraction Fraction::operator-(const Fraction& f)
{
    Fraction tmp(this->numerator * f.denominator - this->denominator * f.numerator, this->denominator * f.denominator);
    simplify(tmp);
    return tmp;
}
Fraction Fraction::operator-(int x)
{
    Fraction d(*this);
    d.numerator -= x * d.denominator;
    simplify(d);
    return d;
}
Fraction operator-(int x, const Fraction& f)
{
    Fraction d(x);
    d = d - f;
    return d;
}
Fraction Fraction::operator*(const Fraction& f)
{
    Fraction tmp(this->numerator * f.numerator, this->denominator * f.denominator);
    simplify(tmp);
    return tmp;
}
Fraction Fraction::operator*(int x)
{
    Fraction d(*this);
    d.numerator *= x;
    simplify(d);
    return d;
}
Fraction operator*(int x, const Fraction& f)
{
    Fraction d(x);
    d = d * f;
    return d;
}
Fraction Fraction::operator/(const Fraction& f)
{
    Fraction tmp(this->numerator, this->denominator);
    if (f.numerator == 0)
    {
        std::cout << "Cannot divide by zero!\n";
    }
    else
    {
        tmp.numerator = tmp.numerator * f.denominator;
        tmp.denominator = tmp.denominator * f.numerator;
    }
    simplify(tmp);
    return tmp;
}
Fraction Fraction::operator/(int x)
{
    Fraction d(*this);
    if (x == 0)
        std::cout << "Cannot divide by zero!\n";
    else
        d.numerator /= x;
    simplify(d);
    return d;
}
Fraction operator/(int x, const Fraction& f)
{
    Fraction d(x);
    d = d / f;
    return d;
}
bool Fraction::operator==(const Fraction& f)
{
    if (this->numerator == f.numerator && this->denominator == f.denominator)
        return true;
    
    return false;
}
bool Fraction::operator!=(const Fraction& f)
{
    return !(*this == f);
}
bool Fraction::operator>=(const Fraction& f)
{
    double f1 = this->numerator * 1.0 / this->denominator;
    double f2 = f.numerator * 1.0 / f.denominator;

    return f1 >= f2;
}
bool Fraction::operator>(const Fraction& f)
{
    double f1 = this->numerator * 1.0 / this->denominator;
    double f2 = f.numerator * 1.0 / f.denominator;

    return f1 > f2;
}
bool Fraction::operator<=(const Fraction& f)
{
    double f1 = this->numerator * 1.0 / this->denominator;
    double f2 = f.numerator * 1.0 / f.denominator;

    return f1 <= f2;
}
bool Fraction::operator<(const Fraction& f)
{
    double f1 = this->numerator * 1.0 / this->denominator;
    double f2 = f.numerator * 1.0 / f.denominator;

    return f1 < f2;
}

std::ostream& operator<<(std::ostream& os, Fraction f)
{
    os << f.numerator;
    if (f.denominator != 1) 
        os << "/" << f.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f)
{
    std::cout << "Input numerator: ";
    is >> f.numerator;
    std::cout << "Input denomerator: ";
    is >> f.denominator;
    return is;
}

Fraction& Fraction::operator+=(const Fraction& f)
{
    this->numerator = this->numerator * f.denominator + f.numerator * this->denominator;
    this->denominator = this->denominator * f.denominator;
    simplify(*this);

    return *this;
}
Fraction& Fraction::operator-=(const Fraction& f)
{
    this->numerator = this->numerator * f.denominator - f.numerator * this->denominator;
    this->denominator = this->denominator * f.denominator;
    simplify(*this);

    return *this;
}
Fraction& Fraction::operator*=(const Fraction& f)
{
    this->numerator = this->numerator * f.numerator;
    this->denominator = this->denominator * f.denominator;
    simplify(*this);

    return *this;
}
Fraction& Fraction::operator/=(const Fraction& f)
{
    if (f.numerator == 0)
    {
        std::cout << "Cannot divide by zero!\n";
    }
    else
    {
        this->numerator = this->numerator * f.denominator;
        this->denominator = this->denominator * f.numerator;
        simplify(*this);
    }
    
    return *this;
}

Fraction Fraction::operator++(int x)
{
    Fraction tmp(*this);
    this->numerator += this->denominator;
    simplify(*this);

    return tmp;
}
Fraction Fraction::operator--(int x)
{
    Fraction tmp(*this);
    this->numerator -= this->denominator;
    simplify(*this);
    
    return tmp;
}
Fraction& Fraction::operator++()
{
    this->numerator += this->denominator;
    simplify(*this);
    
    return *this;
}
Fraction& Fraction::operator--()
{
    this->numerator -= this->denominator;
    simplify(*this);
    
    return *this;
}
Fraction::operator int() const
{
    return this->numerator / this->denominator;
}
Fraction::operator float() const
{
    float d = this->numerator;
    d = d / (this->denominator * 1.0);
    return d;
}