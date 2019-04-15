//
// Created by harry on 01/04/2019.
//

#ifndef PROGRAMMING_2_COURSEWORK_2_ALBUM_H
#define PROGRAMMING_2_COURSEWORK_2_ALBUM_H

#include "Track.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class Album {
public:
    //Constructor with filled parameters
    Album(const string &artist, const string &title, const vector<Track> &tracks);

    //Constructor with just artist and title parameters
    Album(const string &artist, const string &title);

    //Default constructor
    Album();

    //Getters
    const string &getArtist() const;

    const string &getTitle() const;

    const vector<Track> &getTracks() const;

    //Setters
    void setArtist(const string &artist);

    void setTitle(const string &title);

    void setTracks(const vector<Track> &tracks);

    //Input and output stream operator overloads
    friend ostream &operator<<(ostream &os, const Album &album);

    friend istream &operator>>(istream &is, Album &album);


    bool operator<(const Album &rhs) const;

    //Unit test for class
    static void testMethod();

private:
    //Instance attributes
    string artist;
    string title;
    vector<Track> tracks;

    //Method to convert ascii strings to lowercase
    //Used in comparator method
    string stringToLower(string s) const;
};


#endif //PROGRAMMING_2_COURSEWORK_2_ALBUM_H
