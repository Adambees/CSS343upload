/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Classic cpp
// Key: C
// Sort By Release Date and Major Actor
*/
#include "classic.h"

// =================Constructor=======================
// Constructor
Classics::Classics(const string& s) {
    toString(s);
}
// Copy constructor
Classics::Classics(const string& actor, const int& m, const int& yr) {
    mainActor = actor;
    month = m;
    year = yr;
}
// =================End of Constructor================

// =================Deconstructor=====================
// Deconstructor
Classics::~Classics() {}
// empty
// =================End of Deconstructor==============

// =================Print Data Functions==============
// String type
// Convert all the data for movie into string
// format as Key stock director title
// main actor and month year
string Classics::dataOutput() const {
    ostringstream os;
    os << TYPE << ", " << stock << ", " << director << ", " << title << ", "
    << mainActor << ", " << month << ", " << year << endl;
    return os.str();
}
// for customer
// same as dataOutput
// String type
// Convert all the data for customer into string
string Classics::dataOutputForCustomer() const {
    ostringstream os;
    os << DVD << ", " << TYPE << ", " << director << ", "
       << title << ", " << mainActor << ", "
       << month << ", " << year;
    return os.str();
}
// =================End of Print Data Functions=======

// =================Helper Function for Constructor===
// parameter (string that reference data)
// separate the data into small data
// assign data to movie
void Classics::toString(const string& m_data) {
    stringstream ss;
    ss << m_data;
    string s;
    getline(ss, s, ',');
    key = s[0];
    getline(ss, s, ',');
    stringstream(s) >> stock;
    getline(ss, director, ',');
    getline(ss, title, ',');
    ss >> s;
    mainActor += s;
    mainActor += " ";
    ss >> s;
    mainActor += s;
    ss >> month;
    ss >> year;
}
// =================End of toString===================

// =================Compare===========================
// Operator ==
// bool type that compare current obj with other obj (movie)
// take const pointer of movie obj
bool Classics::isEqual(const Movie* m) const {
    const Classics*  classicsPtr = (const Classics*)m;
    return ((mainActor == classicsPtr->mainActor)
    && (year == classicsPtr->year)
    && (month == classicsPtr->month));
}
// Operator >=
// bool type that compare current movie obj with other obj
// take a const movie pointer
// compare year first then
// if same then month and then actor
bool Classics::compareMovie(const Movie* m) const {
    const Classics*  classicsPtr = (const Classics*)m;
    return ((year > classicsPtr->year) ||
    ((year == classicsPtr->year) && (month > classicsPtr->month)) ||
    ((year == classicsPtr->year) && (month == classicsPtr->month) &&
    (mainActor > classicsPtr->mainActor)));
}
// =================End of Compare====================
