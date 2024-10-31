#pragma once
#include <string>
#include <iostream>

class Student
{
private:
    std::string studentID;
    double grade;
    std::string fullname;

public:
    Student();
    Student(std::string studentID, double grade, std::string fullname);
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& is, Student& s);
    std::string getStudentID();
    double getGrade();
    std::string getFullname();
    void setStudentID(std::string studentID);
    void setGrade(double grade);
    void setFullname(std::string fullname);
};