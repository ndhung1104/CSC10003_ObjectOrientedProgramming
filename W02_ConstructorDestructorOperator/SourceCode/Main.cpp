#include "Stack.h"
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

    std::cin.ignore();
    
    std::cout << "Press any key to exit...";

    std::cin.get();

    return 0;
}