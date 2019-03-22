/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#include "transaction.h"

// ===========Constructor===============
Transaction::Transaction() {
    errors = "";
}
// ===========End of Constructor========

// ===========Do transaction============
// does not do anything but exist for
// inheritance purpose
void Transaction::doTransaction(string s, ManageCustomer& mc,
ManageInventory& mi) {}
// empty
// ===========End of Transaction========

// ===========Show Error================
// return the string type of all errors
string Transaction::showErrors() {
    return errors;
}
// ===========End of Show Error=========

// ===========Add Error=================
// collect all errors during command read
void Transaction::addError(string error) {
    errors += "Warning: ";
    errors += error;
    errors += "\n";
}
// ===========End of Add Error==========

// ===========Check Customer============
// check if the customer is found or not
// check pass then return true
// else just return false
bool Transaction::checkCustomer(Customer * c, int cid)  {
    if (c == nullptr) {
        ostringstream os;
        os << cid;
        // add invalid customer id
        addError("Invalid Customer ID: " + os.str());
        return false;
    }
    return true;
}
// ============End of Check Customer====
