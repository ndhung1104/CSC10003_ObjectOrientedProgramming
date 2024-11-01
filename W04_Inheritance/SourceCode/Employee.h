#pragma once
#include <string>
#include <iostream>

class Employee
{
private:
    std::string fullname;
    int startYear;
    double basicSalary;
public:
    Employee();
    Employee(const std::string& fullname, int startYear, double basicSalary);
    Employee(const std::string& fullname, int startYear);
    Employee(const std::string& fullname);
    Employee(const Employee& emp);
    void getEmployeeInfo();
    double calculateSalary();
    void printOut();
};
