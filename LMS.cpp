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
    int menuChoice = -1;
    // 1. Populate map attributes
    // use inverses of typical logic flow to make less indentations and more readable code.
    if (populateLibrary() == false)
    {
        // print error and quit program.
        std::cout << "Error: Could not populate library!" << std::endl;
        return;
    }
    // else continue running...
    // 2. Run Library :)
    do
    {
        system("cls"); // clear the screen every time it loops to keep everything in one window
        
    } while (menuChoice != 5);
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
        std::cout << std::endl
                  << "Could not open books.txt!" << std::endl;
        return false;
    }
    while (std::getline(infileBooks, buffer))
    {
        std::shared_ptr<Book> newBook = std::make_shared<Book>();
        newBook->setISBN(buffer);
        std::getline(infileBooks, buffer);
        newBook->setTitle(buffer);
        std::getline(infileBooks, buffer);
        newBook->setAuthor(buffer);
        std::getline(infileBooks, buffer);
        newBook->setGenre(buffer);
        std::getline(infileBooks, buffer);
        newBook->setAvailable(buffer == "Yes" ? true : false);
        // populating a new pair in the map automatically calls the copy constructor of the smart pointer,
        // increasing its ref count aka storing the book in the library :)
        books[newBook->getISBN()] = newBook;
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
        newAdmin->setFirstName(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin->setLastName(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin->setEmail(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin->setPassword(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin->setUsername(buffer);
        std::getline(infileAdmins, buffer);
        newAdmin->setAccessKey(buffer);
        // same thing happens here with the copy constructor doohicky :)
        administrators[newAdmin->getUsername()] = newAdmin;
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
        newPatron->setFirstName(buffer);
        std::getline(infilePatrons, buffer);
        newPatron->setLastName(buffer);
        std::getline(infilePatrons, buffer);
        newPatron->setEmail(buffer);
        std::getline(infilePatrons, buffer);
        newPatron->setPassword(buffer);
        std::getline(infilePatrons, buffer);
        newPatron->setUsername(buffer);
        std::getline(infilePatrons, buffer);
        newPatron->setNumBorrowed(std::stoi(buffer));
        patrons[newPatron.get()->getUsername()] = newPatron;
    }
    return true;
}
