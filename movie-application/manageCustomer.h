/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_MANAGECUSTOMER_H
#define MOVIESTORE_MANAGECUSTOMER_H

#include "hashTable.h"
#include "customer.h"

using namespace std;

/*
// managerCustomer
// put the customer hashTable
// Customer can also retrieve the customer
*/
class ManageCustomer {
 public:
    // constructor
    ManageCustomer();
    // deconsturctor
    ~ManageCustomer();
    // process file with customer
    void fileCustomer(ifstream &);
    // return pointer to the customer
    Customer* getCustomer(int id);

 private:
    // hashtable
    HashTable h_Table;
};

#endif //MOVIESTORE_MANAGECUSTOMER_H
