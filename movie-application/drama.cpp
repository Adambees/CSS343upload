/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// drama.cpp
// key: D
// sort Director then title
*/

#include "drama.h"

// =============Constructor===================
Drama::Drama(const string& str) {
    toString(str);
}
// copy constructor
Drama::Drama(const string& t, const string& d) {
    title = t;
    director = d;
}
// =============End of Constructor============

// =============Deconstructor=================
Drama::~Drama() {}
// empty
// =============End of Deconstructor==========

// =============Print Function================
// print format: type stock director, title, and year
// convert format of string then return
string Drama::dataOutput() const {
    ostringstream os;
    os << TYPE << ", " << stock << ", " << director << ", "
    << title << ", " << year << endl;
    return os.str();
}
// print for history customer
// convert the format to string then return
string Drama::dataOutputForCustomer() const {
    ostringstream os;
    os << DVD << ", " << TYPE << ", " << director << ", " << title;
    os << ", " << year;
    return os.str();
}
// =============End of Print Function=========

// =============Compare Check=================
// compare current movie obj with other movie obj
// Drama compare Director then title
// Check if the director and title is equal
// return type boolean
bool Drama::isEqual(const Movie* m) const {
    const Drama* dramaPtr = (const Drama*)m;
    return ((title == dramaPtr->title) && (director == dramaPtr->director));
}
// Compare current Movie obj with other movie obj
// Drama compare Director then title
// return type boolean
bool Drama::compareMovie(const Movie* m) const {
    const Drama* dramaPtr = (const Drama*)m;
    return ((director > dramaPtr->director) || ((director == dramaPtr->director)
    && (title > dramaPtr->title)));
}
// =============End of Compare================
