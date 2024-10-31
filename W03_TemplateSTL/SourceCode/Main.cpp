#include "Student.h"
#include "Course.h"
#include "Stack.h"
#include "Fraction.h"

int main()
{
    std::cout << "Bai 1\n";
    std::cout << "Initialize int stack with 5 elements:\n";
    Stack<int> intStack(5);
    
    std::cout << "Checking if the stack is empty return: " << intStack.isEmpty() << "\n";
    std::cout << "Checking if the stack is full return: " << intStack.isFull() << "\n\n";

    std::cout << "Pushing 0 to 4 into the stack: \n\n";
    for (int i = 0; i < 5; i++)
    {
        intStack.push(i);
    }
    
    std::cout << "\nPrint the top value of the stack and pop the stack 5 times: \n";   
    
    for (int i = 0; i < 5; i++)
    {
        int tmp = intStack.getTop();
        std::cout << tmp << " ";
        intStack.pop();
    }

    intStack.clear();
    std::cout << "Stack cleared.\n";
    std::cout << "Is stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << "\n\n";

    std::cout << "Initialize Fraction stack with 3 elements and push 3 fractions into the stack:\n";
    Stack<Fraction> fractionStack(3);

    Fraction f1(1, 2);  
    Fraction f2(3, 4);  
    Fraction f3(5, 6);  
    
    fractionStack.push(f1);
    fractionStack.push(f2);
    fractionStack.push(f3);
    
    std::cout << "Top fraction after pushing 1/2, 3/4, 5/6: " << fractionStack.getTop() << "\n";

    std::cout << "Popped: " << fractionStack.pop() << "\n";
    std::cout << "Top fraction after popping: " << fractionStack.getTop() << "\n";

    std::cout << "Clear the stack \n";
    fractionStack.clear();
    std::cout << "Fraction stack cleared.\n";
    std::cout << "Is stack empty? " << (fractionStack.isEmpty() ? "Yes" : "No") << "\n";


    std::cout << "Bai 2 \n";
    std::cout << "Initializing 2 students, 1 with default parameter and 1 with full parameter: \n";
    Student s1, s2("123456", 9, "Nguyen Van A");
    std::cout << "S1: " << s1 << "\n" << "S2: " << s2 << "\n";
    std::cout << "Input information for student 1 using istream: \n";
    std::cin >> s1;
    std::cout << "Now the information of student 1 becomes: \n";
    std::cout << s1;
    std::cout << "\nTest the setter function for student 1: \n";
    std::string tmp;
    std::cout << "Enter student ID: ";
    getline(std::cin, tmp);
    s1.setStudentID(tmp);
    std::cout << "Enter grade: ";
    double tmpGrade;
    std::cin >> tmpGrade;
    std::cin.ignore();
    s1.setGrade(tmpGrade);
    std::cout << "Enter fullname: ";
    getline(std::cin, tmp);
    s1.setFullname(tmp);
    std::cout << "Print the information of student 1 using getter function: \n";
    std::cout << "Student ID: " << s1.getStudentID() << " - Grade: " << s1.getGrade() << " - Fullname: " << s1.getFullname();

    std::cout << "Bai 3\n";
    std::cout << "Initialize some more students: \n";

    Student student1("23127001", 9, "Nguyen Van A");
    Student student2("23127002", 8, "Nguyen Van B");
    Student student3("23127003", 7, "Nguyen Van C");
    Student student4("23127004", 4, "Nguyen Van D");

    std::cout << "Create a vector of new students and s1 above and enroll them in a course \n";

    std::vector<Student> students = {student1, student2, student3, student4, s1};
    Course myCourse("CS101", "Intro to Computer Science", students);

    std::cout << "Display initial student list: \n";
    myCourse.printStudentList();

    std::cout << "Sort the student list by name in increasing order: \n";
    myCourse.sortStudentList("NAME", true);
    std::cout << "\nSorted by Name (Increasing):\n";
    myCourse.printStudentList();

    std::cout << "Sort the student list by grade in decreasing order: \n";
    myCourse.sortStudentList("GRADE", false);
    std::cout << "\nSorted by Grade (Decreasing):\n";
    myCourse.printStudentList();

    std::cout << "Save the course to a file: \n";
    std::string filePath = "course.txt";
    myCourse.saveCourse(filePath);

    std::cout << "\nCourse saved to " << filePath << "\n";

    std::cout << "Create a new course object and load the data from the file \n";
    Course loadedCourse;
    loadedCourse.readCourse(filePath);
    std::cout << "\nLoaded Course Data:\n";
    myCourse.printStudentList();

    std::cin.ignore();
    
    std::cout << "Press any key to exit...";

    std::cin.get();
    return 0;
}