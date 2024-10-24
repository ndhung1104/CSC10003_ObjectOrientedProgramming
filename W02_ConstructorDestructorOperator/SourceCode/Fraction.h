class Fraction
{
    int numerator;
    int denominator;
    int gcd(int a, int b);
    void simplify(Fraction& f);
public:
    Fraction();
    Fraction(int num);
    Fraction(int num, int denom);
    Fraction(const Fraction& f);
    Fraction& operator=(const Fraction& f);
    Fraction operator+(const Fraction& f);
    Fraction operator+(int x);
    Fraction operator-(const Fraction& f);
    Fraction operator-(int x);
    Fraction operator*(const Fraction& f);
    Fraction operator*(int x);
    Fraction operator/(const Fraction& f);
    Fraction operator/(int x);
    bool operator==(const Fraction& f);
    bool operator!=(const Fraction& f);
    bool operator>=(const Fraction& f);
    bool operator>(const Fraction& f);
    bool operator<=(const Fraction& f);
    bool operator<(const Fraction& f);
    friend std::ostream& operator<<(std::ostream& os, Fraction f);
    friend std::istream& operator>>(std::istream&, Fraction& f);
    Fraction& operator+=(const Fraction& f);
    Fraction& operator-=(const Fraction& f);
    Fraction& operator*=(const Fraction& f);
    Fraction& operator/=(const Fraction& f);
    Fraction operator++(int x);
    Fraction operator--(int x);
    Fraction& operator++();
    Fraction& operator--();
    operator int() const;
    operator float() const;
};

Fraction operator+(int x, const Fraction& f);
Fraction operator-(int x, const Fraction& f);
Fraction operator*(int x, const Fraction& f);
Fraction operator/(int x, const Fraction& f);
