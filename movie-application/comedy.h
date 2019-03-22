/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

/*
// Comedy
// Inheritance Movie.h
// Comedy while class of Movie
// Store same as drama
// Sort by title and year
*/
#ifndef MOVIESTORE_COMEDY_H
#define MOVIESTORE_COMEDY_H

#include "movie.h"
#include <string>

using namespace std;

class Comedy : public Movie {
 public:
    // constructor
    explicit Comedy(const string&);
    // copy constructor
    Comedy(const string&, const int&);
    // deconstructor
    virtual ~Comedy();
    // return string of movie data
    virtual string dataOutput() const;
    // return customer in string format
    virtual string dataOutputForCustomer() const;
    // identifier for comedy
    static const char TYPE = 'F';

 protected:
    // compare purpose sorting
    virtual bool isEqual(const Movie* m) const;
    // compare purpose sorting
    virtual bool compareMovie(const Movie* m) const;
};

#endif //MOVIESTORE_COMEDY_H
