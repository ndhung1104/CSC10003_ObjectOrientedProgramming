#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction a, b, c, d, e, f;
    cout << "Input first number: " << endl;
    a.setValue();
    cout << endl;

    cout << "Input second number: " << endl;
    b.setValue();
    cin.ignore();
    cout << endl;

    cout << "a + b = " << endl;
    c = a.addFraction(b);
    c.printOnScreen();
    cout << endl;

    cout << "a - b = " << endl;
    d = a.subtractFraction(b);
    d.printOnScreen();
    cout << endl;

    cout << "a * b = " << endl;
    e = a.multiplyFraction(b);
    e.printOnScreen();
    cout << endl;

    cout << "a / b = " << endl;
    f = a.divideFraction(b);
    f.printOnScreen();
    cout << endl;

    cout << "Press any key to exit...";

    cin.get();

    return 0;
}
