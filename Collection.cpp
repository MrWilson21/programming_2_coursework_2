//
// Created by harry on 08/04/2019.
//

#include "Collection.h"

//Default constructor
Collection::Collection() {}

//Constructor with album pointers vector as a parameter
Collection::Collection(const vector<Album *> &albums) : albums(albums) {}

//Output stream operator
//Outputs every album in collection in the form "album + \n + album + \n +... + album"
ostream &operator<<(ostream &os, const Collection &collection) {
    if (collection.albums.size() > 0) {
        os << *collection.albums[0];
        for (int i = 1; i < collection.albums.size(); i++) {
            os << "\n" << *collection.albums[i];
        }
    }
    return os;
}

//Input stream operator
istream &operator>>(istream &is, Collection &collection) {
    //vector of album pointers to create collection object with
    vector<Album *> albums;
    //Current album being read in
    Album *curAlbum = new Album();

    //While there are albums to read in, add them to the album list
    while (is >> *curAlbum) {
        albums.push_back(curAlbum);
        curAlbum = new Album();
    }

    //Once all albums are read in create a collection object if there are any albums
    if (albums.size() > 0) {
        collection = Collection(albums);
        //Error bits triggered when end of file is reached so error bits should be cleared if some albums were loaded
        is.clear();

    }
        //If no albums loaded then an error is triggered
    else {
        is.clear(ios_base::failbit);
    }

    return is;
}

const vector<Album *> &Collection::getAlbums() const {
    return albums;
}

void Collection::setAlbums(const vector<Album *> &albums) {
    Collection::albums = albums;
}

void Collection::sortAlbums() {
    sort(albums.begin(), albums.end(), compareAlbumPointers);
}

bool Collection::compareAlbumPointers(Album *a, Album *b) {
    return (*a < *b);
}

//Unit test
void Collection::testMethod() {
    cout << "Test creating collection from input stream\n";
    Collection c;
    ifstream is("albums.txt", ifstream::in);
    if (is >> c) {
        cout << c << "\n";
    } else {
        cout << "fail\n";
    }
}

