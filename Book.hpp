/**************************************************************************
 * Author: Wes Talley
 * Filename: Book.hpp
 * Initial Date: December 1, 2024
 * Purpose: To house all the information for the Book class.
 **************************************************************************/

#pragma once

#include "main.hpp"

class Book
{
private:
    std::string m_ISBN; // this is our UUID for each individual book
    short m_lenISBN;    // these will be the running sizes of each element
    std::string m_title;
    short m_lenTitle;
    std::string m_author;
    short m_lenAuthor;
    bool m_genre;
    bool m_available;

public:
    Book(const std::string &, const std::string &, const std::string &, bool, bool);
    ~Book();
    const std::string &getISBN() const { return m_ISBN; }     // return null in the event that the c-string is empty
    const std::string &getAuthor() const { return m_author; } // return null in the event that the c-string is empty
    const std::string &getTitle() const { return m_title; }   // return null in the event that the c-string is empty
    const bool getGenre() const { return m_genre; }
    const bool getAvailability() const { return m_available; }
};

/***************************************************************************************************/