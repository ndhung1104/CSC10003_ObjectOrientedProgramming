#pragma once
#include "Employee.h"

class ManufacturingEmployee : public Employee
{
private:
    double numberOfProducts;
public:
    ManufacturingEmployee();
    ManufacturingEmployee(const std::string& fullname, int startYear, double basicSalary, double numberOfProducts);
    ManufacturingEmployee(const std::string& fullname, int startYear, double basicSalary);
    ManufacturingEmployee(const std::string& fullname, int startYear);
    ManufacturingEmployee(const ManufacturingEmployee& emp);
    void getEmployeeInfo();
    double calculateSalary();
    void printOut();
    int getEmployeeType();
    using Employee::getFullname;
};

