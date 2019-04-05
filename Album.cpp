//
// Created by harry on 01/04/2019.
//

#include "Album.h"

using namespace std;

//Constructor with filled parameters
Album::Album(const string &artist, const string &title, const vector<Track> &tracks) : artist(artist), title(title),
                                                                                       tracks(tracks) {}

//Constructor which takes only title and artist name
Album::Album(const string &artist, const string &title) : artist(artist), title(title) {}

//Default constructor
Album::Album() = default;

const string &Album::getArtist() const {
    return artist;
}

void Album::setArtist(const string &artist) {
    Album::artist = artist;
}

const string &Album::getTitle() const {
    return title;
}

void Album::setTitle(const string &title) {
    Album::title = title;
}

const vector<Track> &Album::getTracks() const {
    return tracks;
}

void Album::setTracks(const vector<Track> &tracks) {
    Album::tracks = tracks;
}

//Output stream operator
//Outputs in the form "artist : album title" then "\n" + "track" for every track
ostream &operator<<(ostream &os, const Album &album) {
    os << album.artist << " : " << album.title;
    for (Track t : album.tracks) {
        os << "\n" << t;
    }
    return os;
}

//Input stream
//Takes input in form "artist : album title" then "\n" + "track" for every track
istream &operator>>(istream &is, Album &album) {
    string seperator;
    string artist;
    string title;
    string test;

    /*if (is >> artist >> seperator >> title) {
        //Check if string between duration and title is "-" before calling constructor
        if (seperator == '-') {
            album = Album(artist, title);
        }
            //If failed then set fail bit of input stream
        else {
            is.clear(ios_base::failbit);
        }
    }
    //Return input stream for error checking
    return is;*/

    while (is >> test) {
        if (!seperator.compare(":") == 0) {
            if (test.compare(":") == 0) {
                seperator = test;
            } else {
                title = title + test;
            }
        } else {
            title = title + test;
        }
    }
    if (seperator.compare(":") == 0) {
        album = Album(artist, title);
        //cout << album << "\n\n";
    }
    //If failed then set fail bit of input stream
    else {
        is.clear(ios_base::failbit);
    }
    //Return input stream for error checking
    return is;
}

void Album::testMethod() {
    Album a;
    istringstream iss;
    string s;
    ifstream is("C:\\Users\\harry\\CLionProjects\\programming-2-coursework-2\\albums.txt", ifstream::in);
    while (is) {
        getline(is, s);
        iss = istringstream(s);
        if (iss >> a) {
            cout << a;
        }
        else
        {
            cout << "fail\n";
        }
    }
}



