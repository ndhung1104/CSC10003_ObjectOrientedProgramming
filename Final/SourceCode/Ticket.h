#include <string>
#include <iostream>
#include <vector>

using namespace std;

class CustomerType
{
public:
    virtual double discountRate() = 0;
};

class Student : public CustomerType
{
public:
    double discountRate();
};

class VIP : public CustomerType
{
public:
    double discountRate();
};

class Normal : public CustomerType
{
public:
    double discountRate();
};

class Customer
{
private:
    string id;
    string name;
    string phoneNumber;
    CustomerType* type;
public:
    Customer(string id, string name, string phoneNumber, CustomerType* type);
    void setType(CustomerType* type);
    string getName();
    ~Customer();
    double getDiscount();
};

class Movie
{
private:
    string id;
    string name;
    double length;
    double basicPrice;
    string movieTime;
    string movieDate;

public:
    Movie(string id, string name, double length, double basicPrice, string movieTime, string movieDate);
    double getBasicPrice();
    void printInfo();
    string getName();
    string getTime();
    string getDate();
};

class Ticket
{
protected:
    string id;
    Movie movie;
    Customer* customer;
    string chairId;
    string ticketTime;
    string ticketDate;

public:
    Ticket(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate);
    virtual double calPrice() = 0;
    virtual void printInfo();
    ~Ticket();
    string getId();
};

class Ticket2D : public Ticket
{
public:
    Ticket2D(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate);
    double calPrice();
    void printInfo();
};

class Ticket3D : public Ticket
{
private:
    double additionalFee;
public:
    Ticket3D(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate, double additionalFee);
    double calPrice();
    void printInfo();
};

class TicketManager
{
private:
    vector<Ticket*> ticketList;
public:
    Ticket* findTicket(string id);
    TicketManager();
    ~TicketManager();
    double calRevenue();
    Ticket* sellTicket(Customer* customer, Movie m, string chairId, string ticketTime, string ticketDate, string type, double additionalFee = 0);
};