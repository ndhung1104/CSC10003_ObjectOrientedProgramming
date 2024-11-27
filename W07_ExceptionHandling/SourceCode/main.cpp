#include "Fraction.h"
#include "Array.h"
#include "StringToInteger.h"
#include <fstream>
#include "FileNotFoundException.h"
#include "Date.h"
#include "Time.h"
#include "Stack.h"
#include "Queue.h"
int main()
{
    std::cout << "Bai 1......... \n" << "Try to set a fraction denominator to 0: \n";
    Fraction f;
    try 
    {
        f.setValue(1, 0);
    }
    catch (DividedByZeroException& ex)
    {
        std::cout << ex.what() << "\n";
    }
    std::cout << "Bai 2......... \n" << "Try to access the element with index number 7 in an array that has a capacity of 4: \n";
    Array a(4);
    try
    {
        int tmp = a.getValueAt(7);
        std::cout << tmp << "\n";
    }
    catch(IndexOutOfRangeException& ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::ifstream ifs;
    std::string filePath("notFound.txt");
    std::cout << "Bai 3......... \n" << "Try to open file notFound.txt in current folder: \n";
    try
    {
        ifs.open(filePath);
        if (!ifs.is_open())
            throw FileNotFoundException(filePath);
    }
    catch(FileNotFoundException& e)
    {
        std::cout << e.what() << '\n';
    }
    

    std::cout << "Bai 4......... \n" << "Try to convert string one-two-three to integer: \n";
    try 
    {
        stringToInt("one-two-three");
    }
    catch(IntegerFormatException& ex)
    {
        std::cout << ex.what() << "\n";
    }

    std::cout << "Bai 5......... \n" << "Try to initialize a date object with dd/mm/yy = 31/1/1990: \n";
    try 
    {
        Date d(32, 1, 1990);
    }
    catch(DateFormatException& ex)
    {
        std::cout << ex.what() << "\n";
    }

    std::cout << "Bai 5......... \n" << "Try to initialize a time object with h/m/s = 24/96/20: \n";
    try 
    {
        Time t(24, 96, 20);
    }
    catch(TimeFormatException& ex)
    {
        std::cout << ex.what() << "\n";
    }
    std::cout << "Bai 6......... \n";
    try {
        std::cout << "Try to push 4 elements into a stack(3): ";
        Stack s(3);

        s.push(10);
        s.push(20);
        s.push(30);

        s.push(40); 
    } 
    catch (const StackException& e) 
    {
        std::cerr << e.what() << "\n";
    }

    try 
    {
        std::cout << "Try to pop from an empty stack: ";
        Stack s(3);

        s.pop(); 
    } 
    catch (const StackException& e) 
    {
        std::cerr << e.what() << "\n";
    }

    try {
        std::cout << "Try to get top value from an empty stack: ";
        Stack s(3);

        int topValue = s.getTopValue(); 
        std::cout << "Top value: " << topValue << "\n";
    } 
    catch (const StackException& e) 
    {
        std::cerr << e.what() << "\n";
    }

    try {
        std::cout << "Try to enqueue 4 elements into a queue(3): ";
        Queue q(3);

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        q.enqueue(40); 
    } 
    catch (const QueueException& e) 
    {
        std::cerr << e.what() << "\n";
    }

    try 
    {
        std::cout << "Try to dequeue from an empty stack: ";
        Queue q(3);

        q.dequeue(); 
    } 
    catch (const QueueException& e) 
    {
        std::cerr << e.what() << "\n";
    }

    try {
        std::cout << "Try to get front value from an empty queue: ";
        Queue q(3);

        int topValue = q.getFrontValue(); 
        std::cout << "Top value: " << topValue << "\n";
    } 
    catch (const QueueException& e) 
    {
        std::cerr << e.what() << "\n";
    }

    return 0;
}