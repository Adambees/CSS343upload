/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_TRANSACTION_H
#define MOVIESTORE_TRANSACTION_H

#include "manageCustomer.h"
#include "manageInventory.h"
#include "customer.h"
#include <string>

using namespace std;

/*
// Transaction
// parent class for Borrow
// return Inventory, and History
// records the error and adds errors to
// string
*/

class Transaction {
 public:
    // constructor
    Transaction();
    // deconstructor
    virtual ~Transaction() {};
    // process the transaction commend
    virtual void doTransaction(string, ManageCustomer&, ManageInventory&);
    // 
    static const char DVD = 'D';
    // return error message
    string showErrors();

 protected:
    // string that can hold all types of errors
    string errors;
    // add errors all command (mistakes)
    void addError(string);
    // check if the customer is valid or not
    bool checkCustomer(Customer*, int);
};


#endif //MOVIESTORE_TRANSACTION_H
