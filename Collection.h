//
// Created by harry on 08/04/2019.
//

#ifndef PROGRAMMING_2_COURSEWORK_2_COLLECTION_H
#define PROGRAMMING_2_COURSEWORK_2_COLLECTION_H

#include "Album.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

class Collection {
public:
    //Constructor with filled parameters
    Collection(const vector<Album *> &albums);

    //Default constructor
    Collection();

    //Input and output stream operator overloads
    friend ostream &operator<<(ostream &os, const Collection &collection);

    friend istream &operator>>(istream &is, Collection &collection);

    //Getter
    const vector<Album *> &getAlbums() const;

    //Setter
    void setAlbums(const vector<Album *> &albums);

    void sortAlbums();

    static void testMethod();

private:
    //Instance attributes
    vector<Album *> albums;
};


#endif //PROGRAMMING_2_COURSEWORK_2_COLLECTION_H
