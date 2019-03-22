/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#include "history.h"

// ==========Constructor===============
History::History() {
    errors = "";
}
// ==========End of Constructor========

// ==========Deconstructor=============
History::~History() {}
// empty
// ==========End of Deconsturcotr======

// ==========Do Transaction============
// Proceed the transaction
// read the line from customer ID
// if the customer exist then retrieve the customer
// print the customer history
void History::doTransaction(string s, ManageCustomer& mc, ManageInventory& mi) {
    // customer id
    int cid;
    // pointer to customer obj
    Customer * c = nullptr;
    // string reader
    stringstream ss;
    // assign the string to reader
    ss << s;
    // assign the id
    ss >> cid;
    // pointer to customer
    c = mc.getCustomer(cid);
    // check exist of customer and print
    if (checkCustomer(c, cid)) {
        c->movieHistory();
    }
}
// ==========End of Do Transaction=====
