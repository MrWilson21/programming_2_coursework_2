//
// Created by harry on 01/04/2019.
//

#include "Track.h"

using namespace std;

//Constructor with filled parameters
Track::Track(const Duration &duration, const string &title) : duration(duration), title(title) {}

//Default constructor
Track::Track() = default;

const Duration &Track::getDuration() const {
    return duration;
}

void Track::setDuration(const Duration &duration) {
    Track::duration = duration;
}

const string &Track::getTitle() const {
    return title;
}

void Track::setTitle(const string &title) {
    Track::title = title;
}

//Output stream
//Outputs in form "duration - title"
ostream &operator<<(ostream &os, const Track &track) {
    os << track.duration << " - " << track.title;
    return os;
}

//Input stream
//Takes input in form "duration - title"
istream &operator>>(istream &is, Track &track) {
    char seperator;
    string title;
    Duration duration;

    if (is >> duration >> seperator >> title) {
        //Check if string between duration and title is "-" to make a valid track
        if (seperator == '-') {
            string test;
            //If title has more than 1 word then each word must be added to title
            while (is >> test) {
                title += " " + test;
            }
            //Clear fail bit as it will eventually be set when there are no more title words to append
            is.clear();
            track = Track(duration, title);
        }
            //If failed then set fail bit of input stream
        else {
            is.clear(ios_base::failbit);
        }
    }
    //Return input stream for error checking
    return is;
}

//Compare tracks by title
struct Track::titleComparator {
    // Compare 2 Track objects using title
    int operator()(const Track &t1, const Track &t2) {
        return t1.title.compare(t2.title);
    }
};

//Compare track by duration in ascending order
struct Track::durationComparator {
    // Compare 2 Track objects using title
    int operator()(const Track &t1, const Track &t2) {
        if (t1.duration == t2.duration)
            return 0;
        return t1.duration < t2.duration;
    }
};

//Unit test
void Track::testMethod() {
    Track t1;
    cout << "Test creating and outputting track with stream input and output\n";
    cout << "input track: 00:03:45 - track name";
    istringstream iss = istringstream("00:03:45 - track name");
    if (!(iss >> t1)) {
        cout << "failed to read in track";
        return;
    }
    cout << "\n" << t1 << "\n";

    Track t2 = Track(Duration(1, 2, 3), "abcde");
    Track t3 = Track(Duration(6, 5, 4), "qwerty");
    cout << "\nTest comparators\n";
    Track::titleComparator comparator1;
    cout << "compare title of abcde on lhs with qwerty on rhs\n";
    cout << comparator1(t2, t3) << "\n";
    cout << "compare title of abcde on lhs with abcde on rhs\n";
    cout << comparator1(t2, t2) << "\n";
    Track::durationComparator comparator2;
    cout << "compare duration of 01:02:03 on lhs with 06:05:04 on rhs\n";
    cout << comparator2(t2, t3) << "\n";
    cout << "compare duration of 01:02:03 on lhs with 01:02:03 on rhs\n";
    cout << comparator2(t2, t2) << "\n";
}
