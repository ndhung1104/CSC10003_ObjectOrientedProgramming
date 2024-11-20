#include "Company.h"

Company::Company() : companyName("Unknown"), employeeList(std::vector<Employee*>()) {};
Company::Company(const std::string companyName) : companyName(companyName), employeeList(std::vector<Employee*>()) {};
// Company::Company(const std::string companyName, const std::vector<ManagerEmployee>& managerList, const std::vector<ManufacturingEmployee>& mnfgList, const std::vector<OfficeEmployee>& officeList) : companyName(companyName), managerList(managerList), mnfgList(mnfgList), officeList(officeList) {};
void Company::inputEmployee()
{
    while (true)
    {
        std::cout << "Input employee:\n1.Manager\n2.Manufacturing\n3.Office\nEnter any other key to exit\nYour input: ";
        char tmp;
        std::cin >> tmp;
        std::cin.ignore();
        Employee* employee;
        if (tmp < '1' || tmp > '3')
            break;
        if (tmp == '1')
            employee = new ManagerEmployee();
        else if (tmp == '2')
            employee = new ManufacturingEmployee();
        else
            employee = new OfficeEmployee();

        employee->getEmployeeInfo();

        employeeList.push_back(employee);
    }
}

void Company::printEmployeeList()
{
    // std::cout << "Manager employee list: \n";
    // for (int i = 0; i < managerList.size(); i++)
    // {
    //     managerList[i].printOut();
    //     std::cout << "\n";
    // }
        

    // std::cout << "\nManufacturing employee list: \n";
    // for (int i = 0; i < mnfgList.size(); i++)
    // {
    //     mnfgList[i].printOut();
    //     std::cout << "\n";
    // }

    // std::cout << "\nOffice employee list: \n";
    // for (int i = 0; i < officeList.size(); i++)
    // {
    //     officeList[i].printOut();
    //     std::cout << "\n";
    // }
    for (int i = 0; i < employeeList.size(); i++)
    {
        employeeList[i]->printOut();
        std::cout << "\n";
    }
}

double Company::calculateTotalSalary()
{
    double totalSalary = 0;
    // for (int i = 0; i < managerList.size(); i++)
    //     totalSalary += managerList[i].calculateSalary();
        
    // for (int i = 0; i < mnfgList.size(); i++)
    //     totalSalary += mnfgList[i].calculateSalary();
    
    // for (int i = 0; i < officeList.size(); i++)
    //     totalSalary += officeList[i].calculateSalary();
    for (int i = 0; i < employeeList.size(); i++)
        totalSalary += employeeList[i]->calculateSalary();
    
    return totalSalary;
}

bool Company::findEmployee(std::string fullname)
{
    bool found = false;

    // for (int i = 0; i < managerList.size(); i++)
    //     if (fullname == managerList[i].getFullname())
    //         {
    //             managerList[i].printOut();
    //             std::cout << "\n";
    //             found = true;
    //         }

        
    // for (int i = 0; i < mnfgList.size(); i++)
    //     if (fullname == mnfgList[i].getFullname())
    //         {
    //             mnfgList[i].printOut();
    //             std::cout << "\n";
    //             found = true;
    //         }
    
    // for (int i = 0; i < officeList.size(); i++)
    //     if (fullname == officeList[i].getFullname())
    //         {
    //             officeList[i].printOut();
    //             std::cout << "\n";
    //             found = true;
    //         }

    for (int i = 0; i < employeeList.size(); i++)
        if (fullname == employeeList[i]->getFullname())
            {
                employeeList[i]->printOut();
                std::cout << "\n";
                found = true;
            }
    
    return found;
}


bool Company::findEmployeeCode(std::string employeeCode)
{
    bool found = false;

    for (int i = 0; i < employeeList.size(); i++)
        if (employeeCode == employeeList[i]->getEmployeeCode())
            {
                employeeList[i]->printOut();
                std::cout << "\n";
                found = true;
            }
    
    return found;
}

bool Company::findEmployeeWithBirthMonth(int month)
{
    bool found = false;

    for (int i = 0; i < employeeList.size(); i++)
        if (month == employeeList[i]->getEmployeeBirthMonth())
            {
                employeeList[i]->printOut();
                std::cout << "\n";
                found = true;
            }
    
    return found;
}


void Company::addEmployee(ManagerEmployee& employee)
{
    Employee* emp = &employee;
    employeeList.push_back(emp);
    // managerList.push_back(employee);
}

void Company::addEmployee(ManufacturingEmployee& employee)
{
    Employee* emp = &employee;
    employeeList.push_back(emp);
}

void Company::addEmployee(OfficeEmployee& employee)
{
    Employee* emp = &employee;
    employeeList.push_back(emp);
}

Company::~Company()
{
    for (int i = 0; i < employeeList.size(); i++)
        delete employeeList[i];
}

void Company::findHighestSalaryEmployee()
{
    if (employeeList.size() == 0)
    {
        std::cout << "There is no employee in the company!\n";
        return;
    }
    int pos = 0;
    double salary = employeeList[0]->calculateSalary();
    for (int i = 1; i < employeeList.size(); i++)
    {
        double tmpSalary = employeeList[i]->calculateSalary();
        if (tmpSalary > salary)
        {
            pos = i;
            salary = tmpSalary;
        }
    }
    std::cout << "The highest salary is: " << salary << " of employee: " << employeeList[pos]->getFullname() << ".\n";
}

int Company::getNumberOfEmployee(int type) // 1 = Manager, 2 = Manufacturing, 3 = Office
{
    int count = 0;
    for (int i = 0; i < employeeList.size(); i++)
        if (employeeList[i]->getEmployeeType() == type)
            count++;
    
    return count;
}

double Company::calculateAverageSalary()
{
    return calculateTotalSalary() / employeeList.size();
}

void Company::findEmployeeWithSalaryBelow(double salary)
{
    for (int i = 0; i < employeeList.size(); i++)
        if (employeeList[i]->calculateSalary() < salary)
        {
            employeeList[i]->getEmployeeInfo();
            std::cout << "\n";
        }
}