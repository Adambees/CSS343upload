/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_MANAGEINVENTORY_H
#define MOVIESTORE_MANAGEINVENTORY_H

#include "movie.h"
#include "BSTree.h"
#include "movieMaker.h"

/*
// ManageInventory
// read the data files
// then sort and insert movies to BST
// Also display all BST and track the
// invalid movies
*/

class ManageInventory {
 public:
    // process the inventory
    void runInventory(ifstream &);
    // retrieve the movie from BST
    Movie * retrieveMovie(Movie*, char);
    // display
    void showMeTheOutput();

 private:
    //add errors for invalid movie
    void addError(string);
    // display all invalid movie
    void showErrors() const;
    // BST for classics
    BSTree classicsBST;
    // BST for comedy
    BSTree comedyBST;
    // BST for drama
    BSTree dramaBST;
    string errors;
};

#endif //MOVIESTORE_MANAGEINVENTORY_H
