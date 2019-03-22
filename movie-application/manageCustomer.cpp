/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#include "manageCustomer.h"

// ===========Constructor=======================
ManageCustomer::ManageCustomer() {}
// empty
// ===========End of constructor================

// ===========Deconstructor=====================
ManageCustomer::~ManageCustomer() {}
// empty
// ===========End of Constructor================

// ===========File Customer=====================
// Read the file
// parse the data (customer data)
// then insert customer to hashtable
void ManageCustomer::fileCustomer(ifstream& file) {
    for (;;) {
        // id
        int cid;
        // last naem and first name hold space too
        string last, first, space;
        // get id
        getline(file, space, ' ');
        // convert id to int
        stringstream(space) >> cid;
        // get last name
        getline(file, last, ' ');
        // get first name
        getline(file, first);
        // hit the end of line break
        if (file.eof()) break;
        // alloc the customer
        Customer*  cPtr = new Customer (cid, last, first);
        // insert the customer to hash
        // invalid then not insert
        bool success = h_Table.addCustomer(cid, cPtr);
        if (!success)
            delete cPtr;
    }
}
// ===========End of File Customer==============

// ===========Get Customer======================
// Pointer to customer
// retrieve from hash table
Customer*  ManageCustomer::getCustomer(int cid) {
    Customer*  c = nullptr;
    c = h_Table.getCustomer(cid);
    return c;
}
// ===========End of Get Customer===============
