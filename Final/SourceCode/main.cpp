#include "Ticket.h"

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