class Date
{
    int day;
    int month;
    int year;
    int numberOfDays;
    bool isLeapYear(int y);
    int daysInYears();
    int daysInMonths();
    void dateToDays();
    void daysToDate();


public:
    void input();
    void output();
    void increaseOneDay();
    void increaseNDay(int n);
    void decreaseOneDay();
    void decreaseNDay(int n);
    int compare(Date x);
};
