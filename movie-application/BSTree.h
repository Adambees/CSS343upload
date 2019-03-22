/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Class BST
*/

#ifndef MOVIESTORE_BSTREE_H
#define MOVIESTORE_BSTREE_H

#include "movie.h"
/*
// Simple BST
// Each node print the movie data
// root and root contain at most 2 nodes
// left and right
*/
class BSTree {
 public:
    // Constructor
    BSTree();
    // Deconstructor
    ~BSTree();
    // Empty the tree
    void makeEmpty();
    // Check empty or not
    bool isEmpty() const;
    // Search the data
    Movie* retrieve(const Movie*);
    // Insert the data
    bool putIntoBST(Movie *);
    void showMeTheOutput();

 private:
    int movieCode;
    // =================Structure of Node================
    // Just normal BST
    struct Node {
        Movie* data;
        Node* leftPtr;
        Node* rightPtr;
    };
    Node* root;
    // =================End of BST=======================

    // =================Helper Functions=================
    void emptyHelper(Node*&);
    Movie* retrieveBSTHelper(Node*&, const Movie*) const;
    void inorderOutput(Node*) const;
    bool putIntoBSTHelper(Node*&, Movie*);
    // =================End of Helper Functions==========
};

#endif //MOVIESTORE_BSTREE_H
