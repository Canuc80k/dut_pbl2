#pragma once
#include "Calendar.h"
#include <fstream>
#include <iostream>
using namespace std;

Calendar::Calendar(int month, int year) {
    this->month = month;
    this->year = year;
}

int Calendar::getDay(int date, int month, int year) {
    int monthc, yearc, centuryc, centuryx, lyearc, day;
    switch (month) {
        case 1: {monthc = 0; break;}
        case 2: {monthc = 1; break;}
        case 3: {monthc = 3; break;}
        case 4: {monthc = 6; break;}
        case 5: {monthc = 1; break;}
        case 6: {monthc = 4; break;}
        case 7: {monthc = 6; break;}
        case 8: {monthc = 2; break;}
        case 9: {monthc = 5; break;}
        case 10: {monthc = 0; break;}
        case 11: {monthc = 3; break;}
        case 12: {monthc = 5; break;}
    }

    yearc = (year + (year / 4)) % 7;
    centuryx = (year - (year % 100));

    switch (centuryx) {
        case 1700: {centuryc = 4; break;}
        case 1800: {centuryc = 2; break;}
        case 1900: {centuryc = 0; break;}
        case 2000: {centuryc = 6; break;}
        case 2100: {centuryc = 4; break;}
        case 2200: {centuryc = 8; break;}
        case 2300: {centuryc = 0; break;}
    }

    lyearc = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0))
        if (month == 1 || month == 2)
            lyearc = 1;

    day = (yearc - lyearc + date + monthc + centuryc) % 7;
    return day;
}

int Calendar::getMonth() {return this->month;}
int Calendar::getYear() {return this->year;}
void Calendar::setMonth(int month) {this->month = month;}
void Calendar::setYear(int year) {this->year = year;}