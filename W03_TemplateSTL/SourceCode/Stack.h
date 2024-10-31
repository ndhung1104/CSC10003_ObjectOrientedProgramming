#include <iostream>
#include <stdexcept>

template <class T>
class Stack {
private:
    T* data;
    int topIndex;
    int capacity;

public:
    Stack();                
    Stack(int n);           
    ~Stack();               
    void clear();           
    bool isFull();          
    bool isEmpty();         
    void push(const T& item);  
    T pop();                
    T getTop();             
};

template <class T>
Stack<T>::Stack() : data(nullptr), topIndex(-1), capacity(10) {
    data = new T[capacity];
}

template <class T>
Stack<T>::Stack(int n) : topIndex(-1), capacity(n) {
    data = new T[capacity];
}

template <class T>
Stack<T>::~Stack() {
    delete[] data;
}

template <class T>
void Stack<T>::clear() {
    topIndex = -1;
}

template <class T>
bool Stack<T>::isFull() {
    return topIndex == capacity - 1;
}

template <class T>
bool Stack<T>::isEmpty() {
    return topIndex == -1;
}

template <class T>
void Stack<T>::push(const T& item) {
    if (isFull()) {
        throw std::overflow_error("Stack is full");
    }
    data[++topIndex] = item;
}

template <class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return data[topIndex--];
}

template <class T>
T Stack<T>::getTop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return data[topIndex];
}
