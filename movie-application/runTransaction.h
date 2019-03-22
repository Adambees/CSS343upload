/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_RUNTRANSACTION_H
#define MOVIESTORE_RUNTRANSACTION_H

#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"
#include "transaction.h"

using namespace std;

/*
// Run Transaction
// Use Factory pattern
*/

class RunTransaction {
 public:
    // create static pointer to movie obj
    static Transaction* runTransaction(const char&);
};


#endif //MOVIESTORE_RUNTRANSACTION_H
