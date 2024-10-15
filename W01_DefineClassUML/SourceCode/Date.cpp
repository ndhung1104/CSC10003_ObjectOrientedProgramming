#include <iostream>
#include "Date.h"

bool Date::isLeapYear(int y) 
{
    if (y % 4 == 0) 
    {
        if (y % 100 == 0) 
        {
            return y % 400 == 0;
        }
        return true;
    }
    return false;
}

int Date::daysInYears() 
{
    int days = 0;
    for (int y = 1; y <= year; y++) 
    {
        days += isLeapYear(y) ? 366 : 365;
    }
    return days;
}

int Date::daysInMonths() 
{
    int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = 0;
    for (int m = 1; m < month; m++) 
    {
        days += monthDays[m - 1];
    }
    if (month > 2 && isLeapYear(year)) 
    {
        days += 1;
    }
    return days;
}

void Date::dateToDays() {
    
    numberOfDays = daysInYears(); 
    numberOfDays += daysInMonths(); 
    numberOfDays += day; 
}

void Date::daysToDate() {
    int tmp = numberOfDays;
    year = 1;
    
    while (tmp >= daysInYears()) 
    {
        year++;
    }
    year--;
    tmp -= daysInYears();
    
    month = 1;
    
    while (tmp >= daysInMonths()) 
    {
        month++;
    }
    month--;
    tmp -= daysInMonths();
    
    day = tmp;
}

void Date::input()
{
    std::cout << "Input day: ";
    std::cin >> day;

    std::cout << "Input month: ";
    std::cin >> month;

    std::cout << "Input year: ";
    std::cin >> year;

    dateToDays();

    std::cin.ignore();
}

void Date::output()
{
    std::cout << "Date in dd/mm/yy format is: " << this->day << "/" << this->month << "/" << this->year << "\n";
}

void Date::increaseNDay(int n)
{
    numberOfDays += n;
    daysToDate();
}

void Date::increaseOneDay()
{
    increaseNDay(1);
}

void Date::decreaseNDay(int n)
{
    increaseNDay(-n);
}

void Date::decreaseOneDay()
{
    decreaseNDay(1);
}

int Date::compare(Date x)
{
    if (numberOfDays > x.numberOfDays)
        return 1;
    else if (numberOfDays < x.numberOfDays)
        return -1;
    
    return 0;
}


