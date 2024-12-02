/*******************************************************
 * Author: Wes Talley
 * Filename: main.hpp
 * Initial Date: December 1, 2024
 * Purpose: To house all the general libraries and constants
 * used throughout the program.
 * OVERALL GOAL
 * Learn smart pointers, better OOP, and secure software engineering practices
 * as well as brush up on DSA material :)
 *******************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <cstdlib>
#include <chrono> // for benchmarking purposes with the ability to grab time units, will also need a Timer class of some sort to implement this with.
#include <string>
#include <cstring>

/*
 * Global constants and "singletons" stored here
 * THESE NEED TO BE MADE ISO STANDARD!!!!!
 */

namespace BookInputConstraints
{
    const short ISBN_LENGTH = 17; // 13 integers + 4 hyphens
    const short TITLE_LENGTH = 50;
    const short AUTHOR_LENGTH = 50;
}

namespace UserInputConstraints
{
    const short FIRSTNAME_LENGTH = 30;
    const short LASTNAME_LENGTH = 30;
    const short EMAIL_LENGTH = 50;
    const short PASSWORD_LENGTH = 50;
    const short USERNAME_LENGTH = 15;
    const short BORROW_LIMIT = 10;
}

/*************************************************/