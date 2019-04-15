#include <iostream>
#include <algorithm>
#include "Duration.h"
#include "Track.h"
#include "Album.h"
#include "collection.h"

using namespace std;

int main() {
    //Unit test calls for each class
    //Duration::testMethod();
    //Track::testMethod();
    //Album::testMethod();
    Collection::testMethod();

    cout << "Read in collection from albums.txt\n";
    Collection c;
    //Open file to load
    ifstream is("albums.txt", ifstream::in);
    if (is >> c) {
        //Success if collection can be loaded in
        cout << "Load success\n\n";
    }
    else{
        //Exit if load failed
        cout << "Failed to load collection";
        return EXIT_FAILURE;
    }

    cout << "Display collection in alphabetical order\n";
    //Sort using album < operator
    c.sortAlbums();
    cout << c << "\n\n";

    cout << "Display total play time of all Pink Floyd albums\n";
    vector<Album*> albums = c.getAlbums();
    Duration totalPinkFloydDuration = Duration(0, 0, 0);

    //For each album
    for(Album* a : albums){
        //If artist is Pink Floyd then add album duration to total
        if(a->getArtist() == "Pink Floyd"){
            for (Track t : a->getTracks()) {
                totalPinkFloydDuration = totalPinkFloydDuration + t.getDuration();
            }
        }
    }
    cout << totalPinkFloydDuration << "\n\n";

    cout << "Display album with largest number of tracks\n";
    //Initialise longest album to first in list
    Album* largestAlbum = albums[0];
    //For each album check if size of track list is greater than largest album track list
    for(Album* a : albums)
    {
        //If greater then replace largest album with new one
        if(a->getTracks().size() > largestAlbum->getTracks().size()){
            largestAlbum = a;
        }
    }
    cout << *largestAlbum << "\n\n";

    cout << "Display the details of the longest track in the collection\n";
    //Initialise longest track to first track of first album
    Track longestTrack = albums[0]->getTracks()[0];
    //For each album
    for(Album* a : albums){
        //For each track in album
        for (Track t : a->getTracks()) {
            //If track is longer than longest track then replace longest track with new one
            if(t.getDuration() > longestTrack.getDuration()){
                longestTrack = t;
            }
        }
    }
    cout << longestTrack << "\n\n";

    return EXIT_SUCCESS;
}