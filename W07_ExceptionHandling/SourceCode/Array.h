#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <cstring>

class IndexOutOfRangeException : public std::exception
{
private:
    int index, capacity;

public:
    IndexOutOfRangeException(int index, int capacity);
    const char* what() const throw();
};

class Array
{
private:
    int capacity;
    int* a;

public:
    Array();
    Array(int capacity);
    int getValueAt(int index);
    ~Array();
};