//
//  CCalendar.hpp
//  AsciiCalendar
//
//  Created by losirise on 05.06.2021.
//

#ifndef CCalendar_hpp
#define CCalendar_hpp

#include "CMonth.hpp"

class Calendar : protected Month
{
private:
    Month month[12];
    int year;
    
    //PRIVATE METHODS USE ONLY BY CALENDAR
    void printDays(int counter); // show on ther screen month appearance
    void setMonth(int year); // function wich gives an month amount of days.
    
public:
    
    Calendar(); // gets system date

    bool isLeapYear(int year); // determine if year is leap
    void seeCalendarShell(); // see calendar
    Calendar& operator++(); // + 1 to year
    Calendar& operator--(); // -1 from year

    
    ~Calendar();
};


#endif /* CCalendar_hpp */
