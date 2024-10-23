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
    bool enqueue(int x);
    bool dequeue();
    bool getFrontValue(int& value);
};