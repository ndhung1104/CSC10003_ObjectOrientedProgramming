#include <iostream>
#include <cstring>
#include <string>

class Book
{
private:
    char* title;
    char* author;
    int pages;
    double price;
public:
    Book();
    Book(std::string title, std::string author, int pages, double price);
    ~Book();
    void printBook();
};




