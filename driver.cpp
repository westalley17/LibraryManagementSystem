/**************************************************************************
 * Author: Wes Talley
 * Filename: driver.cpp
 * Initial Date: December 2, 2024
 * Purpose: The initial calling point of the program to initialize an LMS
 * object and run its functionality.
 **************************************************************************/

#include "LMS.hpp"

int main()
{
    // generate the LMS object
    LibraryManagementSystem library;
    // call run
    library.run();
    // cleanup
    return 0;
}