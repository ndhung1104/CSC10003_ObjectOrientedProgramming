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
    std::vector<ManagerEmployee> managerList;
    std::vector<ManufacturingEmployee> mnfgList;
    std::vector<OfficeEmployee> officeList;

public:
    Company();
    Company(const std::string companyName);
    Company(const std::string companyName, const std::vector<ManagerEmployee>& managerList, const std::vector<ManufacturingEmployee>& mnfgList, const std::vector<OfficeEmployee>& officeList);
    void inputEmployee();
    void printEmployeeList();
    double calculateTotalSalary();
    bool findEmployee(std::string fullname);
    void addEmployee(const ManagerEmployee& employee);
    void addEmployee(const ManufacturingEmployee& employee);
    void addEmployee(const OfficeEmployee& employee);    
};
