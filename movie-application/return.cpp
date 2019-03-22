/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// return cpp
*/

#include "return.h"

// ===========Constructor==================================
Return::Return() {
    errors = "";
}
// ===========End of Constructor===========================

// ===========Deconstructor================================
Return::~Return() {}
// empty
// ===========End of Deconstructor=========================

// ===========Do transaction===============================
// process the transaction
// read the line and get the id
// check if the id is valid then call helper function
// continue read the data
void Return::doTransaction(string s, ManageCustomer& mc, ManageInventory& mi) {
    // temp to store data
    string temp;
    // customer id
    int cid;
    // customer pointer obj
    Customer * c = nullptr;
    // string reader
    stringstream ss;
    // insert the string to reader
    ss << s;
    // insert customer id
    ss >> cid;
    // get the pointer to the customer
    c = mc.getCustomer(cid);
    // check if te customer is valid
    // get movie data and process the transaction
    if (checkCustomer(c, cid)) {
        getline(ss, temp);
        readTransaction(temp, c, mi);
    }
}
// ===========End of Transaction===========================

// ===========Return Movie=================================
// check the customer can return movie or not
// check if customer borrow the movie and add the error message
// movie does not exist in manage inventory
void Return::returnMovie(Customer* c, Movie* m, Movie* temp) {
    // check retrieve successful
    if (m != nullptr) {
        // try return
        bool success = c->returnMovie(m);
        // add invalid message
        if (!success) {
            addError(c->getCustomerData() + "\n" + "Invalid Return "
                     + m->dataOutputForCustomer() + " [DIDN'T BORROWED]");
        }
    } else {
        addError("Invalid Return " + temp->dataOutputForCustomer() +
        " [NO SUCH MOVIE IN THE STORE]");
    }
}
// ===========End of Return Movie==========================

// ===========Read Transaction=============================
// helper function for doTransaction
// parse the string into small
// create pointer to a movie and retrieve actual movie
// if retrieve success then process the return
void Return::readTransaction(string s, Customer* c, ManageInventory& mi) {
    // get reader
    stringstream ss;
    // insert string into reader
    ss << s;
    // hold media and movie
    char media_T, movie_T;
    // var for title, director, actor
    string title, director, mainActor;
    // year month var
    int yr = 0;
    int month = 0;
    // pointer actually hold tree
    Movie* m = nullptr;
    // tempo transaction movie pointer
    Movie* temp = nullptr;
    // insert the media
    ss >> media_T;
    if (media_T == DVD) {
        ss >> movie_T;
        switch (movie_T) {
            case 'D':
                getline(ss, director, ',');
                getline(ss, title, ',');
                temp = new Drama(title, director);
                m = mi.retrieveMovie(temp, movie_T);
                returnMovie(c, m, temp);
                delete temp;
                break;
            case 'F':
                getline(ss, title, ',');
                getline(ss, director);
                stringstream(director) >> yr;
                temp = new Comedy(title, yr);
                m = mi.retrieveMovie(temp, movie_T);
                returnMovie(c, m, temp);
                delete temp;
                break;
            case 'C':
                getline(ss, title, ' ');
                getline(ss, title, ' ');
                stringstream(title) >> month;
                getline(ss, title, ' ');
                stringstream(title) >> yr;
                ss >> title;
                mainActor += title;
                mainActor += ' ';
                ss >> title;
                mainActor += title;
                temp = new Classics(mainActor, month, yr);
                m = mi.retrieveMovie(temp, movie_T);
                returnMovie(c, m, temp);
                delete temp;
                break;
            default:
                getline(ss, title);
                string str(1, movie_T);
                addError("Invalid Movie type: " + str + title);
                break;
        }
    } else {
        string str(1, media_T);
        getline(ss, title);
        addError("Invalid Media type: " + str + title);
    }
}
// ===========End of Read Transaction======================
