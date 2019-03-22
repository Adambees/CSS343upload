/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Comedy cpp
// Key: F
// Sort By Title, Year
*/

#include "comedy.h"

// ==========Constructor ===================
Comedy::Comedy(const string& s) {
    toString(s);
}
// copy constructor
Comedy::Comedy(const string& t, const int& yr) {
    title = t;
    year = yr;
}
// ==========End of Constructor=============

// ==========Deconstructor==================
Comedy::~Comedy() {}
// empty
// ==========End of Deconstructor===========

// ==========Print Functions================
// format of key, stock, director title and year
// all movie data compose to string
string Comedy::dataOutput() const {
    ostringstream os;
    os << TYPE << ", " << stock << ", " << director << ", " << title << ", "
    << year << endl;
    return os.str();
}
// convert all customer data to string
// return string
string Comedy::dataOutputForCustomer() const {
    ostringstream os;
    os << DVD << ", " << TYPE << ", " << title << ", " << director << ", "
    << year;
    return os.str();
}
// =============End of Print================
// isEqual as operator==
// compare movie obj(current) with other movie obj
// take one param pointer movie
// compare title and year
bool Comedy::isEqual(const Movie* m) const {
    const Comedy* comedyPtr = (const Comedy*)m;
    return ((title == comedyPtr->title) && (year == comedyPtr->year));
}
// operator >=
// compare movieObj with other movie obj
// take one param of movie pointer
// compare the title first
// then compare year
bool Comedy::compareMovie(const Movie* m) const {
    const Comedy* comedyPtr = (const Comedy*)m;
    return ((title > comedyPtr->title) || ((title == comedyPtr->title)
    && (year > comedyPtr->year)));
}
// =============End of Compare==============
