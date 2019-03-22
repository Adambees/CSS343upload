/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#include "runTransaction.h"

// ===========Run Transaction===========================
// static method to return the pointer of the movie
Transaction* RunTransaction::runTransaction(const char& type) {
    // pointer to transaction
    Transaction* t = nullptr;
    switch (type) {
        case Borrow::TYPE:
            // alloc borrow
            t = new Borrow();
            break;
        case Return::TYPE:
            // alloc return
            t = new Return();
            break;
        case History::TYPE:
            // alloc history
            t = new History();
            break;
        case Inventory::TYPE:
            // alloc inventory
            t = new Inventory();
            break;
        default:
            // alloc NULL
            t = nullptr;
            break;
    }
    // return the transaction
    return t;
}
// ===========End of Run Transaction====================
