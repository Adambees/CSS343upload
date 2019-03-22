/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_HISTORY_H
#define MOVIESTORE_HISTORY_H

#include "manageCustomer.h"
#include "manageInventory.h"
#include "transaction.h"
#include <string>

using namespace std;

/*
// History
// child class of transaction
// display history of all customer transaction
*/

class History : public Transaction {
 public:
    // constructor
    History();
    // deconstructor
    ~History();
    // process the transaction
    virtual void doTransaction(string, ManageCustomer&, ManageInventory&);
    // static identifier
    static const char TYPE = 'H';
};

#endif //MOVIESTORE_HISTORY_H
