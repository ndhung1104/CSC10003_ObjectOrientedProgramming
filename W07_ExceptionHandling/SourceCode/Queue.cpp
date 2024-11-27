#include "Queue.h"
#include <iostream>

QueueException::QueueException(const std::string& msg) : message(msg) {};
const char* QueueException::what() const throw()
{
    return message.c_str();
}

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
    // std::cout << "Queue deleted!\n";
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
void Queue::enqueue(int x)
{
    if (isFull())
        throw QueueException("Enqueue failed: Queue is full.");

    rearIndex++;
    arr[rearIndex] = x;
}
void Queue::dequeue()
{
    if (isEmpty())
        throw QueueException("Dequeue failed: Queue is empty.");
    for (int i = frontIndex; i < rearIndex; i++)
        arr[i] = arr[i + 1];
    
    rearIndex--;
}
int Queue::getFrontValue()
{
    if (isEmpty())
        throw QueueException("Get front failed: Queue is empty.");
    
    return arr[frontIndex];
}