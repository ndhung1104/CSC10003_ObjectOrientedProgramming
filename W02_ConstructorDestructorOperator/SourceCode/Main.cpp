#include "Stack.h"
#include "Queue.h"
#include "Student.h"
#include "Fraction.h"
#include <iostream>


int main()
{
    std::cout << "Bai 1 \n";
    Fraction f1, f2; // 0/1
    Fraction f3(1, -7); // -1/7
    Fraction f4(f3); // Copy constructor
    Fraction f5 = f2; // Copy constructor
    Fraction f6, f7, f8; // Default constructor
    f6 = f3; // Operator =
    f7 = f1 + f5;
    f8 = f2 - f4;
    f3 = f1 * f7;
    f5 = f6 / f2; // Cannot divide by zero!
    if (f2 == f3)
        std::cout << "f2==f3" << std::endl;
    if (f3 != f1)
        std::cout << "f3!=f1" << std::endl;
    if (f2 >= f5)
        std::cout << "f2>=f5" << std::endl;
    if (f2 > f5)
        std::cout << "f2>f5" << std::endl;
    if (f5 <= f3)
        std::cout << "f5<=f3" << std::endl;
    if (f5 < f3)
        std::cout << "f5<f3" << std::endl;
    f1 = f2 + 3;
    f3 = -7 + f1;
    f5 = 7 * f3;
    f6 = f4 - 6;
    std::cout << f3 << std::endl;
    std::cout << f6 << std::endl;
    f1 += f5;
    f6 -= f7;
    f8 *= f1;
    f8 /= f2; // Cannot divide by zero!
    std::cout << f8++ << std::endl;
    std::cout << ++f7 << std::endl;
    std::cout << f8-- << std::endl;
    std::cout << --f7 << std::endl;
    f3 += Fraction(11, 2);
    int x = int(f3); // 3/2 => 1
    float f = (float)f3; // 3/2 => 1.5
    std::cout << x << std::endl;
    std::cout << f << std::endl;
    std::cout << "\n";


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
    std::cout << "Initialize student 1 and input data: \n";
    Student st;
    std::cin >> st;
    std::cout << "\nPrint out student 1 infos: \n";
    std::cout << st;
    std::cout << "\nInitialize student 2 and 3 using 2 copy contructors Student s2(s1) and Student s3 = s1 \n";
    
    Student st2(st), st3;
    st3 = st;
    std::cout << "Print out student 2 and 3 infos: \n";
    std::cout << st2;
    std::cout << st3 << "\n";

    std::cout << "Completed...";
    std::cin.ignore();
    
    std::cout << "Press any key to exit...";

    std::cin.get();

    return 0;
}