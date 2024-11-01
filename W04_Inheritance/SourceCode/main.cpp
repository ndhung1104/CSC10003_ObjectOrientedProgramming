#include "ManagerEmployee.h"
#include "ManufacturingEmployee.h"
#include "OfficeEmployee.h"

int main()
{
    std::cout << "Initialize 5 employees with different constructors: \n";
    Employee e1("Nguyen Van A"), e2("Nguyen Van A", 2024), e3("Nguyen Van A", 2024, 1000), e4, e5(e1);
    e1.printOut(); std::cout << "\n";
    e2.printOut(); std::cout << "\n";
    e3.printOut(); std::cout << "\n";
    e4.printOut(); std::cout << "\n";
    e5.printOut(); std::cout << "\n\n";

    std::cout << "Initialize 5 office employees with different constructors: \n";
    OfficeEmployee oe1("Nguyen Van A", 2024, 1000), oe2("Nguyen Van A", 2024, 1000, 30), oe3("Nguyen Van A", 2024, 1000, 30, 5000), oe4, oe5(oe1);
    oe1.printOut(); std::cout << "\n";
    oe2.printOut(); std::cout << "\n";
    oe3.printOut(); std::cout << "\n";
    oe4.printOut(); std::cout << "\n";
    oe5.printOut(); std::cout << "\n\n";

    std::cout << "Initialize 5 manufacturing employees with different constructors: \n";
    ManufacturingEmployee me1("Nguyen Van A", 2024, 1000), me2("Nguyen Van A", 2024, 1000, 30), me3("Nguyen Van A", 2024), me4, me5(me1);
    me1.printOut(); std::cout << "\n";
    me2.printOut(); std::cout << "\n";
    me3.printOut(); std::cout << "\n";
    me4.printOut(); std::cout << "\n";
    me5.printOut(); std::cout << "\n\n";

    std::cout << "Initialize 5 manager employees with different constructors: \n";
    ManagerEmployee mnge1("Nguyen Van A", 2024, 1000), mnge2("Nguyen Van A", 2024, 1000, 3), mnge3("Nguyen Van A", 2024, 1000, 3, 1999), mnge4, mnge5(mnge1);
    mnge1.printOut(); std::cout << "\n";
    mnge2.printOut(); std::cout << "\n";
    mnge3.printOut(); std::cout << "\n";
    mnge4.printOut(); std::cout << "\n";
    mnge5.printOut(); std::cout << "\n\n";

    std::cout << "Input employees 4 and print out the result: \n";
    e4.getEmployeeInfo();
    e4.printOut(); std::cout << "\n\n";
    std::cout << "Calculate employees 4 salary and print out the result: \n";
    std::cout << e4.calculateSalary() << "\n";
    return 0;
}