/* 
 * File:   date.cpp
 * Author: Max Collins
 * S_ID: 2132622
 * FAN: coll0428
 * 
 * Created on 7 March 2015, 9:26 AM
 */

#include "Date.h"

/**
 * Creates a Date for the given day, month, and year.
 * 
 * @param day the day
 * @param month the month
 * @param year the year
 */
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

/**
 * Gets the day of this Date
 * 
 * @return the day
 */
int Date::getDay() {
    return this->day;
}

/**
 * Sets the day of this Date
 * 
 * @param day the day
 */
void Date::setDay(int day) {
    this->day = day;
}

/**
 * Gets the month of this Date
 * 
 * @return the month
 */
int Date::getMonth() {
    return this->month;
}

/**
 * Sets the month of this Date
 * 
 * @param month the month
 */
void Date::setMonth(int month) {
    this->month = month;
}

/**
 * Gets the year of this Date
 * 
 * @return the year
 */
int Date::getYear() {
    return this->year;
}

/**
 * Sets the year of this Date
 * 
 * @param year the year
 */
void Date::setYear(int year) {
    this->year = year;
}

/**
 * Returns true if this Date represents a leap year
 * 
 * @return true if leap year
 */
bool Date::isLeapYear() {
    if (this->year > 1752) {
        // Valid for dates after the change to the Gregorian calendar
        return this->year % 400 == 0 || this->year % 100 != 0 && this->year % 4 == 0;
    } else {
        return this->year % 4 == 0;
        //valid for dates prior to the Gregorian change
    }
}

/**
 * Returns the number of days in this Date's month
 * 
 * @return the number of days in the month
 */
int Date::daysInMonth() {
    // "30 days hath September ... "
    switch (this->month) {
        case 9:
        case 4:
        case 6:
        case 11:
            return 30;
        default:
            return 31;
        case 2:
            return this->isLeapYear() ? 29 : 28;
    }
}

/**
 * Advances this Date by one day
 */
void Date::advance() {
    this->day++;

    if (this->day > this->daysInMonth()) {
        this->day = 1;
        this->month++;
    }
    if (this->month > 12) {
        this->month = 1;
        this->year++;
    }
    //Gregorian Switchover
    if (this->day == 3 && this->month == 9 && this->year == 1752) {
        this->day = 14;
    }
}

/**
 * Returns true if this Date precedes date
 * 
 * @return true if this precedes date
 */
bool Date::precedes(Date date) {
    return this->year < date.getYear()
            || this->year == date.getYear() && this->month < date.getMonth()
            || this->year == date.getYear() && this->month == date.getMonth() && this->day < date.getDay();
}


