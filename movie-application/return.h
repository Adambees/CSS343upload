/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_RETURN_H
#define MOVIESTORE_RETURN_H

#include "manageCustomer.h"
#include "manageInventory.h"
#include "transaction.h"
#include <string>

using namespace std;

/*
// Return
// Child class of Transaction
// return movie from customer
// update the manageInventory
*/

class Return : public Transaction {
 public:
    // constructor
    Return();
    // deconstructor
    ~Return();
    // process the transaction
    virtual void doTransaction(string, ManageCustomer&, ManageInventory&);\
    // static identifier
    static const char TYPE = 'R';

 protected:
    // helper function to transaction
    void returnMovie(Customer*, Movie*, Movie*);
    // helper function to transaction
    void readTransaction(string info, Customer* customer, ManageInventory& inv_mang);
};

#endif //MOVIESTORE_RETURN_H
