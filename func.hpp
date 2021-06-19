//
//  func.hpp
//  AsciiCalendar
//
//  Created by Павло Коваль on 06.06.2021.
//

#ifndef func_hpp
#define func_hpp

#include <iostream>
#include <iomanip>

using namespace std;

int countDigets(int number);
void makeLine(); // make line of '-'
void PrintBigNumbers(int number); // makes big number
void splitNumber(int number, vector<int>& array); // split number in an array

#endif /* func_hpp */
