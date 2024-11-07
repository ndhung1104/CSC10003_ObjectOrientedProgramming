#pragma once
#include "Employee.h"

class ManufacturingEmployee : Employee
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
    using Employee::getFullname;
};

