//
// Created by harry on 01/04/2019.
//

#ifndef PROGRAMMING_2_COURSEWORK_2_TRACK_H
#define PROGRAMMING_2_COURSEWORK_2_TRACK_H

#include "Duration.h"
#include <iostream>
#include <string>

using namespace std;

class Track {
public:
    //Default constructor
    Track();

    Track(const Duration &duration, const string &title);

    //Getters
    const Duration &getDuration() const;

    const string &getTitle() const;

    //Setters
    void setDuration(const Duration &duration);

    void setTitle(const string &title);

    //Input and output steam operator overloads
    friend ostream &operator<<(ostream &os, const Track &track);

    friend istream &operator>>(istream &is, Track &track);

    //Unit test for class
    static void testMethod();

    //Comparators for comparing tracks using titles and durations
    struct titleComparator;
    struct durationComparator;

private:
    //Instance attributes
    Duration duration;
    string title;
};


#endif //PROGRAMMING_2_COURSEWORK_2_TRACK_H
