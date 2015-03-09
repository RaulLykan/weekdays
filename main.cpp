/* 
 * File:   main.cpp
 * Author: Max Collins
 * S_ID: 2132622
 * FAN: coll0428
 *
 * Created on 7 March 2015, 9:03 AM
 */

#include <cstdlib>
#include "Date.h"
#include <iostream>

using namespace std;

const string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"};

/**
 * Returns the weekday on which date falls
 * 
 * @param date the Date
 * @return a String naming the day
 */
string weekday(Date date) {

    Date trial(1, 1, 1); // CE beginning
    int weekday = 6; // ... on a Saturday        

    if (date.precedes(trial)) {
        return "Mysteryday";
    } else {
        // Simple but inefficient: count every day!
        while (trial.precedes(date)) {
            trial.advance();
            weekday = (weekday + 1) % 7;
        }
        return days[weekday];
    }
}

int main(int argc, char** argv) {

    //cout << "What date (d m y)? ";
    while (!cin.eof()) {
        int day, month, year;
        string eventString;
        cin >> day >> month >> year;

        std::getline(std::cin, eventString);
        Date event(day, month, year);
        eventString.erase(0, 1);
        cout << eventString << " on a " << weekday(event) << endl;
    }
    return 0;
}


