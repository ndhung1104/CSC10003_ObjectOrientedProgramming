#include "Rectangle.h"
#include <iostream>

void Rectangle::inputRectangle()
{
    std::cout << "Input rectangle: \n";
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Input point: " << i << "\n";
        p[i].input();
        std::cout << "\n";
    }
        
}
bool Rectangle::isRectangle()
{
    if (p[0].calculateSquareDistance(p[1]) != p[2].calculateSquareDistance(p[3]) || p[0].calculateSquareDistance(p[3]) != p[1].calculateSquareDistance(p[2]))
        return false;

    
    if (p[0].calculateSquareDistance(p[1]) + p[1].calculateSquareDistance(p[2]) != p[0].calculateSquareDistance(p[2]))
        return false;

    if (p[1].calculateSquareDistance(p[2]) + p[2].calculateSquareDistance(p[3]) != p[1].calculateSquareDistance(p[3]) )
        return false;
    
    return true;
}
double Rectangle::calPerimeter()
{
    if (isRectangle())
        return (p[0].calculateDistance(p[1]) * 2 + p[1].calculateDistance(p[2]) * 2);
    
    return -1;
}
double Rectangle::calArea()
{
    if (isRectangle())
        return (p[0].calculateDistance(p[1]) * p[1].calculateDistance(p[2]));
    
    return -1;
}