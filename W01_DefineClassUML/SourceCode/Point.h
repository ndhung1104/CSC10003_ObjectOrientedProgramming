#ifndef POINT
#define POINT

class Point
{
    double x;
    double y;

public:
    void input();
    void output();
    double calculateDistance(Point a);
    double calculateSquareDistance(Point a);
};

#endif