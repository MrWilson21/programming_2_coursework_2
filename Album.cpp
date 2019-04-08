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
    //Strings for title, separating character, artist and the temporary test string
    string seperator;
    string artist;
    string title;
    string test;

    //Current line and input stream for current line
    string curLine;
    istringstream iss;

    //Get the first line to try to make an album with
    getline(is, curLine);
    iss = istringstream(curLine);

    //While there are still strings in the first line
    while (iss >> test) {
        //If seperator character has not been set yet
        if (!seperator.compare(":") == 0) {
            //If current string is the separating character then set the seperator
            if (test.compare(":") == 0) {
                seperator = test;
            }
            //If not then append test word to the artist string
            else {
                if(artist.empty()){
                    artist = test;
                }
                else{
                    artist += " " + test;
                }

            }
        }
        //If separating character already set then append the test word to the title
        else {
            if(title.empty()){
                title = test;
            }
            else{
                title += " " + test;
            }
        }
    }

    //After artist and title set, get tracks to add line by line
    //Tracks array
    vector<Track> tracks;
    //Current track
    Track curTrack;
    //Boolean to stop reading tracks at end of album
    bool readingTracks = true;
    //Line for input stream to return to once there are no more tracks to read
    int previousLine;

    while(readingTracks){
        //Set line to return to if fail
        previousLine = is.tellg();
        //Get one line and convert to an input stream to create track object from
        getline(is, curLine);
        iss = istringstream(curLine);

        //Try to create track and add it to track vector
        if(iss >> curTrack){
            tracks.push_back(curTrack);
        }
        //If failed then there are no more tracks to read so stop reading tracks and return input stream to previous line
        else
        {
            readingTracks = false;
            is.seekg(previousLine);
        }
    }

    //Check if album was read in properly by comparing seperator to its expected value before creating object
    if (seperator.compare(":") == 0) {
        album = Album(artist, title, tracks);
    }
    //If failed then set fail bit of input stream
    else {
        is.clear(ios_base::failbit);
    }

    return is;
}

//Unit test
void Album::testMethod() {
    cout << "Test creating album from input stream\n";
    Album a;
    ifstream is("albums.txt", ifstream::in);
    if (is >> a){
        cout << a << "\n";
    }
    else{
        cout << "fail\n";
    }
}



