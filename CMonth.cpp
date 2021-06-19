//
//  CMonth.cpp
//  AsciiCalendar
//
//  Created by losirise on 06.06.2021.
//

#include "CMonth.hpp"

#include <numeric>

Month::Month()
{
    name = "NO NAME";
    days = 30;
}

Month::Month(string name, int days)
{
    this -> name = name;
    this -> days = days;
}

int Month::getDays() // return size of month in days
{
    return days;
}

string Month::getName() // return name of month
{
    return name;
}

short Month::getIndex()
{
    return index;
}

void Month::setIndex(short index) // set index for the month
{
    this -> index = index;
}

void Month::setDays(int days) // set size of month in days
{
    this -> days = days;
}

void Month::setName(string name) // set name for month
{
    this -> name = name;
}

Month::~Month()
{
    
}
