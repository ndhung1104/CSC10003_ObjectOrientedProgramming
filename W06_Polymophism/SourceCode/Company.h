#pragma once
#include <string>
#include "OfficeEmployee.h"
#include "ManagerEmployee.h"
#include "ManufacturingEmployee.h"
#include <vector>
#include <iostream>

class Company
{
private:
    std::string companyName;
    // std::vector<ManagerEmployee> managerList;
    // std::vector<ManufacturingEmployee> mnfgList;
    // std::vector<OfficeEmployee> officeList;
    std::vector<Employee*> employeeList;

public:
    Company();
    ~Company();
    Company(const std::string companyName);
    // Company(const std::string companyName, const std::vector<ManagerEmployee>& managerList, const std::vector<ManufacturingEmployee>& mnfgList, const std::vector<OfficeEmployee>& officeList);
    void inputEmployee();
    void printEmployeeList();
    double calculateTotalSalary();
    bool findEmployee(std::string fullname);
    bool findEmployeeCode(std::string employeeCode);
    bool findEmployeeWithBirthMonth(int month);
    void addEmployee(ManagerEmployee& employee);
    void addEmployee(ManufacturingEmployee& employee);
    void addEmployee(OfficeEmployee& employee);    
    void findHighestSalaryEmployee();
    int getNumberOfEmployee(int employeeType); // 1 = Manager, 2 = Manufacturing, 3 = Office
    double calculateAverageSalary();
    void findEmployeeWithSalaryBelow(double salary);
};
