#include <iostream>

class Student
{
private:
    char* studentId;
    double gpa;
    char* fullname;
    char* address;

public:
    Student();
    Student(char* studentId, double gpa, char* fullname, char* address);
    ~Student();
    Student(const Student& s);
    Student& operator=(const Student& s);
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& os, Student& s);
};