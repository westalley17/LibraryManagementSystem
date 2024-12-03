/********************************************************************************************************
 * Author: Wes Talley
 * Filename: LMS.cpp
 * Initial Date: December 2, 2024
 * Purpose: To house the class functions to be called from the driver.
 ********************************************************************************************************/

#include "LMS.hpp"

/********************************************************************************************************/

/**
 * @brief
 * Will call subroutines to populate the maps,
 * display any requested data, manage said data,
 * and eventually clean up any dangling processes.
 */
void LibraryManagementSystem::run()
{
    // 1. Populate map attributes
    // use inverses of typical logic flow to make less indentations and more readable code.
    if (populateLibrary() == false)
    {
        // print error and quit program.
        std::cout << "Error: Could not populate library!" << std::endl;
        return;
    }
    // else continue running...
}
/*
 * TODO: spin each one of these file objects on to
 * a new thread to "improve" performance (assuming
 * literally millions of books or something... mainly
 * just for practice)
 */
bool LibraryManagementSystem::populateLibrary()
{
    std::ifstream infileBooks("Data/books.txt");
    std::ifstream infileAdmins("Data/admins.txt");
    std::ifstream infilePatrons("Data/patrons.txt");
    std::string buffer;
    // fill books map
    if (!infileBooks.is_open())
    {
        std::cout << std::endl << "Could not open books.txt!" << std::endl;
        return false;
    }
    while (std::getline(infileBooks, buffer))
    {
        std::shared_ptr<Book> newBook = std::make_shared<Book>();
        newBook.get()->setISBN(buffer);
        std::getline(infileBooks, buffer);
        newBook.get()->setTitle(buffer);
        std::getline(infileBooks, buffer);
        newBook.get()->setAuthor(buffer);
        std::getline(infileBooks, buffer);
        newBook.get()->setGenre(buffer == "1" ? true : false);
        std::getline(infileBooks, buffer);
        newBook.get()->setAvailable(buffer == "1" ? true : false);
        // populating a new pair in the map automatically calls the copy constructor of the smart pointer,
        // increasing its ref count aka storing the book in the library :)
        books[newBook.get()->getISBN()] = newBook;
    }
    if (!infileAdmins.is_open())
    {
        std::cout << std::endl
                  << "Could not open admins.txt!" << std::endl;
        return false;
    }
    // fill admin map
    while (std::getline(infileAdmins, buffer))
    {
        std::shared_ptr<Administrator> newAdmin = std::make_shared<Administrator>();
        newAdmin.get()->setFirstName(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin.get()->setLastName(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin.get()->setEmail(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin.get()->setPassword(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin.get()->setUsername(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin.get()->setAccessKey(buffer);
        // same thing happens here with the copy constructor doohicky :)
        administrators[newAdmin.get()->getUsername()] = newAdmin;
    }
    if (!infilePatrons.is_open())
    {
        std::cout << std::endl
                  << "Could not open patrons.txt!" << std::endl;
        return false;
    }
    // fill patron map
    while (std::getline(infilePatrons, buffer))
    {
        std::shared_ptr<Patron> newPatron = std::make_shared<Patron>();
        newPatron.get()->setFirstName(buffer);
        std::getline(infileAdmins, buffer);
        newPatron.get()->setLastName(buffer);
        std::getline(infileAdmins, buffer);
        newPatron.get()->setEmail(buffer);
        std::getline(infileAdmins, buffer);
        newPatron.get()->setPassword(buffer);
        std::getline(infileAdmins, buffer);
        newPatron.get()->setUsername(buffer);
        std::getline(infileAdmins, buffer);
        newPatron.get()->setNumBorrowed(std::stoi(buffer));
        patrons[newPatron.get()->getUsername()] = newPatron;
    }
    return true;
}
