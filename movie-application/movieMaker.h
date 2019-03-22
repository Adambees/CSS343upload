/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Class moviemaker (movieFactory)
*/

#ifndef MOVIESTORE_MOVIEMAKER_H
#define MOVIESTORE_MOVIEMAKER_H

#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"

using namespace std;
/*
// indicate factory pattern
*/
class MovieMaker {
 public:
    // pointer for makeMovie
    static Movie* makeMovie(const string&);
};

#endif //MOVIESTORE_MOVIEMAKER_H
