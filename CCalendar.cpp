//
//  CCalendar.cpp
//  AsciiCalendar
//
//  Created by losirise on 05.06.2021.
//

#include "CCalendar.hpp"
#include "colormod.hpp"

#include <ctime>
#include <cstring>

Calendar::Calendar() : Month()
{
    //determine system year
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    this -> year = 1900 + ltm->tm_year;
    
    setMonth(year);
}

void Calendar::printDays(int cycle) // show on ther screen months appearance
{
    
    // (1.25*year) % 7
    int weekCounter = 1, monthCounter, weekDay, actualDay;
    
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    
    for (int j = 0; j < 6; j++) // how many rows
    {
        monthCounter = cycle;

        // FORMULA::: ( (year*1.25) % 7 + index month + index day) % 7
        
        for (int i = 0; i < 4; i++) // how many months
        {
            weekDay = (int(1.25*year)%7 + month[monthCounter].getIndex() + 1) % 7;
            
            if (weekDay == 0)
                weekDay = 7;
            
            for (int k = weekCounter; k < weekCounter+7; k++) // how many days
            {
                
                cout.width(4);
                
                string a = month[monthCounter].getName();
                
                actualDay = k - weekDay;
                
                if ( k < weekDay)
                    cout << " " << setw(2);
                
                else if (actualDay > month[monthCounter].getDays() - 1) // space if amount of days is less than need
                    cout << " " << setw(2);
                
               
                
                else
                    cout << actualDay+1 << setw(2);
            }
            
            monthCounter += 1;
            cout << "|";
        }
        
        cout << endl;
        weekCounter += 7;
    }
}

bool Calendar::isLeapYear(int year) // determine if year is leap
{
    if (year % 400 == 0)
        return true;
 
    if (year % 100 == 0)
        return false;
 
    if (year % 4 == 0)
        return true;
    
    return false;
}

void Calendar::setMonth(int year) // function wich gives an month number of days.
{

    month[0].setName("JANUARY");
    month[0].setDays(31);


    if (isLeapYear(year))
    {
        month[1].setName("FEBRUARY");
        month[1].setDays(29);
        month[1].setIndex(0);
        
        month[0].setIndex(4); // JANUARY INDEX
    }
    else
    {
        month[1].setName("FEBRUARY");
        month[1].setDays(28); // FEBRUARY
        month[1].setIndex(1);
        
        month[0].setIndex(5); // JANUARY INDEX
    }
    
    month[2].setName("MARCH");
    month[2].setDays(31); // MARCH
    month[2].setIndex(1);
    
    month[3].setName("APRIL");
    month[3].setDays(30); // APRIL
    month[3].setIndex(4);
    
    month[4].setName("MAY");
    month[4].setDays(31); // MAY
    month[4].setIndex(6);
    
    month[5].setName("JUNE");
    month[5].setDays(30); // JUNE
    month[5].setIndex(2);
    
    month[6].setName("JULY");
    month[6].setDays(31); // JULY
    month[6].setIndex(4);
    
    month[7].setName("AUGUST");
    month[7].setDays(31); // AUGUST
    month[7].setIndex(0);
    
    month[8].setName("SEPTEMBER");
    month[8].setDays(30); // SEPTEMBER
    month[8].setIndex(3);
    
    month[9].setName("OCTOBER");
    month[9].setDays(31); // OCTOBER
    month[9].setIndex(5);
    
    month[10].setName("NOVEMBER");
    month[10].setDays(30);// NOVEMBER
    month[10].setIndex(1);
    
    month[11].setName("DECEMBER");
    month[11].setDays(31);// DECEMBER
    month[11].setIndex(3);
    
}

void Calendar::seeCalendarShell() // see calendar
{
    
    PrintBigNumbers(year);
    
    setMonth(year);
    
    makeLine();
    
    // --------------------- FORMULA OF "COUT"--------------------------------
    // [len of MONTH] + [SPACES] << NAME OF MONTH << [SPACES] - [len of MONTH]
    
    cout << setw((int)month[0].getName().size()+2) << month[0].getName() << setw(28-(int)month[0].getName().size()) << "|";
    cout << setw((int)month[1].getName().size()+2) << month[1].getName() << setw(28-(int)month[1].getName().size()) << "|";
    cout << setw((int)month[2].getName().size()+2) << month[2].getName() << setw(28-(int)month[2].getName().size()) << "|";
    cout << setw((int)month[3].getName().size()+2) << month[3].getName() << setw(28-(int)month[3].getName().size()) << "|";
    cout << endl;
    
    makeLine();
    
    printDays(0);
 
    makeLine();
    
    // --------------------- FORMULA OF "COUT"--------------------------------
    // [len of MONTH] + [SPACES] << NAME OF MONTH << [SPACES] - [len of MONTH]
    
    cout << setw((int)month[4].getName().size()+2) << month[4].getName() << setw(28-(int)month[4].getName().size()) << "|";
    cout << setw((int)month[5].getName().size()+2) << month[5].getName() << setw(28-(int)month[5].getName().size()) << "|";
    cout << setw((int)month[6].getName().size()+2) << month[6].getName() << setw(28-(int)month[6].getName().size()) << "|";
    cout << setw((int)month[7].getName().size()+2) << month[7].getName() << setw(28-(int)month[7].getName().size()) << "|";
    cout << endl;
    
    makeLine();
    
    printDays(4);
    
    makeLine();
    
    // --------------------- FORMULA OF "COUT"--------------------------------
    // [len of MONTH] + [SPACES] << NAME OF MONTH << [SPACES] - [len of MONTH]
    
    cout << setw((int)month[8].getName().size()+2) << month[8].getName() << setw(28-(int)month[8].getName().size()) << "|";
    cout << setw((int)month[9].getName().size()+2) << month[9].getName() << setw(28-(int)month[9].getName().size()) << "|";
    cout << setw((int)month[10].getName().size()+2) << month[10].getName() << setw(28-(int)month[10].getName().size()) << "|";
    cout << setw((int)month[11].getName().size()+2) << month[11].getName() << setw(28-(int)month[11].getName().size()) << "|";
    cout << endl;
    
    makeLine();
    
    printDays(8);
    
    makeLine();
  
}

Calendar& Calendar::operator++() // + 1 to year
{
    year++;
    return *this;
}

Calendar& Calendar::operator--() // -1 from year
{
    year--;
    return *this;
}

Calendar::~Calendar()
{
    
}


