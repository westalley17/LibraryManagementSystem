/**************************************************************************
 * Author: Wes Talley
 * Filename: User.hpp
 * Initial Date: December 1, 2024
 * Purpose: To house all the information for the User class.
 **************************************************************************/

#pragma once

#include "main.hpp"

class User
{
private:
    std::string m_firstName;
    short m_lenFirstName;
    std::string m_lastName;
    short m_lenLastName;
    std::string m_email;
    short m_lenEmail;
    std::string m_password;
    short m_lenPassword;
    std::string m_username;
    short m_lenUsername;

public:
    // getters
    const std::string &getFirstName() const { return m_firstName; }
    const std::string &getLastName() const { return m_lastName; }
    const std::string &getEmail() const { return m_email; }
    const std::string &getPassword() const { return m_password; }
    const std::string &getUsername() const { return m_username; }

    // setters
    void setFirstName(const std::string &firstName) { m_firstName = firstName; }
    void setLastName(const std::string &lastName) { m_lastName = lastName; }
    void setEmail(const std::string &email) { m_email = email; }
    void setPassword(const std::string &password) { m_password = password; }
    void setUsername(const std::string &username) { m_username = username; }
};