#include "BrickBreaker.h"

Ball::Ball(){};

Ball* Ball::getInstance()
{
    if (instance == nullptr)
        instance = new Ball();
    
    return instance;
}

void Ball::deleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void Ball::printAddress()
{
    std::cout << (void*)instance << "\n";
}