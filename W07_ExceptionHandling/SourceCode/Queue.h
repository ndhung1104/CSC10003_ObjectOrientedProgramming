#include <exception>
#include <string>

class QueueException : public std::exception {
private:
    std::string message;

public:
    QueueException(const std::string& msg);
    const char* what() const throw();
};

class Queue
{
    int* arr;
    int frontIndex, rearIndex;
    int size;

public:
    Queue();
    Queue(int size);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    void dequeue();
    int getFrontValue();
};