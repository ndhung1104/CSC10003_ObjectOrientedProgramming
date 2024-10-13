#include <iostream>
#include "Student.h"

void Student::inputGrade()
{
    std::cout << "Input math grade: ";
    std::cin >> mathGrade;

    std::cout << "Input english grade: ";
    std::cin >> englishGrade;

    std::cout << "Input programming grade: ";
    std::cin >> programmingGrade;
}

void Student::outputAverageGrade()
{
    double avgGrade = (mathGrade + englishGrade + programmingGrade) / 3;
    std::cout << "The student's average grade is: " << avgGrade << "\n";
}

void Student::isFullyExcelence()
{
    double avgGrade = (mathGrade + englishGrade + programmingGrade) / 3;

    if (avgGrade > 8 && mathGrade > 6.5 && englishGrade > 6.5 && programmingGrade > 6.5)
        std::cout << "This student is gioi toan dien! \n";
    else    
        std::cout << "This student is not gioi toan dien \n"; 
}