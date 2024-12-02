/********************************************************************************************************
 * Author: Wes Talley
 * Filename: LMS.hpp
 * Initial Date: December 1, 2024
 * Purpose: To house the class definition and its function prototypes to be used in the driver.
 ********************************************************************************************************/

#pragma once

#include "Users/Administrator.hpp"
#include "Users/Patron.hpp"
#include "Book.hpp"

// each Book and User instance in this library will be allocated using smart pointers to manage memory more safely.
// the job of this class is to be able to manage any User or Book in its system--be it removing the instance,
// creating more instances, or modifying existing ones.

/*
    TODO:
        - Use RegEx matching to validate user input to ensure security
        - Validate length of user input against namespaces
        - IMPLEMENT WINDOWS CLEAR SCREEN FUNCTIONALITY FOR BETTER LOOK/FEEL :D
*/
class LibraryManagementSystem
{
private:
    std::unordered_map<std::string, std::shared_ptr<Book>> books;
    std::unordered_map<std::string, std::shared_ptr<Administrator>> administrators;
    std::unordered_map<std::string, std::shared_ptr<Patron>> patrons;

public:
    void run();
};