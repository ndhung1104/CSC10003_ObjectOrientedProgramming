#include "Employee.h"

Employee::Employee() : fullname("Unknown"), startYear(-1), basicSalary(0){}

Employee::Employee(const std::string& fullname, int startYear, double basicSalary) : fullname(fullname), startYear(startYear), basicSalary(basicSalary), employeeCode(0), birthMonth(1) {};

Employee::Employee(const std::string& fullname, int startYear) : fullname(fullname), startYear(startYear), basicSalary(0), employeeCode(0), birthMonth(1) {};

Employee::Employee(const std::string& fullname) : fullname(fullname), startYear(-1), basicSalary(0), employeeCode(0), birthMonth(1) {};

Employee::Employee(const Employee& emp)
{
    fullname = emp.fullname;
    startYear = emp.startYear;
    basicSalary = emp.basicSalary;
    employeeCode = emp.employeeCode;
    birthMonth = emp.birthMonth;
}

std::string Employee::getFullname()
{
    return this->fullname;
}

void Employee::printOut()
{
    std::cout << fullname << " " << startYear << " " << basicSalary << " ";
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
    std::cout << "\nInput employee code: \n";
    getline(std::cin, employeeCode);
    std::cout << "\nInput birth month: \n";
    std::cin >> birthMonth;
    std::cin.ignore();
    std::cout << "\nInput basic salary: \n";
    getline(std::cin, tmp);
    basicSalary = std::stod(tmp);
}