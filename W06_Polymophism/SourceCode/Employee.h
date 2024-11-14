#pragma once
#include <string>
#include <iostream>

class Employee
{
private:
    std::string fullname;
    int startYear;
    double basicSalary;
    std::string employeeCode;
    int birthMonth;
public:
    Employee();
    Employee(const std::string& fullname, int startYear, double basicSalary);
    Employee(const std::string& fullname, int startYear);
    Employee(const std::string& fullname);
    Employee(const Employee& emp);
    virtual void getEmployeeInfo();
    virtual double calculateSalary();
    virtual void printOut();
    std::string getFullname();
    virtual int getEmployeeType() = 0;
};
