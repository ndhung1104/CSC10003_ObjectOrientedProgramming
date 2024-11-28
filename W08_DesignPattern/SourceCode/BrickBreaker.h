#include <iostream>
#include <vector>

class Bar
{

};

class Ball
{
private:
    static Ball* instance;
    Ball();
    Ball(const Ball&) = delete;
    Ball& operator=(const Ball&) = delete;
public:
    static Ball* getInstance();
    static void deleteInstance();
    void printAddress();
};

class Brick
{

};

class Game
{
private:
    std::vector<Brick*> bricks;
    Bar* bar;
    Ball* ball;
};