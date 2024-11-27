#include "Stack.h"
#include <iostream>

StackException::StackException(const std::string& msg) : message(msg) {};
const char* StackException::what() const throw()
{
    return message.c_str();
}

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
    // std::cout << "Stack deleted \n";
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
void Stack::push(int x)
{
    if (this->isFull())
        throw StackException("Push failed: Stack is full.");
    
    this->topIndex++;
    this->arr[this->topIndex] = x;
}
void Stack::pop()
{
    if (this->isEmpty())
        throw StackException("Pop failed: Stack is empty.");

    this->topIndex--;
}
int Stack::getTopValue()
{
    if (this->isEmpty())
        throw StackException("GetTopValue failed: Stack is empty.");
    
    return this->arr[this->topIndex];
}