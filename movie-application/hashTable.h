/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_HASHTABLE_H
#define MOVIESTORE_HASHTABLE_H

#include "customer.h"

using namespace std;

/*
// Hashtable
// implemented hashtable data structure
// provide customer id access
*/

class HashTable {
 public:
    // constructor
    HashTable();
    // deconstructor
    ~HashTable();
    // return the pointer obj customer
    Customer * getCustomer(int);
    // insert the customer to hashtable
    bool addCustomer(int, Customer *);

    // size of size customer
    static const int SIZE = 100;
    // number of hashing
    static const int HASH = 102;

 private:
    // helper function to deconstructor
    void emptyHash();
    // helper function for constructor
    void buildHash();

    // structure for linked list at hashtable index
    struct HashList;
    // hash table structure
    struct HashArray {
        HashList* front;
    };

    // linked list attached to index
    struct HashList {
        Customer* c_data;
        int key;
        HashList* next;
    };
    // hashtable arr
    HashArray h_Array[SIZE];
};

#endif //MOVIESTORE_HASHTABLE_H
