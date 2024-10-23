#include "Stack.h"
#include "Queue.h"
#include "Student.h"
#include <iostream>


int main()
{
    std::cout << "Bai 2 \n";

    std::cout << "Initialize the stack with 5 elements: \n";
    Stack s(5);
    std::cout << "Checking if the stack is empty return: " << s.isEmpty() << "\n";
    std::cout << "Checking if the stack is full return: " << s.isFull() << "\n\n";

    std::cout << "Pushing 0 to 4 into the stack: \n\n";
    for (int i = 0; i < 5; i++)
    {
        if (s.push(i))
            std::cout << "Pushing " << i << " into the stack! \n";
        else
            std::cout << "Failed to push " << i << " into the stack! \n";
    }
    
    std::cout << "\nPrint the top value of the stack and pop the stack 5 times: \n";   
    
    for (int i = 0; i < 10; i++)
    {
        int tmp;
        if (s.getTopValue(tmp))
            std::cout << tmp << " ";
        s.pop();
    }

    std::cout << "Bai 3 \n";

    std::cout << "Initialize the queue with 5 elements: \n";
    Queue q(5);
    std::cout << "Checking if the queue is empty return: " << q.isEmpty() << "\n";
    std::cout << "Checking if the queue is full return: " << q.isFull() << "\n\n";

    std::cout << "Pushing 0 to 4 into the queue: \n\n";
    for (int i = 0; i < 5; i++)
    {
        if (q.enqueue(i))
            std::cout << "Pushing " << i << " into the queue! \n";
        else
            std::cout << "Failed to push " << i << " into the queue! \n";
    }
    
    std::cout << "\nPrint the top value of the queue and dequeue 5 times: \n";   
    
    for (int i = 0; i < 10; i++)
    {
        int tmp;
        if (q.getFrontValue(tmp))
            std::cout << tmp << " ";
        q.dequeue();
    }

    std::cout << "Bai 4 \n";
    Student st, st1;
    std::cin >> st;
    std::cout << st;
    st1 = st;
    std::cout << st1;

    std::cin.ignore();
    
    std::cout << "Press any key to exit...";

    std::cin.get();

    return 0;
}