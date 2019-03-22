/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

/*
// Inheritance Movie
// Drama
// Child class of Movie
// Key D
// Sort using Director then Title
*/

#ifndef MOVIESTORE_DRAMA_H
#define MOVIESTORE_DRAMA_H

#include "movie.h"
#include <string>

using namespace std;

class Drama : public Movie {
 public:
    // constructor
    explicit Drama(const string&);
    // copy constructor
    Drama(const string&, const string&);
    // deconstructor
    virtual ~Drama();
    // return string format data for movie
    virtual string dataOutput() const;
    // return string format data for customer
    virtual string dataOutputForCustomer() const;
    // Identifier for Drama
    static const char TYPE = 'D';

 protected:
    // compare purpose for sorting
    virtual bool isEqual(const Movie* m) const;
    // compare purpose for sorting
    virtual bool compareMovie(const Movie* m) const;
};

#endif //MOVIESTORE_DRAMA_H
