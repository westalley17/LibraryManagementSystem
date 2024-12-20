/**************************************************************************
 * Author: Wes Talley
 * Filename: Administrator.hpp
 * Initial Date: December 2, 2024
 * Purpose: To house all the information for the Admin class.
 **************************************************************************/

#pragma once

#include "User.hpp"

// child class from the general User class for admin purposes/privileges
class Administrator : public User
{
private:
    std::string m_accessKey;

public:
    const std::string &getAccessKey() { return m_accessKey; }
    void setAccessKey(const std::string &accessKey) { m_accessKey = accessKey; }
};