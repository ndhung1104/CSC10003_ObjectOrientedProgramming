#include "Array.h"

IndexOutOfRangeException::IndexOutOfRangeException(int index, int capacity)
{
    this->index = index;
    this->capacity = capacity;
}

const char* IndexOutOfRangeException::what() const throw()
{
    std::stringstream stream;
    stream << "Exception: Index out of range\n";
    stream << "Detail: index = " << index << ", capacity = " << capacity << "\n";

    return _strdup(stream.str().c_str());
}

Array::Array()  : capacity(0), a(nullptr) {};
Array::Array(int size) : capacity(size), a(new int[size]{0}) {};
Array::~Array()
{
    if (a)
        delete [] a; 
}
int Array::getValueAt(int index)
{
    if (index < 0 || index >= capacity)
        throw IndexOutOfRangeException(index, capacity);
    
    return a[index];
}