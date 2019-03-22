/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Class movie.cpp
*/

#include "movie.h"

// Key, Stock, Director, Title, Year
// (major actor released date for Classics)
Movie::Movie() {
    key = ' ';
    stock = 0;
    director ="";
    title = "";
    year = 0;
}

// ===========Deconstructor======================
Movie::~Movie() {}
// empty
// ===========End of Deconstrutor================

// ===========Get Stock==========================
// get stock of movie
int Movie::getStock() {
    return stock;
}
// ===========End of Get Stock===================

// ===========Helper function to write===========
// method to help constructor
// parse the string to small
void Movie::toString(const string& m_data) {
    // string reader
    stringstream ss;
    // insert the data to string
    ss << m_data;
    // temp variable
    string s;
    // get the movie type
    getline(ss, s, ',');
    // assign the movie type
    key = s[0];
    // get stock
    getline(ss, s, ',');
    // assign the stock
    stringstream(s) >> stock;
    // assign the director
    getline(ss, director, ',');
    // assign the title
    getline(ss, title, ',');
    // get year then assign year
    getline(ss, s, ',');
    stringstream(s) >> year;
}
// ===========End of toString====================

// ===========Stock Increase=====================
// simply just check the condition
// then add stock
// return type is boolean
bool Movie::stockIncrease(int add) {
    if (add < 0) {
        return false;
    }
    stock += add;
    return true;
}
// ===========End of Stock Increase==============

// ===========Stock Decrease=====================
// if the stock number is less or equal 0
// just return false
// else decrease then return true
bool Movie::stockDecrease() {
    if (stock <= 0) {
        return false;
    }
    stock--;
    return true;
}
// ===========End of Stock Decrease==============
