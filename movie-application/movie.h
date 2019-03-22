/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

/*
// class Movie
// It is abstract class 
// for its child classes
// Drama, Classics, Comedy
// The purpose of this class is just for
// inheritance
// General information it contains are
// Key, stock, director, title, and year
*/

#ifndef MOVIESTORE_MOVIE_H
#define MOVIESTORE_MOVIE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Movie {
 public:
    // Deconstructor
    virtual ~Movie();
    // return current stock
    virtual int getStock();
    // increase the stock
    virtual bool stockIncrease(int);
    // decrease the stock
    virtual bool stockDecrease();
    // pure virtual function inheritance purpose set to 0
    virtual bool isEqual(const Movie* m) const = 0;
    // pure virtual function inheritance purpose set to 0
    virtual bool compareMovie(const Movie* m) const = 0;
    // pure virtual function inheritance purpose set to 0
    virtual string dataOutput() const = 0;
    // pure virtual function inheritance purpose set to 0
    virtual string dataOutputForCustomer() const = 0;

 protected:
    // constructor is in protected to avoid declaration problem
    Movie();
    // helper method for copy constructor
    void toString(const string&);
    char key;
    int stock;
    string director;
    string title;
    int year;
    static const char DVD = 'D';
};

#endif //MOVIESTORE_MOVIE_H
