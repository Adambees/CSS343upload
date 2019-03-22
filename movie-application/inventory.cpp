/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// class Inventory
*/

#include "inventory.h"

// ===========Constructor====================
Inventory::Inventory() {
    errors = "";
}
// ===========End of Constructor=============

// ===========Deconstructor==================
Inventory::~Inventory() {}
// empty
// ===========End of Deconstructor===========

// ===========Transaction====================
// cite inventory manager to print the
// current inventory that has all movie in store
void Inventory::doTransaction(string s, ManageCustomer& mc,
        ManageInventory& mi) {
    // print all the movie that in the store
    mi.showMeTheOutput();
}
// ===========End of Transaction=============
