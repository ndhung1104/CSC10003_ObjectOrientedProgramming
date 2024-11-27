#include "Date.h"

DateFormatException::DateFormatException(int value, const std::string& reason) : value(value), reason(reason) {};

const char* DateFormatException::what() const throw()
{
    std::string msg;
    msg += "The input number: " + std::to_string(value) + " is invalid. " + reason + "\n";
    return msg.c_str();
}

bool Date::isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date::Date(int dd, int mm, int yy) : mm(1), dd(1), yy(2000)
{
    if (mm < 1 || mm > 12) {
        throw DateFormatException(mm, "Month must be between 1 and 12.");
    }

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (mm == 2 && isLeapYear(yy)) {
        daysInMonth[2] = 29;
    }

    if (dd < 1 || dd > daysInMonth[mm]) {
        throw DateFormatException(dd, "Day is out of range for the given month and year.");
    }

    if (yy < 1) {
        throw DateFormatException(yy, "Year must be greater than 0.");
    }

    this->mm = mm;
    this->yy = yy;
    this->dd = dd;
}