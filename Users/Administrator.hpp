/**************************************************************************
 * Author: Wes Talley
 * Filename: Administrator.hpp
 * Initial Date: December 2, 2024
 * Purpose: To house all the information for the Admin class.
 **************************************************************************/

#pragma once

#include "User.hpp"

// child class from the general User class for admin purposes/privileges
class Administrator : User
{
private:
    std::string m_accessKey;
public:
};