//
// Created by harry on 01/04/2019.
//

#ifndef PROGRAMMING_2_COURSEWORK_2_DURATION_H
#define PROGRAMMING_2_COURSEWORK_2_DURATION_H

#include <iostream>
#include <sstream>

using namespace std;

class Duration {
public:
    //Constructor with filled parameters
    Duration(int hours, int minutes, int seconds);

    //Default constructor
    Duration();

    //Getters
    int getSeconds() const;

    int getMinutes() const;

    int getHours() const;

    //Setters
    void setSeconds(int seconds);

    void setMinutes(int minutes);

    void setHours(int hours);

    //Input and output stream operator overloads
    friend ostream &operator<<(ostream &os, const Duration &duration);

    friend istream &operator>>(istream &is, Duration &duration);

    //Relational operator overloads
    bool operator<(const Duration &rhs) const;

    bool operator>(const Duration &rhs) const;

    bool operator<=(const Duration &rhs) const;

    bool operator>=(const Duration &rhs) const;

    //Equality operator overloads
    bool operator==(const Duration &rhs) const;

    bool operator!=(const Duration &rhs) const;

    // + and - operator overloads
    Duration operator+(const Duration &rhs) const;

    Duration operator-(const Duration &rhs) const;

    //Unit test for class
    static void testMethod();

private:
    //Ensure that duration has no more than 59 seconds or 59 minutes and no less than -59 seconds or -59 minutes
    //by converting minutes into hours and seconds into minutes
    void normalise();

    //Instance attributes
    int seconds;
    int minutes;
    int hours;
};

#endif //PROGRAMMING_2_COURSEWORK_2_DURATION_H
