/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

/*
// Inheritance Movie
// Classic
// Child class of Movie
// Contains month and actor (which different)
// With Other two movies
*/
#ifndef MOVIESTORE_CLASSIC_H
#define MOVIESTORE_CLASSIC_H

#include "movie.h"
#include <string>

using namespace std;

class Classics : public Movie {
 public:
    // Constructor
    explicit Classics(const string&);
    // Copy Constructor
    Classics(const string&, const int&, const int&);
    // Deconstructor
    virtual ~Classics();
    // return string format data for movie
    virtual string dataOutput() const;
    // return string format data for customer
    virtual string dataOutputForCustomer() const;
    // identifier
    static const char TYPE = 'C';

 protected:
    // helper function for returning data
    void toString(const string&);
    // compare purpose sorting
    virtual bool isEqual(const Movie* m) const;
    // compare purpose sorting
    virtual bool compareMovie(const Movie* m) const;

    int month;
    string mainActor;
};

#endif //MOVIESTORE_CLASSIC_H
