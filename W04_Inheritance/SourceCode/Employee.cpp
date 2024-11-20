#include "Employee.h"

Employee::Employee() : fullname("Unknown"), startYear(-1), basicSalary(0){}

Employee::Employee(const std::string& fullname, int startYear, double basicSalary) : fullname(fullname), startYear(startYear), basicSalary(basicSalary) {};

Employee::Employee(const std::string& fullname, int startYear) : fullname(fullname), startYear(startYear), basicSalary(0) {};

Employee::Employee(const std::string& fullname) : fullname(fullname), startYear(-1), basicSalary(0) {};

Employee::Employee(const Employee& emp)
{
    fullname = emp.fullname;
    startYear = emp.startYear;
    basicSalary = emp.basicSalary;
    birthMonth = emp.birthMonth;
    employeeCode = emp.employeeCode;
}

std::string Employee::getFullname()
{
    return this->fullname;
}

std::string Employee::getEmployeeCode()
{
    return this->employeeCode;
}

void Employee::printOut()
{
    std::cout << fullname << " " << startYear << " " << basicSalary << " " << employeeCode << " " << birthMonth << " ";
}

double Employee::calculateSalary()
{
    return basicSalary;
}

void Employee::getEmployeeInfo()
{
    std::string tmp;
    std::cout << "\nInput full name: \n";
    getline(std::cin, fullname);
    std::cout << "\nInput start year: \n";
    std::cin >> startYear;
    std::cin.ignore();
    std::cout << "\nInput basic salary: \n";
    getline(std::cin, tmp);
    basicSalary = std::stod(tmp);
    std::cout << "\nInput employee code: \n";
    getline(std::cin, tmp);
    employeeCode = std::stod(tmp);
    std::cout << "\nInput birth month: \n";
    std::cin >> birthMonth;
    std::cin.ignore();
}