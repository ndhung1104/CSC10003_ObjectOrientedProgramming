#include "Book.h"

Book::Book()
{
    std::string defaultTitle, defaultAuthor;
    defaultTitle = "Unknown Title";
    defaultAuthor = "Unknown Author";

    title = new char[defaultTitle.size() + 1];
    author = new char[defaultAuthor.size() + 1];

    strcpy(title, defaultTitle.c_str());
    strcpy(author, defaultAuthor.c_str());
    
    pages = 0;
    price = 0.0;
}

Book::Book(std::string defaultTitle, std::string defaultAuthor, int pages, double price)
{
    title = new char[defaultTitle.size() + 1];
    author = new char[defaultAuthor.size() + 1];

    strcpy(title, defaultTitle.c_str());
    strcpy(author, defaultAuthor.c_str());
    
    this->pages = pages;
    this->price = price;
}

void Book::printBook()
{
    std::cout << title << " " << author << " " << pages << " " << price << "\n";
}

Book::~Book()
{
    delete [] title;
    delete [] author;
    title = nullptr;
    author = nullptr;

    std::cout << "Book object destroyed \n";
}
