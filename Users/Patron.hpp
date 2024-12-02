/**************************************************************************
 * Author: Wes Talley
 * Filename: Patron.hpp
 * Initial Date: December 2, 2024
 * Purpose: To house all the information for the Patron class.
 **************************************************************************/

#pragma once

#include "User.hpp"

// child class from the general User class for typical library visitor
class Patron : User
{
private:
    short m_borrowed; // init to 0 in constructor
public:
};