/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_INVENTORY_H
#define MOVIESTORE_INVENTORY_H

#include "manageCustomer.h"
#include "manageInventory.h"
#include "transaction.h"
#include <string>

using namespace std;

/*
// Inventory
// child class of transaction
// For display the drama, comedy, classics
// movie of the store
*/

class Inventory : public Transaction {
 public:
    // constructor
    Inventory();
    // deconstructor
    ~Inventory();
    // process the transaction
    virtual void doTransaction(string s, ManageCustomer& mc, ManageInventory& mi);
    // static identifier
    static const char TYPE = 'I';
};

#endif //MOVIESTORE_INVENTORY_H
