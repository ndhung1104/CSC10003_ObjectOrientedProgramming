#include "Company.h"

Company::Company() : companyName("Unknown"), managerList(std::vector<ManagerEmployee>()), mnfgList(std::vector<ManufacturingEmployee>()), officeList(std::vector<OfficeEmployee>()) {};
Company::Company(const std::string companyName) : companyName(companyName), managerList(std::vector<ManagerEmployee>()), mnfgList(std::vector<ManufacturingEmployee>()), officeList(std::vector<OfficeEmployee>()) {};
Company::Company(const std::string companyName, const std::vector<ManagerEmployee>& managerList, const std::vector<ManufacturingEmployee>& mnfgList, const std::vector<OfficeEmployee>& officeList) : companyName(companyName), managerList(managerList), mnfgList(mnfgList), officeList(officeList) {};
void Company::inputEmployee()
{
    while (true)
    {
        std::cout << "Input employee:\n1.Manager\n2.Manufacturing\n3.Office\nEnter any other key to exit\nYour input: ";
        char tmp;
        std::cin >> tmp;
        if (tmp < '1' || tmp > '3')
            break;
        if (tmp == '1')
        {
            ManagerEmployee employee;
            employee.getEmployeeInfo();
            managerList.push_back(employee);
        }
        else if (tmp == '2')
        {
            ManufacturingEmployee employee;
            employee.getEmployeeInfo();
            mnfgList.push_back(employee);
        }
        else
        {
            OfficeEmployee employee;
            employee.getEmployeeInfo();
            officeList.push_back(employee);
        }
    }
}

void Company::printEmployeeList()
{
    std::cout << "Manager employee list: \n";
    for (int i = 0; i < managerList.size(); i++)
    {
        managerList[i].printOut();
        std::cout << "\n";
    }
        

    std::cout << "\nManufacturing employee list: \n";
    for (int i = 0; i < mnfgList.size(); i++)
    {
        mnfgList[i].printOut();
        std::cout << "\n";
    }

    std::cout << "\nOffice employee list: \n";
    for (int i = 0; i < officeList.size(); i++)
    {
        officeList[i].printOut();
        std::cout << "\n";
    }
}

double Company::calculateTotalSalary()
{
    double totalSalary = 0;
    for (int i = 0; i < managerList.size(); i++)
        totalSalary += managerList[i].calculateSalary();
        
    for (int i = 0; i < mnfgList.size(); i++)
        totalSalary += mnfgList[i].calculateSalary();
    
    for (int i = 0; i < officeList.size(); i++)
        totalSalary += officeList[i].calculateSalary();
    
    return totalSalary;
}

bool Company::findEmployee(std::string fullname)
{
    bool found = false;

    for (int i = 0; i < managerList.size(); i++)
        if (fullname == managerList[i].getFullname())
            {
                managerList[i].printOut();
                std::cout << "\n";
                found = true;
            }

        
    for (int i = 0; i < mnfgList.size(); i++)
        if (fullname == mnfgList[i].getFullname())
            {
                mnfgList[i].printOut();
                std::cout << "\n";
                found = true;
            }
    
    for (int i = 0; i < officeList.size(); i++)
        if (fullname == officeList[i].getFullname())
            {
                officeList[i].printOut();
                std::cout << "\n";
                found = true;
            }
    
    return found;
}

void Company::addEmployee(const ManagerEmployee& employee)
{
    managerList.push_back(employee);
}

void Company::addEmployee(const ManufacturingEmployee& employee)
{
    mnfgList.push_back(employee);
}

void Company::addEmployee(const OfficeEmployee& employee)
{
    officeList.push_back(employee);
}