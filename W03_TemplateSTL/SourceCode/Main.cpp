#include "Student.h"

int main()
{
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

    return 0;
}