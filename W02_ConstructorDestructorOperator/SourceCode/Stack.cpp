#include "Stack.h"
#include <iostream>

Stack::Stack() : arr(nullptr), topIndex(-1), size(0) {}

Stack::Stack(int stackSize) : arr(new int[stackSize]), topIndex(-1), size(stackSize) {}

Stack::Stack(const Stack& s)
{
    this->size = s.size;
    this->arr = new int[this->size];
    this->topIndex = s.topIndex;

    for (int i = 0; i < this->size; i++)
        this->arr[i] = s.arr[i];
}

Stack& Stack::operator=(const Stack& s)
{
    if (this->arr)
        delete [] this->arr;
    
    this->size = s.size;
    this->arr = new int[this->size];
    this->topIndex = s.topIndex;

    for (int i = 0; i < this->size; i++)
        this->arr[i] = s.arr[i];

    return *this;
}
Stack::~Stack()
{
    if (this->arr)
        delete [] this->arr;
    this->arr = nullptr;
    this->size = 0;
    this->topIndex = -1;
    std::cout << "Stack deleted \n";
}
bool Stack::isEmpty()
{
    if (this->topIndex == -1)
        return true;
    
    return false;
}
bool Stack::isFull()
{
    if (this->topIndex + 1 == this->size)
        return true;
    
    return false;
}
bool Stack::push(int x)
{
    if (this->isFull())
        return false;
    
    this->topIndex++;
    this->arr[this->topIndex] = x;

    return true;
}
bool Stack::pop()
{
    if (this->isEmpty())
        return false;

    this->topIndex--;

    return true;
}
bool Stack::getTopValue(int &returnValue)
{
    if (this->isEmpty())
        return false;
    
    returnValue = this->arr[this->topIndex];
    
    return true;
}