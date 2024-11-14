#include "ManagerEmployee.h"

ManagerEmployee::ManagerEmployee() : Employee::Employee(), titleCoefficient(0), bonus(0) {}

ManagerEmployee::ManagerEmployee(const std::string& fullname, int startYear, double basicSalary, double titleCoefficient, double bonus) : Employee::Employee(fullname, startYear, basicSalary), titleCoefficient(titleCoefficient), bonus(bonus) {}

ManagerEmployee::ManagerEmployee(const std::string& fullname, int startYear, double basicSalary, double titleCoefficient) : Employee::Employee(fullname, startYear, basicSalary), titleCoefficient(titleCoefficient), bonus(0) {}

ManagerEmployee::ManagerEmployee(const std::string& fullname, int startYear, double basicSalary) : Employee::Employee(fullname, startYear, basicSalary), titleCoefficient(0), bonus(0) {}

ManagerEmployee::ManagerEmployee(const ManagerEmployee& emp) : Employee(emp), titleCoefficient(emp.titleCoefficient), bonus(emp.bonus) {}

void ManagerEmployee::printOut()
{
    Employee::printOut();
    std::cout << titleCoefficient << " " << bonus;
}

double ManagerEmployee::calculateSalary()
{
    double salary = Employee::calculateSalary() * titleCoefficient + bonus;
    return salary;
}

void ManagerEmployee::getEmployeeInfo()
{
    Employee::getEmployeeInfo();
    std::cout << "\nInput titleCoefficient: \n";
    std::string tmp;
    getline(std::cin, tmp);
    titleCoefficient = stod(tmp);
    std::cout << "\nInput bonus: \n";
    getline(std::cin, tmp);
    bonus = stod(tmp);
}

int ManagerEmployee::getEmployeeType()
{
    return 1;
}