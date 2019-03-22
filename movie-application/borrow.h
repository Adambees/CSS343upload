/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Class Borrow
*/

#ifndef MOVIESTORE_BORROW_H
#define MOVIESTORE_BORROW_H

#include "manageCustomer.h"
#include "manageInventory.h"
#include "transaction.h"
#include <string>

using namespace std;

/*
// Borrow the movie from customer
// and update the manageInventory
// child class of transaction
*/

class Borrow : public Transaction {
 public:
    Borrow();
    ~Borrow();
    virtual void doTransaction(string, ManageCustomer&, ManageInventory&);
    static const char TYPE = 'B';

 protected:
    void borrowMovie(Customer*, Movie*, Movie*);
    void readTransaction(string info, Customer* customer, ManageInventory& inv_mang);
};

#endif //MOVIESTORE_BORROW_H
