#include "ManufacturingEmployee.h"

ManufacturingEmployee::ManufacturingEmployee() : Employee::Employee(), numberOfProducts(0){}

ManufacturingEmployee::ManufacturingEmployee(const std::string& fullname, int startYear, double basicSalary, double numberOfProducts) : Employee::Employee(fullname, startYear, basicSalary), numberOfProducts(numberOfProducts){}

ManufacturingEmployee::ManufacturingEmployee(const std::string& fullname, int startYear, double basicSalary) : Employee::Employee(fullname, startYear, basicSalary), numberOfProducts(numberOfProducts){}

ManufacturingEmployee::ManufacturingEmployee(const std::string& fullname, int startYear) : Employee::Employee(fullname, startYear), numberOfProducts(0){}

ManufacturingEmployee::ManufacturingEmployee(const ManufacturingEmployee& emp) : Employee(emp), numberOfProducts(emp.numberOfProducts) {}

void ManufacturingEmployee::printOut()
{
    Employee::printOut();
    std::cout << numberOfProducts;
}

double ManufacturingEmployee::calculateSalary()
{
    double salary = Employee::calculateSalary() + numberOfProducts * 2000;
    return salary;
}

void ManufacturingEmployee::getEmployeeInfo()
{
    Employee::getEmployeeInfo();
    std::cout << "\nInput number of products: \n";
    std::string tmp;
    getline(std::cin, tmp);
    numberOfProducts = stod(tmp);
}