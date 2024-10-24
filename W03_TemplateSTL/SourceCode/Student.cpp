#include "Student.h"


Student::Student() : studentID("Unkwown"), grade(-1), fullname("Unknown") {};
Student::Student(std::string id, double g, std::string fname) : studentID(id), grade(g), fullname(fname) {};
std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << "Student ID: " << s.studentID << ", Grade: " << s.grade << ", Fullname: " << s.fullname;
    return os;
}
std::istream& operator>>(std::istream& is, Student& s)
{
    std::cout << "Enter student ID: ";
    getline(is, s.studentID);
    std::cout << "Enter grade: ";
    is >> s.grade;
    is.ignore();
    std::cout << "Enter fullname: ";
    getline(is, s.fullname);

    return is;
}
std::string Student::getStudentID()
{
    return this->studentID;
}
double Student::getGrade()
{
    return this->grade;
}
std::string Student::getFullname()
{
    return this->fullname;
}
void Student::setStudentID(std::string studentID)
{
    this->studentID = studentID;
}
void Student::setGrade(double grade)
{
    this->grade = grade;
}
void Student::setFullname(std::string fullname)
{
    this->fullname = fullname;
}