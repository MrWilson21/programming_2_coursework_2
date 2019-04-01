//
// Created by harry on 01/04/2019.
//

#include <iostream>
#include "Duration.h"

using namespace std;

//Constructor normalises duration after creating it to ensure seconds and minutes are not greater than 59
Duration::Duration(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->normalise();
}

Duration::Duration() {}

int Duration::getSeconds() const {
    return seconds;
}

void Duration::setSeconds(int seconds) {
    Duration::seconds = seconds;
}

int Duration::getMinutes() const {
    return minutes;
}

void Duration::setMinutes(int minutes) {
    Duration::minutes = minutes;
}

int Duration::getHours() const {
    return hours;
}

void Duration::setHours(int hours) {
    Duration::hours = hours;
}

// < operator
//Checks if hours are less than or greater than and returns true or false respectively
//If hours is neither greater or smaller then do the same check for minutes and then finally seconds
bool Duration::operator<(const Duration &rhs) const {
    //Check hours
    if (hours < rhs.hours)
        return true;
    if (rhs.hours < hours)
        return false;
    //Check minutes if not already returned
    if (minutes < rhs.minutes)
        return true;
    if (rhs.minutes < minutes)
        return false;
    //Check seconds if not already returned
    return seconds < rhs.seconds;
}

// > Operator uses same behaviour of < operator but reverses order of lhs and rhs
bool Duration::operator>(const Duration &rhs) const {
    return rhs < *this;
}

// > Operator uses same behaviour of < operator
//Checks if rhs is not less than lhs which would imply lhs is less than or greater than rhs
bool Duration::operator<=(const Duration &rhs) const {
    return !(rhs < *this);
}

// > Operator uses same behaviour of < operator
//Checks if lhs is not less than rhs which would imply rhs is less than or greater than lhs
bool Duration::operator>=(const Duration &rhs) const {
    return !(*this < rhs);
}

//output stream operator
//Takes a constant duration and non constant output stream
ostream &operator<<(ostream &os, const Duration &duration) {
    os.fill('0');

    os.width(2);
    os << duration.hours << ':';
    os.width(2);
    os << duration.minutes << ':';
    os.width(2);
    os << duration.seconds;
    return os;
}

//Input stream operator
//Takes an input of the form "integer:integer:integer"
//Takes a non constant duration and non constant input stream
istream &operator>>(istream &is, Duration &duration) {
    char c1;
    char c2;
    int hours, minutes, seconds;

    if (is >> seconds >> c1 >> minutes >> c2 >> hours) {
        //Check if chars between numbers are : before calling constructor
        if (c1 == ':' && c2 == ':') {
            duration = Duration(hours, minutes, seconds);
        }
        //If failed then set fail bit of input stream
        else {
            is.clear(ios_base::failbit);
        }
    }
    //Return input stream for error checking
    return is;
}

void Duration::normalise() {
    //Add the division of seconds by 60 to minutes and set seconds to the remainder of the division
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds = seconds % 60;
    }
    //Add the division of minutes by 60 to hours and set minutes to the remainder of the division
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes = minutes % 60;
    }
}

//Unit test
void Duration::testMethod() {
    Duration d1;
    cout << "Test creating and outputting duration with stream input and output\n";
    cout << "input duration: ";
    while (!(cin >> d1)) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "input not recognised, please input duration:";
    }
    cout << "\n" << d1 << "\n";

    cout << "\nTest creating duration with more than 60 seconds and minutes and outputting\n";
    cout << "Input duration of 0:67:101\n";
    Duration d2 = Duration(0, 67, 101);
    cout << "output duration of " << d2 << "\n";

    cout << "\nTest relational operators\n";
    cout << "Testing 01:03:06 on the lhs and 01:08:41 on the rhs\n";
    Duration d3 = Duration(1, 3, 6);
    bool test = d3 > d2;
    cout << "> operator: " << test << "\n";
    test = d3 < d2;
    cout << "< operator: " << test << "\n";
    test = d3 >= d2;
    cout << ">= operator: " << test << "\n";
    test = d3 <= d2;
    cout << "<= operator: " << test << "\n";

    cout << "\nTesting 01:03:06 on the lhs and 01:03:06 on the rhs\n";
    test = d3 > d3;
    cout << "> operator: " << test << "\n";
    test = d3 < d3;
    cout << "< operator: " << test << "\n";
    test = d3 >= d3;
    cout << ">= operator: " << test << "\n";
    test = d3 <= d3;
    cout << "<= operator: " << test << "\n";
}
