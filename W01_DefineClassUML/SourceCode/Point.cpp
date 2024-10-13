#include <iostream>
#include <cmath>
#include "Point.h"

void Point::input()
{
    std::cout << "Input x coordinate: ";
    std::cin >> x;

    std::cout << "Input y coordinate: ";
    std::cin >> y;
}

void Point::output()
{
    std::cout << "The coordinate of this point is: (" << x << "," << y << ")" << "\n";
}

double Point::calculateDistance(Point a)
{
    double distance = sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));

    return distance;
}