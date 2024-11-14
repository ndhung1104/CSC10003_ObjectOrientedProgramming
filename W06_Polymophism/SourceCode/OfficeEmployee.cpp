#include "OfficeEmployee.h"

OfficeEmployee::OfficeEmployee() : Employee::Employee(), numberOfDays(0), allowance(0) {}

OfficeEmployee::OfficeEmployee(const std::string& fullname, int startYear, double basicSalary, double numberOfDays, double allowance) : Employee::Employee(fullname, startYear, basicSalary), numberOfDays(numberOfDays), allowance(allowance) {}

OfficeEmployee::OfficeEmployee(const std::string& fullname, int startYear, double basicSalary, double numberOfDays) : Employee::Employee(fullname, startYear, basicSalary), numberOfDays(numberOfDays), allowance(0) {}

OfficeEmployee::OfficeEmployee(const std::string& fullname, int startYear, double basicSalary) : Employee::Employee(fullname, startYear, basicSalary), numberOfDays(0), allowance(0) {}

OfficeEmployee::OfficeEmployee(const OfficeEmployee& emp) : Employee(emp), numberOfDays(emp.numberOfDays), allowance(emp.allowance) {}

void OfficeEmployee::printOut()
{
    Employee::printOut();
    std::cout << numberOfDays << " " << allowance;
}

double OfficeEmployee::calculateSalary()
{
    double salary = Employee::calculateSalary() + numberOfDays * 100000 + allowance;
    return salary;
}

void OfficeEmployee::getEmployeeInfo()
{
    Employee::getEmployeeInfo();
    std::cout << "\nInput number of numberOfDays: \n";
    std::string tmp;
    getline(std::cin, tmp);
    numberOfDays = stod(tmp);
    std::cout << "\nInput allowance: \n";
    getline(std::cin, tmp);
    allowance = stod(tmp);
}

int OfficeEmployee::getEmployeeType()
{
    return 3;
}