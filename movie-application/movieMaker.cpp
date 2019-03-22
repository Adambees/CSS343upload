/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Class moviemaker (movieFactory)
*/

#include "movieMaker.h"

// ===========MakeMovie=========================
// static method to return the pointer of the movie
Movie * MovieMaker::makeMovie(const string& m) {
    // movie pointer
    Movie *  newMovie = nullptr;
    // get the first character of the string
    switch (m[0]) {
        case Drama::TYPE:
        // create drama
            newMovie = (Movie*) new Drama(m);
            break;
        // create comedy
        case Comedy::TYPE:
            newMovie = (Movie*) new Comedy(m);
            break;
        // create classics
        case Classics::TYPE:
            newMovie = (Movie*) new Classics(m);
            break;
        default:
            newMovie = nullptr;
            break;
    }
    // return movie
    return newMovie;
}
// ===========End of Make Movie=================
