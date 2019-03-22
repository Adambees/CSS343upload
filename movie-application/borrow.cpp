/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Class borrow.cpp
*/

#include "borrow.h"

// ==========Constructor===================
Borrow::Borrow() {
    errors = "";
}
// ==========End of Constructor============

// ==========Deconstructor=================
Borrow::~Borrow() {}
// empty
// ==========End of Deconstructor==========

// ==========Do Transaction================
// read the line and get the id
// check id
// if the customer Id is valid then call the helper
// read transaction
void Borrow::doTransaction(string s, ManageCustomer& mc, ManageInventory& mi) {
    string str;
    int cid;
    Customer * c = nullptr;
    stringstream ss;
    ss << s;
    ss >> cid;
    c = mc.getCustomer(cid);
    if (checkCustomer(c, cid)) {
        getline(ss, str);
        readTransaction(str, c, mi);
    }
}
// ==========End of DoTransaction==========

// ==========Borrow Movie==================
// check if the customer is available to borrow movie
// from the movie inventory. if movie is not exist
// in the inventory, it sends error
void Borrow::borrowMovie(Customer* c, Movie* m, Movie* temp) {
    if (m != nullptr) {
        bool success = c->borrowMovie(m);
        if (!success) {
            addError("Invalid Borrow " + c->getCustomerData() +
            " " + m->dataOutputForCustomer() + " [OUT OF STOCK]");
        }
    } else {
        addError("Invalid Borrow " + temp->dataOutputForCustomer()
        + " [NO SUCH MOVIE IN THE STORE]");
    }
}
// ==========End of Borrow Movie===========

// ==========Read Transaction==============
// Helper function for Do Traction
// Parse the line to small
// base on the parse, creates pointer to movie
// and retrieve actual movie
// if it retrieve, then call borrowMovie
void Borrow::readTransaction(string s, Customer* c, ManageInventory& mi) {
    // get reader
    stringstream ss;
    // insert the string
    ss << s;
    // media, movie var
    char media_T, movie_T;
    // movie title, director actor var
    string title, director, mainActor;
    int yr = 0;
    int month = 0;
    Movie* m = nullptr;
    Movie* temp = nullptr;
    // insert the media
    ss >> media_T;
    if (media_T == DVD) {
        // insert the movie type
        ss >> movie_T;
        switch (movie_T) {
            case 'D':
                getline(ss, director, ',');
                getline(ss, title, ',');
                temp = new Drama(title, director);
                m = mi.retrieveMovie(temp, movie_T);
                borrowMovie(c, m, temp);
                delete temp;
                break;
            case 'F':
                getline(ss, title, ',');
                getline(ss, director);
                stringstream(director) >> yr;
                temp = new Comedy(title, yr);
                m = mi.retrieveMovie(temp, movie_T);
                borrowMovie(c, m, temp);
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
                borrowMovie(c, m, temp);
                delete temp;
                break;
            // Invalid movie type
            default:
                getline(ss, title);
                string str(1, movie_T);
                addError("Invalid Movie type: " + str + title);
                break;
        }
    } else {
        string str(1, media_T);
        getline(ss, title);
        // add invalid media type
        addError("Invalid Media type: " + str + title);
    }
}
// ==========End of Read Transaction=======
