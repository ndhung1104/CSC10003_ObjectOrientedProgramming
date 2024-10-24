#include "Student.h"
#include <string>
#include <cstring>

Student::Student() : studentId(new char[8]), fullname(new char[8]), address(new char[8]), gpa(-1)
{
    std::string a = "Unkwown";
    strcpy(studentId, a.c_str());
    strcpy(fullname, a.c_str());
    strcpy(address, a.c_str());
}

Student::Student(char* studentId, double gpa, char* fullname, char* address)
{
    this->studentId = new char[strlen(studentId) + 1];
    this->fullname = new char[strlen(fullname) + 1];
    this->address = new char[strlen(address) + 1];
    strcpy(this->studentId, studentId);
    strcpy(this->fullname, fullname);
    strcpy(this->address, address);
    this->gpa = gpa;
}

Student::~Student()
{
    delete [] studentId;
    delete [] fullname;
    delete [] address;
    studentId = nullptr;
    fullname = nullptr;
    address = nullptr;
}

Student::Student(const Student& s)
{
    
    this->studentId = new char[strlen(s.studentId) + 1];
    this->fullname = new char[strlen(s.fullname) + 1];
    this->address = new char[strlen(s.address) + 1];
    strcpy(this->studentId, s.studentId);
    strcpy(this->fullname, s.fullname);
    strcpy(this->address, s.address);
    this->gpa = s.gpa;
}

Student& Student::operator=(const Student& s)
{
    if (this == &s)
        return *this;

    if (studentId)
        delete [] studentId;
    if (fullname)
        delete [] fullname;
    if (address)
        delete [] address;
    this->studentId = new char[strlen(s.studentId) + 1];
    this->fullname = new char[strlen(s.fullname) + 1];
    this->address = new char[strlen(s.address) + 1];
    
    this->studentId = s.studentId;
    this->fullname = s.fullname;
    this->address = s.address;
    this->gpa = s.gpa;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << "Student ID: " << s.studentId << " - Full name: " << s.fullname << " - Address: " << s.address << " - GPA: " << s.gpa << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Student& s)
{
    std::string tmp;

    std::cout << "Input Student ID: ";
    std::getline(is, tmp);
    if (s.studentId)
        delete [] s.studentId;
    s.studentId = new char[tmp.size() + 1];
    strcpy(s.studentId, tmp.c_str());
    tmp = "";

    std::cout << "Input Full name: ";
    std::getline(is, tmp);
    if (s.fullname)
        delete [] s.fullname;
    s.fullname = new char[tmp.size() + 1];
    strcpy(s.fullname, tmp.c_str());
    tmp = "";

    std::cout << "Input Address: ";
    std::getline(is, tmp);
    if (s.address)
        delete [] s.address;
    s.address = new char[tmp.size() + 1];
    strcpy(s.address, tmp.c_str());
    tmp = "";

    std::cout << "Input GPA: ";
    is >> s.gpa;

    return is;
}