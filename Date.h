/* 
 * File:   date.h
 * Author: Max Collins
 * S_ID: 2132622
 * FAN: coll0428
 *
 * Created on 7 March 2015, 9:26 AM
 */

#ifndef DATE_H
#define	DATE_H

class Date {
public:
    Date(int day, int month, int year);

    int getDay();

    void setDay(int day);

    int getMonth();

    void setMonth(int month);

    int getYear();

    void setYear(int year);

    bool isLeapYear();

    int daysInMonth();

    void advance();

    bool precedes(Date date);

private:
    int day;
    int month;
    int year;
};

#endif	/* DATE_H */

