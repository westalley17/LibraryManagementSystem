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
    char m_firstName[UserInputConstraints::FIRSTNAME_LENGTH];
    short m_lenFirstName;
    char m_lastName[UserInputConstraints::LASTNAME_LENGTH];
    short m_lenLastName;
    char m_email[UserInputConstraints::EMAIL_LENGTH];
    short m_lenEmail;
    char m_password[UserInputConstraints::PASSWORD_LENGTH];
    short m_lenPassword;
    char m_username[UserInputConstraints::USERNAME_LENGTH];
    short m_lenUsername;

public:
    char *getFirstName() { return m_lenFirstName > 0 ? m_firstName : nullptr; }
    char *getLastName() { return m_lenLastName > 0 ? m_lastName : nullptr; }
    char *getEmail() { return m_lenEmail > 0 ? m_email : nullptr; }
    char *getPassword() { return m_lenPassword > 0 ? m_password : nullptr; }
    char *getUsername() { return m_lenUsername > 0 ? m_username : nullptr; }
};