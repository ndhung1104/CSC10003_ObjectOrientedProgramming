#include "Book.h"

int main()
{
    std::string a = "a", b = "b";
    Book a1, b1("a", b, 1, 0);

    a1.printBook();
    b1.printBook();

    return 0;
}