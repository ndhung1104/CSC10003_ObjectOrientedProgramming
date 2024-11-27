#include <exception>
#include <string>

class StackException : public std::exception {
private:
    std::string message;

public:
    StackException(const std::string& msg);
    const char* what() const throw();
};

class Stack
{
private:
    int* arr;
    int topIndex;
    int size;

public:
    Stack();
    Stack(int stackSize);
    Stack(const Stack& s);
    Stack& operator=(const Stack& s);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int x);
    void pop();
    int getTopValue();
};