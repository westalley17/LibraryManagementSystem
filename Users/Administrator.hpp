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
    char m_accessKey[AdminConstraints::ACCESS_KEY_LENGTH]; // 10 character string representing a full-pass key
public:
};