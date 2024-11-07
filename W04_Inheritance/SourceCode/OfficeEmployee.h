#pragma once
#include "Employee.h"

class OfficeEmployee : Employee
{
private:
    double numberOfDays;
    double allowance;
public:
    OfficeEmployee();
    OfficeEmployee(const std::string& fullname, int startYear, double basicSalary, double numberOfDays, double allowance);
    OfficeEmployee(const std::string& fullname, int startYear, double basicSalary, double numberOfDays);
    OfficeEmployee(const std::string& fullname, int startYear, double basicSalary);
    OfficeEmployee(const OfficeEmployee& emp);
    void getEmployeeInfo();
    double calculateSalary();
    void printOut();
    using Employee::getFullname;
};

