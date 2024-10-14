#include "Point.h"

class Rectangle
{
    Point p[4];

public:
    void inputRectangle();
    bool isRectangle();
    double calPerimeter();
    double calArea();
};