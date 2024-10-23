#include "Queue.h"
#include <iostream>

Queue::Queue() : arr(nullptr), frontIndex(0), rearIndex(-1), size(0) {};
Queue::Queue(int sz) : arr(new int[sz]), frontIndex(0), rearIndex(-1), size(sz) {};
Queue::~Queue()
{
    if (arr)
    {
        delete [] arr;
        arr = nullptr;
        size = 0;
        frontIndex = 0;
        rearIndex = -1;
    }
    std::cout << "Queue deleted!\n";
}
bool Queue::isEmpty()
{
    if (rearIndex == -1)
        return true;
    
    return false;
}
bool Queue::isFull()
{
    if (rearIndex == size - 1)
        return true;
    
    return false;
}
bool Queue::enqueue(int x)
{
    if (isFull())
        return false;

    rearIndex++;
    arr[rearIndex] = x;
    return true;
}
bool Queue::dequeue()
{
    if (isEmpty())
        return false;
    for (int i = frontIndex; i < rearIndex; i++)
        arr[i] = arr[i + 1];
    
    rearIndex--;

    return true;
}
bool Queue::getFrontValue(int& value)
{
    if (isEmpty())
        return false;
    
    value = arr[frontIndex];

    return true;
}