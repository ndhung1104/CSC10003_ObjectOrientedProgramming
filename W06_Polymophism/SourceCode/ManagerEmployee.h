#pragma once
#include "Employee.h"

class ManagerEmployee : public Employee
{
private:
    double titleCoefficient;
    double bonus;
public:
    ManagerEmployee();
    ManagerEmployee(const std::string& fullname, int startYear, double basicSalary, double titleCoefficient, double bonus);
    ManagerEmployee(const std::string& fullname, int startYear, double basicSalary, double titleCoefficient);
    ManagerEmployee(const std::string& fullname, int startYear, double basicSalary);
    ManagerEmployee(const ManagerEmployee& emp);
    void getEmployeeInfo();
    double calculateSalary();
    void printOut();
    int getEmployeeType();
    using Employee::getFullname;
};

