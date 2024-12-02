/**************************************************************************
 * Author: Wes Talley
 * Filename: Book.cpp
 * Initial Date: December 1, 2024
 * Purpose: Function definitions for the Book class
 **************************************************************************/

#include "Book.hpp"

Book::Book(const char *ISBN, const char *author, const char *title, bool genre, bool available)
{
    // initialize Book attributes (assuming security measures were taken in the LMS)
    std::strncpy(m_ISBN, ISBN, BookInputConstraints::ISBN_LENGTH); // buffer size will be taken into account in the LMS verification
    std::strncpy(m_author, author, BookInputConstraints::AUTHOR_LENGTH);
    std::strncpy(m_title, title, BookInputConstraints::TITLE_LENGTH);
    m_genre = genre;
    m_available = available;
    // accumulate runners (quite proud of these)
    for (m_lenISBN = 0; m_lenISBN < BookInputConstraints::ISBN_LENGTH && m_ISBN[m_lenISBN] != '\0'; m_lenISBN++)
        ;
    for (m_lenAuthor = 0; m_lenAuthor < BookInputConstraints::AUTHOR_LENGTH && m_author[m_lenAuthor] != '\0'; m_lenAuthor++)
        ;
    for (m_lenTitle = 0; m_lenTitle < BookInputConstraints::TITLE_LENGTH && m_title[m_lenTitle] != '\0'; m_lenTitle++)
        ;
}

Book::~Book()
{
    // destruct ? (BOOM)
    // no need for this really since we're going to use smart pointers throughout code :)
}
