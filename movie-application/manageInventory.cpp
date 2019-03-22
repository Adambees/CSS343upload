/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#include "manageInventory.h"

// ===========Run Inventory====================
// Process the files and send line to movieMaker
// The obj will be inserted to BST
// if the objects are invalid then add to history error
void ManageInventory::runInventory(ifstream& infile) {
    // store movie data var
    string s;
    for (;;) {
        // insert data to string
        getline(infile, s);
        // end of the line
        if (infile.eof()) break;
        // pointer movie
        Movie* m = MovieMaker::makeMovie(s);
        switch (s[0]) {
            // insert drama
            case Drama::TYPE:
                dramaBST.putIntoBST(m);
                break;
            // insert comedy
            case Comedy::TYPE:
                comedyBST.putIntoBST(m);
                break;
            // insert classics
            case Classics::TYPE:
                classicsBST.putIntoBST(m);
                break;
            default:
                addError(s);
                break;
        }
    }
    // display errors
    showErrors();
}
// ===========End of Run Inventory=============

// ===========Retrieve Movie===================
// Pointer to movie
// retrieve movie from BST
Movie* ManageInventory::retrieveMovie(Movie* temp, char type)  {
    // simply switch to get right tree
    switch (type) {
        case 'D':
            return dramaBST.retrieve(temp);
        case 'F':
            return comedyBST.retrieve(temp);
        case 'C':
            return classicsBST.retrieve(temp);
        default:
            break;
    }
    return nullptr;
}

// ===========Show Output======================
// display all BST
// comedy, drama, classics
void ManageInventory::showMeTheOutput() {
    cout << endl;
    cout << "Comedies " << endl;
    cout << "TYPE | Stock | Director | Title | Year" << endl;
    comedyBST.showMeTheOutput();
    cout << "Dramas " << endl;
    cout << "TYPE | Stock | Director | Title | Year" << endl;
    dramaBST.showMeTheOutput();
    cout << "Classics " << endl;
    cout << "TYPE | Stock | Director | Title | Main Actor| Month | Year"
    << endl;
    classicsBST.showMeTheOutput();
    cout << endl << endl;
}
// ===========End of Show Output===============

// ===========Add Error========================
// collect the error during movie creating
// store the error into string error
void ManageInventory::addError(string error) {
    errors += error;
    errors += "\n";
}
// ===========End Add Error====================

// ===========Show Errors======================
// display all errors
void ManageInventory::showErrors() const {
    cout << endl;
    cout << "Invalid Movie Report" << endl << endl;
    cout << errors;
    cout << endl;
}
// ===========End of Show Errors===============
