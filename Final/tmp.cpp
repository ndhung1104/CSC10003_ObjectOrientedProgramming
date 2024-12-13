#include "Ticket.h"

// #include <string>
// #include <iostream>
// #include <vector>

// using namespace std;
// class CustomerType
// {
// public:
//     virtual double discountRate() = 0;
// };

// class Student : public CustomerType
// {
// public:
//     double discountRate();
// };

// double Student::discountRate()
// {
//     return 0.3;
// }

// class VIP : public CustomerType
// {
// public:
//     double discountRate();
// };

// double VIP::discountRate()
// {
//     return 0.15;
// }

// class Normal : public CustomerType
// {
// public:
//     double discountRate();
// };

// double Normal::discountRate()
// {
//     return 0;
// }

// class Customer
// {
// private:
//     string id;
//     string name;
//     string phoneNumber;
//     CustomerType* type;
// public:
//     Customer(string id, string name, string phoneNumber, CustomerType* type);
//     void setType(CustomerType* type);
//     string getName();
//     ~Customer();
// };

// Customer::Customer(string id, string name, string phoneNumber, CustomerType* type) : id(id), name(name), phoneNumber(phoneNumber), type(type) {};

// string Customer::getName()
// {
//     return name;
// }

// Customer::~Customer()
// {
//     if (type)
//     {
//         delete type;
//         type = nullptr;
//     }
// }

// class Movie
// {
// private:
//     string id;
//     string name;
//     double length;
//     double basicPrice;
//     string movieTime;
//     string movieDate;

// public:
//     Movie(string id, string name, double length, double basicPrice, string movieTime, string movieDate);
//     double getBasicPrice();
//     void printInfo();
//     string getName();
//     string getTime();
//     string getDate();
// };

// string Movie::getName()
// {
//     return name;
// }

// string Movie::getTime()
// {
//     return movieTime;
// }

// string Movie::getDate()
// {
//     return movieDate;
// }


// Movie::Movie(string id, string name, double length, double basicPrice, string movieTime, string movieDate) : id(id), name(name), length(length), basicPrice(basicPrice), movieTime(movieTime), movieDate(movieDate) {};

// double Movie::getBasicPrice()
// {
//     return basicPrice;
// }

// class Ticket
// {
// protected:
//     string id;
//     Movie movie;
//     Customer* customer;
//     string chairId;
//     string ticketTime;
//     string ticketDate;

// public:
//     Ticket(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate);
//     virtual double calPrice() = 0;
//     virtual void printInfo();
//     ~Ticket();
//     string getId();
// };

// Ticket::Ticket(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate) : movie(movie), customer(customer), chairId(chairId), ticketTime(ticketTime), ticketDate(ticketDate) 
// {
//     id = to_string(rand());
// };

// void Ticket::printInfo()
// {
//     cout << "Ticket ID: " << id << ", Customer name: " << customer->getName() << ", Movie name: " << movie.getName() << ", Chair id: " << chairId << ", Movie time and date: " << movie.getTime() << " " << movie.getDate() << ", Ticket time and date: " << ticketTime << " " << ticketDate; 
// }

// string Ticket::getId()
// {
//     return id;
// }

// Ticket::~Ticket()
// {
//     if (customer)
//     {
//         delete customer;
//         customer = nullptr;
//     }
// }

// class Ticket2D : public Ticket
// {
// public:
//     Ticket2D(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate);
//     double calPrice();
//     void printInfo();
// };

// Ticket2D::Ticket2D(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate) : Ticket(movie, customer, chairId, ticketTime, ticketDate) {};
// double Ticket2D::calPrice()
// {
//     return movie.getBasicPrice() * 1.1;
// }

// void Ticket2D::printInfo()
// {
//     Ticket::printInfo();
//     cout << ", Price: " << calPrice() << "\n";
// }

// class Ticket3D : public Ticket
// {
// private:
//     double additionalFee;
// public:
//     Ticket3D(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate, double additionalFee);
//     double calPrice();
//     void printInfo();
// };

// Ticket3D::Ticket3D(Movie movie, Customer* customer, string chairId, string ticketTime, string ticketDate, double additionalFee) : Ticket(movie, customer, chairId, ticketTime, ticketDate), additionalFee(additionalFee)  {};
// double Ticket3D::calPrice()
// {
//     return (movie.getBasicPrice() + additionalFee) * 1.1;
// }

// void Ticket3D::printInfo()
// {
//     Ticket::printInfo();
//     cout << ", Price: " << calPrice() << "\n";
// }

// class TicketManager
// {
// private:
//     vector<Ticket*> ticketList;
// public:
//     Ticket* findTicket(string id);
//     TicketManager();
//     ~TicketManager();
//     double calRevenue();
//     Ticket* sellTicket(Customer* customer, Movie m, string chairId, string ticketTime, string ticketDate, string type, double additionalFee = 0);
// };

// TicketManager::~TicketManager()
// {
//     for (int i = 0; i < ticketList.size(); i++)
//         if (ticketList[i])
//         {
//             delete ticketList[i];
//             ticketList[i] = nullptr;
//         }
// }

// TicketManager::TicketManager() : ticketList(vector<Ticket*> ()) {};

// Ticket* TicketManager::sellTicket(Customer* customer, Movie m, string chairId, string ticketTime, string ticketDate, string type, double additionalFee)
// {
//     Ticket* t;
//     if (type == "2D")
//     {
//         t = new Ticket2D(m, customer, chairId, ticketTime, ticketDate);
//     }
//     else if (type == "3D")
//     {
//         t = new Ticket3D(m, customer, chairId, ticketTime, ticketDate, additionalFee);
//     }
//     else
//         return nullptr;
//     ticketList.push_back(t);

//     return t;
// }

// Ticket* TicketManager::findTicket(string id)
// {
//     for (int i = 0; i < ticketList.size(); i++)
//         if (id == ticketList[i]->getId())
//             return ticketList[i];
    
//     return nullptr;
// }

// double TicketManager::calRevenue()
// {
//     double rev = 0;

//     for (int i = 0; i < ticketList.size(); i++)
//         rev += ticketList[i]->calPrice();

//     return rev;
// }

int main()
{
    cout << "Create 2 movies with the below info:\nm1:\nId: Movie id 1\nName: Movie name 1\nLength: 2.0\nBase price: 10\nTime: 18h\nDate: 01/01/2024\n\n";
    cout << "m2:\nId: Movie id 2\nName: Movie name 2\nLength: 3.0\nBase price: 20\nTime: 18h\nDate: 02/01/2024\n\n";
    Movie m1("Movie id 1", "Movie name 1", 2.0, 10, "18h", "01/01/2024");
    Movie m2("Movie id 2", "Movie name 2", 3.0, 20, "18h", "02/01/2024");


    cout << "Create 2 customers with the below info:\ncustomerStudent:\nId: Student id\nName: Student name\nPhone number: 0987654321\nType: Student\n\n";
    cout << "customerVIP:\nId: VIP id\nName: VIP name\nPhone number: 123456789\nType: VIP\n\n";
    Customer* customerStudent = new Customer("Student id", "Student name", "0987654321", new Student());
    Customer* customerVIP = new Customer("VIP id", "VIP name", "123456789", new VIP());
    Ticket* t2d, * t3d;
    cout << "Initialize 1 ticket manager tm\n\n";
    TicketManager tm;

    cout << "Sell a 2D ticket of movie 1 for customerStudent and a 3D ticket of movie 2 for customerVIP and print the 2 ticket info: \n\n";
    t2d = tm.sellTicket(customerStudent, m1, "R1-J11", "15h", "01/01/2024", "2D");
    t3d = tm.sellTicket(customerVIP, m2, "R2-J13", "13h", "01/01/2024", "3D", 10);
    // Ticket2D t2d("2D id", m, customerStudent, "R1-J11", "15h", "01/01/2024");
    // Ticket3D t3d("3D id", m, customerVIP, "R2-J11", "13h", "01/01/2024", 10);
    t2d->printInfo();
    t3d->printInfo();

    cout << "\nFind the 2d ticket above with id: " << t2d->getId() <<" and print info:\n";
    Ticket* tmpTicket;
    tmpTicket = tm.findTicket(t2d->getId());
    if (tmpTicket)
        tmpTicket->printInfo();

    cout << "\nThe total revenue of the ticket manager is: " << tm.calRevenue() << "\n\n";
    return 0;
}