/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#include "hashTable.h"

// ===========Constructor====================
// use helper function
HashTable::HashTable() {
    buildHash();
}
// ===========End of Constructor=============

// ===========Helper Function================
// for constructor
// simply loop through and
// initialize all table index to null
void HashTable::buildHash() {
    for (int i = 0; i < SIZE; ++i) {
        h_Array[i].front = nullptr;
    }
}
// ===========End Helper Function============

// ===========Deconstructor==================
HashTable::~HashTable() {
    emptyHash();
}
// ===========End Deconstructor==============

// ===========Helper Empty Hash==============
// helper for deconstructor
// delete all linked list indexes
void HashTable::emptyHash() {
    for (int i = 0; i < SIZE; ++i) {
        if (h_Array[i].front != nullptr) {
            HashList* temp = h_Array[i].front;
            while (h_Array[i].front != nullptr) {
                h_Array[i].front = h_Array[i].front->next;
                delete temp->c_data;
                delete temp;
                temp = h_Array[i].front;
            }
        }
    }
}
// ===========End of Empty Hash==============

// ===========GetCustomer====================
// take key
// find index in the hashtable
// traversal the linked list and return ptr
Customer* HashTable::getCustomer(int cid) {
    // size check
    if (cid > 9999 || cid < 0) {
        return nullptr;
    }
    // assign hash
    int hash = (cid % HASH);
    // if no customer at the hash index then
    // traverse the list
    if (h_Array[hash].front == nullptr) {
        return nullptr;
    } else {
        HashList* h_list = h_Array[hash].front;
        while (h_list != nullptr) {
            // if the key is found
            // return
            if (cid == h_list->key) {
                return h_list->c_data;
            }
            // else next
            h_list = h_list->next;
        }
    }
    // not found then return null
    return nullptr;
}
// ===========End of Get Customer============

// ===========Add Customer===================
// find the hash number for customer
// insert the customer pointer to hashtable
bool HashTable::addCustomer(int cid, Customer* c) {
    // size check
    if (cid > 9999 || cid < 0) {
        return false;
    }
    // assign hash
    int hash = (cid % HASH);
    // pointer node to store the customer
    HashList* h_list = new HashList;
    // point the customer
    h_list->c_data = c;
    // point the key
    h_list->key = cid;
    // next set to null
    h_list->next = nullptr;
    // check if the index is empty
    // if more then one node then
    // go to else part
    if (h_Array[hash].front == nullptr) {
        h_list->next = h_Array[hash].front;
        h_Array[hash].front = h_list;
    } else {
        HashList * current = h_Array[hash].front;
        while (current->next != nullptr) {
            // delete the customer
            // delete the pointer
            if (cid == current->key) {
                delete h_list->c_data;
                delete h_list;
                return false;
            }
            current = current->next;
        }
        // add to the list
        current->next = h_list;
    }
    return true;
}
// ===========End of add Customer============
