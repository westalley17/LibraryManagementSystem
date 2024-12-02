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
    char m_ISBN[BookInputConstraints::ISBN_LENGTH]; // this is our UUID for each individual book
    short m_lenISBN;                                // these will be the running sizes of each element
    char m_title[BookInputConstraints::TITLE_LENGTH];
    short m_lenTitle;
    char m_author[BookInputConstraints::AUTHOR_LENGTH];
    short m_lenAuthor;
    bool m_genre;
    bool m_available;

public:
    Book(const char *, const char *, const char *, bool, bool);
    ~Book();
    char *getISBN() { return m_lenISBN > 0 ? m_ISBN : nullptr; }       // return null in the event that the c-string is empty
    char *getAuthor() { return m_lenAuthor > 0 ? m_author : nullptr; } // return null in the event that the c-string is empty
    char *getTitle() { return m_lenTitle > 0 ? m_title : nullptr; }    // return null in the event that the c-string is empty
    bool getGenre() { return m_genre; }
    bool getAvailability() { return m_available; }
};

/***************************************************************************************************/