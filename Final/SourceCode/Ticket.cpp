#include "Ticket.h"

double Student::discountRate()
{
    return 0.3;
}

double VIP::discountRate()
{
    return 0.15;
}

Customer::Customer(string id, string name, string phoneNumber, CustomerType* type) : id(id), name(name), phoneNumber(phoneNumber), type(type) {};

string Customer::getName()
{
    return name;
}

double Customer::getDiscount()
{
    return type->discountRate();
}

Customer::~Customer()
{
    if (type)
    {
        delete type;
        type = nullptr;
    }
}

string Movie::getName()
{
    return name;
}

string Movie::getTime()
{
    return movieTime;
}

string Movie::getDate()
{
    return movieDate;
}


Movie::Movie(string id, string name, double length, double basicPrice, string movieTime, string movieDate) : id(id), name(name), length(length), basicPrice(basicPrice), movieTime(movieTime), movieDate(movieDate) {};

double Movie::getBasicPrice()
{
    return basicPrice;
}

Ticket::Ticket(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate) : movie(movie), customer(customer), chairId(chairId), ticketTime(ticketTime), ticketDate(ticketDate) 
{
    id = to_string(rand());
};

void Ticket::printInfo()
{
    cout << "Ticket ID: " << id << ", Customer name: " << customer->getName() << ", Movie name: " << movie.getName() << ", Chair id: " << chairId << ", Movie time and date: " << movie.getTime() << " " << movie.getDate() << ", Ticket time and date: " << ticketTime << " " << ticketDate; 
}

string Ticket::getId()
{
    return id;
}

Ticket::~Ticket()
{
    if (customer)
    {
        delete customer;
        customer = nullptr;
    }
}

Ticket2D::Ticket2D(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate) : Ticket(movie, customer, chairId, ticketTime, ticketDate) {};
double Ticket2D::calPrice()
{
    return movie.getBasicPrice() * 1.1 * (1 - customer->getDiscount());
}

void Ticket2D::printInfo()
{
    Ticket::printInfo();
    cout << ", Price: " << calPrice() << "\n";
}

Ticket3D::Ticket3D(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate, double additionalFee) : Ticket(movie, customer, chairId, ticketTime, ticketDate), additionalFee(additionalFee)  {};
double Ticket3D::calPrice()
{
    return (movie.getBasicPrice() + additionalFee) * 1.1 * (1 - customer->getDiscount());
}

void Ticket3D::printInfo()
{
    Ticket::printInfo();
    cout << ", Price: " << calPrice() << "\n";
}

TicketManager::~TicketManager()
{
    for (int i = 0; i < ticketList.size(); i++)
        if (ticketList[i])
        {
            delete ticketList[i];
            ticketList[i] = nullptr;
        }
}

TicketManager::TicketManager() : ticketList(vector<Ticket*> ()) {};

Ticket* TicketManager::sellTicket(Customer* customer, Movie m, string chairId, string ticketTime, string ticketDate, string type, double additionalFee)
{
    Ticket* t;
    if (type == "2D")
    {
        t = new Ticket2D(m, customer, chairId, ticketTime, ticketDate);
    }
    else if (type == "3D")
    {
        t = new Ticket3D(m, customer, chairId, ticketTime, ticketDate, additionalFee);
    }
    else
        return nullptr;
    ticketList.push_back(t);

    return t;
}

Ticket* TicketManager::findTicket(string id)
{
    for (int i = 0; i < ticketList.size(); i++)
        if (id == ticketList[i]->getId())
            return ticketList[i];
    
    return nullptr;
}

double TicketManager::calRevenue()
{
    double rev = 0;

    for (int i = 0; i < ticketList.size(); i++)
        rev += ticketList[i]->calPrice();

    return rev;
}