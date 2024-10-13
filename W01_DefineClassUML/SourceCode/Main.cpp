#include <iostream>
#include "Fraction.h"
#include "Date.h"

using namespace std;

int main()
{
    // cout << "Bai 1..............." << endl;
    // Fraction a, b, c, d, e, f;
    // cout << "Input first number: " << endl;
    // a.setValue();
    // cout << endl;

    // cout << "Input second number: " << endl;
    // b.setValue();
    // cin.ignore();
    // cout << endl;

    // cout << "a + b = " << endl;
    // c = a.addFraction(b);
    // c.printOnScreen();
    // cout << endl;

    // cout << "a - b = " << endl;
    // d = a.subtractFraction(b);
    // d.printOnScreen();
    // cout << endl;

    // cout << "a * b = " << endl;
    // e = a.multiplyFraction(b);
    // e.printOnScreen();
    // cout << endl;

    // cout << "a / b = " << endl;
    // f = a.divideFraction(b);
    // f.printOnScreen();
    // cout << endl;
    
    cout << "Bai 2..............." << endl;
    Date date1;
    
    cout << "Input date: " << "\n";
    date1.input();
    date1.output();
    cout << "\n";

    cout << "Increase 1 day" << "\n";
    date1.increaseOneDay();
    date1.output();
    cout << "\n";

    cout << "Decrease 1 day" << "\n";
    date1.decreaseOneDay();
    date1.output();
    cout << "\n";

    cout << "Increase n day, please input n: ";
    int n;
    cin >> n;
    date1.increaseNDay(n);
    date1.output();
    cout << "\n";

    cout << "Decrease n day, please input n: ";
    cin >> n;
    date1.decreaseNDay(n);
    date1.output();
    cout << "\n";

    Date date2;
    cout << "Input second date to compare: " << "\n";
    date2.input();
    date2.output();
    cout << "\n";

    cout << "Comparing the first date to the second date will result in: " << date1.compare(date2);
    cout << "\n";

    cout << "Press any key to exit...";

    cin.get();

    return 0;
}
