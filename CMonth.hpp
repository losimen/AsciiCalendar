//
//  CMonth.hpp
//  AsciiCalendar
//
//  Created by losirise on 06.06.2021.
//

#ifndef CMonth_hpp
#define CMonth_hpp

#include "func.hpp"
#include <vector>

class Month
{
    
protected:
    string name; // name of the month
    int days; // amount of days in month
    short index; // month's index

public:
    Month();
    Month(string name, int days);
  
    int getDays(); // return size of month in days
    string getName();

    void setDays(int days); // set size of month in days
    void setName(string name); // set name for month
    
    
    short getIndex();
    void setIndex(short index); // set index for the month
    


    
    ~Month();
};

#endif /* CMonth_hpp */
