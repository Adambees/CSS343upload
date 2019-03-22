/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Class Customer
*/

#ifndef MOVIESTORE_CUSTOMER_H
#define MOVIESTORE_CUSTOMER_H

#include "movie.h"
#include <vector>
#include <string>

using namespace std;

/*
// Customer
// contains id, first, last name
// keep track the borrow and return movies
*/

class Customer {
 public:
    // constructor
    Customer();
    // copy constructor
    Customer(int, string, string);
    // deconstructor
    ~Customer();
    // borrow movie
    bool borrowMovie(Movie*);
    // return movie
    bool returnMovie(Movie*);
    // print customer borrow and returns history
    void movieHistory();
    // return customer id
    int getID() const ;
    // return data about customer
    string getCustomerData();

 private:
    // last name
    string last;
    // first name
    string first;
    // key
    int customer_ID;
    // increases movie stock
    int stock_increment;

    // structure for customer
    struct  List {
        List* next;
        char transaction;
        Movie* m_data;
    };
    List* front;
    // vector reverse history
    vector<string> array;

    // structure for borrow
    struct TransactionList{
        TransactionList* next;
        // B or R
        char transaction;
        Movie* movie;
    };
    TransactionList* tFront;
    // check if return is valid
    bool checkReturn(Movie*);
    // check if borrow is valid
    bool checkBorrow(Movie*);
    // add transaction
    bool addTransaction(const char, Movie*);
};

#endif //MOVIESTORE_CUSTOMER_H
