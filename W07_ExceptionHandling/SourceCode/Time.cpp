#include "Time.h"

TimeFormatException::TimeFormatException(int value, const std::string& reason) : value(value), reason(reason) {};

const char* TimeFormatException::what() const throw() {
    static std::string msg;

    msg = "Invalid value: " + std::to_string(value) + ". " + reason;
    return msg.c_str();
}

Time::Time(int h, int m, int s) 
{
    if (h < 0 || h > 23) {
        throw TimeFormatException(h, "Hours must be between 0 and 23.");
    }

    if (m < 0 || m > 59) {
        throw TimeFormatException(m, "Minutes must be between 0 and 59.");
    }

    if (s < 0 || s > 59) {
        throw TimeFormatException(s, "Seconds must be between 0 and 59.");
    }

    this->h = h;
    this->m = m;
    this->s = s;
}