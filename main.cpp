//
//  main.cpp
//  AsciiCalendar
//
//  Created by losirise on 05.06.2021.
//

#include "CCalendar.hpp"
#include "colormod.hpp"

int main()
{
    
    Calendar calendar;

    int choice;

    while (true)
    {
        system("clear");
        std::cout << std::endl << std::endl;

        calendar.seeCalendarShell();

        cout << endl;
        cout << "<-1 Move back" << setw(107) << "Move forward 2->";
        cout << endl;

        cin >> choice;

        if (choice == 1)
        {
            calendar.operator--();
        }

        else if (choice == 2)
        {
            calendar.operator++();
        }

        else if (choice == 0)
        {
            break;
        }

    }


    std::cout << std::endl;
    
    return 0;
}
