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
    bool push(int x);
    bool pop();
    bool getTopValue(int &returnValue);
};