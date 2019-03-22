/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#include "storeManager.h"
// ===========Build Store===================
// cite the customer manager
// cite the inventory manager
// customer data
void StoreManager::buildStore(ifstream& db_Movie, ifstream& db_Customer) {
    manage_Inventory.runInventory(db_Movie);
    manage_Customer.fileCustomer(db_Customer);
}
// ===========End Build Store===============

// ===========Read Command==================
// read commands
// reference the commands
void StoreManager::readCommand(ifstream& c) {
    command.readCommand(c, manage_Customer, manage_Inventory);
}
// ===========End Read Command==============
