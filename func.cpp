//
//  func.cpp
//  AsciiCalendar
//
//  Created by losirise on 06.06.2021.
//

#include "func.hpp"
#include <iomanip>
#include <vector>


int countDigets(int number)
{
    int counter = 0;
    
    while(number)
    {
        number /= 10;
        counter++;
    }
    
    return counter;
}

void makeLine()  // make line of '-'
{
    for (int i = 0; i < 4; i++)
    {
        cout << setfill('-') << setw(30) << "|";
    }
    
    cout << setfill(' ');
    
    cout << endl;
}

void PrintBigNumbers(int number) // makes big number
{
    
    vector<int> array;
    int counter = 0;
    
    splitNumber(number, array);
    
    while (counter != 5)
    {
        for(vector<int>::iterator it = array.begin(); it != array.end(); it++)
        {
            if (*it == 0)
            {
                if (counter == 0)
                {
                    cout <<  " 0000   ";
                }
                
                else if (counter < 4)
                {
                    cout << "00  00  ";
                }
                
                else
                {
                    cout << " 0000   ";
                }
            }
            
            else if (*it == 1)
            {
                if (counter == 0)
                {
                    cout <<  "1111    ";
                }
                
                else if (counter < 4)
                {
                    cout << "  11    ";
                }
                
                else
                {
                    cout << "111111  ";
                }
            }
            
            else if (*it == 2)
            {
                if (counter == 0)
                {
                    cout << " 2222   ";
                }
                
                else if (counter == 1)
                {
                    cout << "22  22  ";
                }
                
                else if (counter == 2)
                {
                    cout << "   22   ";
                }
                
                else if (counter == 3)
                {
                    cout << "  22    ";
                }
                
                else if (counter == 4)
                {
                    cout << "222222  ";
                }
            
            }
            
            else if (*it == 3)
            {
                if (counter == 0 || counter == 4)
                {
                    cout << " 3333   ";
                }
                
                else if (counter % 2 != 0)
                {
                    cout << "33  33  ";
                }
                
                else if (counter == 2)
                {
                    cout << "   333   ";
                }
                
            }
            
            else if (*it == 4)
            {
                if (counter <= 1)
                {
                    cout << "44  44  ";
                }
                
                else if (counter == 2)
                {
                    cout << "444444  ";
                }
                
                else if (counter >= 3)
                {
                    cout << "    44  ";
                }
            
            }
            
            else if (*it == 5)
            {
                if (counter == 0)
                {
                    cout << "555555  ";
                }
                
                else if (counter == 1)
                {
                    cout << "55      ";
                }
                
                else if (counter == 2)
                {
                    cout << "55555   ";
                }
                
                else if (counter == 3)
                {
                    cout << "    55  ";
                }
                
                else if (counter == 4)
                {
                    cout << "55555   ";
                }
            }
            
            else if (*it == 6)
            {
                if (counter == 0)
                {
                    cout << " 6666   ";
                }
                
                else if (counter == 1)
                {
                    cout << "66      ";
                }
                
                else if (counter == 2)
                {
                    cout << "66666   ";
                }
                
                else if (counter == 3)
                {
                    cout << "66  66  ";
                }
                
                else if (counter == 4)
                {
                    cout << " 6666   ";
                }
                
            }
            
            else if (*it == 7)
            {
                if (counter == 0)
                {
                    cout << "777777  ";
                }
                
                else if (counter == 1)
                {
                    cout << "   77   ";
                }
                
                else if (counter == 2)
                {
                    cout << "  77    ";
                }
                
                else if (counter == 3)
                {
                    cout << " 77     ";
                }
                
                else if (counter == 4)
                {
                    cout << "77      ";
                }
                
            }
            
            else if (*it == 8)
            {
                if (counter % 2 == 0)
                {
                    cout << " 8888   ";
                }
                
                else if (counter % 2 != 0)
                {
                    cout << "88  88  ";
                }
            }
            
            else if (*it == 9)
            {
                if (counter == 0)
                {
                    cout << " 9999   ";
                }
                
                else if (counter == 1)
                {
                    cout << "99  99  ";
                }
                
                else if (counter == 2)
                {
                    cout << " 99999  ";
                }
                
                else if (counter == 3)
                {
                    cout << "    99  ";
                }
                
                else if (counter == 4)
                {
                    cout << " 9999   ";
                }
            }
        }
        
        counter++;
        cout << endl;

        
    }
    
    
    
}

void splitNumber(int number, vector<int>& array) // split number in an array
{
    array.resize(countDigets(number));
    
    for (int i = 0; i <= array.size(); i++)
    {
        array[i] = number % 10;
        number /= 10;
    }
    
    reverse(array.begin(), array.end());
}
