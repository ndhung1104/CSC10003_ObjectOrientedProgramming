#include "ManagerEmployee.h"
#include "ManufacturingEmployee.h"
#include "OfficeEmployee.h"
#include "Company.h"

int main()
{
    // std::cout << "Initialize 5 employees with different constructors: \n";
    // Employee e1("Nguyen Van A"), e2("Nguyen Van A", 2024), e3("Nguyen Van A", 2024, 1000), e4, e5(e1);
    // e1.printOut(); std::cout << "\n";
    // e2.printOut(); std::cout << "\n";
    // e3.printOut(); std::cout << "\n";
    // e4.printOut(); std::cout << "\n";
    // e5.printOut(); std::cout << "\n\n";

    // std::cout << "Initialize 5 office employees with different constructors: \n";
    // OfficeEmployee oe1("Nguyen Van B", 2024, 1000), oe2("Nguyen Van C", 2024, 1000, 30), oe3("Nguyen Van D", 2024, 1000, 30, 5000), oe4, oe5(oe1);
    // oe1.printOut(); std::cout << "\n";
    // oe2.printOut(); std::cout << "\n";
    // oe3.printOut(); std::cout << "\n";
    // oe4.printOut(); std::cout << "\n";
    // oe5.printOut(); std::cout << "\n\n";

    // std::cout << "Initialize 5 manufacturing employees with different constructors: \n";
    // ManufacturingEmployee me1("Nguyen Van E", 2024, 1000), me2("Nguyen Van F", 2024, 1000, 30), me3("Nguyen Van G", 2024), me4, me5(me1);
    // me1.printOut(); std::cout << "\n";
    // me2.printOut(); std::cout << "\n";
    // me3.printOut(); std::cout << "\n";
    // me4.printOut(); std::cout << "\n";
    // me5.printOut(); std::cout << "\n\n";

    // std::cout << "Initialize 5 manager employees with different constructors: \n";
    // ManagerEmployee mnge1("Nguyen Van H", 2024, 1000), mnge2("Nguyen Van I", 2024, 1000, 3), mnge3("Nguyen Van J", 2024, 1000, 3, 1999), mnge4, mnge5(mnge1);
    // mnge1.printOut(); std::cout << "\n";
    // mnge2.printOut(); std::cout << "\n";
    // mnge3.printOut(); std::cout << "\n";
    // mnge4.printOut(); std::cout << "\n";
    // mnge5.printOut(); std::cout << "\n\n";

    // std::cout << "Input employees 4 and print out the result: \n";
    // e4.getEmployeeInfo();
    // e4.printOut(); std::cout << "\n\n";
    // std::cout << "Calculate employees 4 salary and print out the result: \n";
    // std::cout << e4.calculateSalary() << "\n";

    std::cout << "\nCreate company ABC!\n";
    Company company("ABC");
    // company.addEmployee(oe1); company.addEmployee(oe2); company.addEmployee(oe3); company.addEmployee(oe4); company.addEmployee(oe5);
    // company.addEmployee(me1); company.addEmployee(me2); company.addEmployee(me3); company.addEmployee(me4); company.addEmployee(me5);
    // company.addEmployee(mnge1); company.addEmployee(mnge2); company.addEmployee(mnge3); company.addEmployee(mnge4); company.addEmployee(mnge5);

    std::cout << "\nInput employees from keyboard: \n";
    company.inputEmployee();

    std::cout << "\nPrint out the list of employee: \n";
    company.printEmployeeList();

    std::cout << "\nThe total salary of the company is: " << company.calculateTotalSalary() << "\n";

    std::cout << "\nFind the employee with the highest salary in the company will result in: \n";
    company.findHighestSalaryEmployee();

    std::cout << "\nFind the number of manufacturing employee in the company will result in: " << company.getNumberOfEmployee(2) << "\n";

    std::cout << "\nFind the number of office employee in the company will result in: " << company.getNumberOfEmployee(3) << "\n";

    std::cout << "\nFind the average salary in the company will result in: " << company.calculateAverageSalary() << "\n";

    // std::cout << "\nEnter: \n";
    // company.findEmployeeWithSalaryBelow(3000000);

    // std::cout << "\nFind the employee with the salary < 3000000 in the company will result in: \n";
    // company.findEmployeeWithSalaryBelow(3000000);


    return 0;
}