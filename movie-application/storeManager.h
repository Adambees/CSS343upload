/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_STOREMANAGER_H
#define MOVIESTORE_STOREMANAGER_H

#include "manageCustomer.h"
#include "manageInventory.h"
#include "commandRunner.h"

/*
// StoreManager
// Class for managing other manage classes
*/
class StoreManager {
 public:
    // build store based on creating movie and customer
    void buildStore(ifstream&, ifstream&);
    // process the commandline
    void readCommand(ifstream&);

 private:
    // Customer Manage obj
    ManageCustomer manage_Customer;
    // Inventory Manage obj
    ManageInventory manage_Inventory;
    // commands Manager obj
    CommandRunner command;
};

#endif //MOVIESTORE_STOREMANAGER_H
