/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
// Class Customer
*/

#include "customer.h"

// ==========Constructor===================
Customer::Customer() {
    stock_increment = 1;
}
// ==========End of Constructor============

// ==========Copy Constructor==============
Customer::Customer(int cid, string lName, string fName) {
    front = nullptr;
    tFront = nullptr;
    last = lName;
    first = fName;
    customer_ID = cid;
    stock_increment = 1;
}
// ==========End of Copy Constructor=======

// ==========Deconstructor=================
Customer::~Customer() {
    // delete the history
    List* l_Ptr = front;
    while (l_Ptr != nullptr) {
        front = front->next;
        l_Ptr->m_data = nullptr;
        delete l_Ptr;
        l_Ptr = front;
    }
    // delete the transaction log
    TransactionList* t_list = tFront;
    while (t_list != nullptr) {
        tFront = tFront->next;
        t_list->movie = nullptr;
        delete t_list;
        t_list = tFront;
    }
    // empty vector
    array.clear();
}
// ==========Get Id========================
// return id of customer
int Customer::getID() const {
    return customer_ID;
}
// ==========End Get Id====================

// ==========Add Transaction===============
// save transaction history using linked list
bool Customer::addTransaction(const char type, Movie* m) {
    // alloc ptr
    List* l_Ptr = new List;
    // point to transaction type
    l_Ptr->transaction = type;
    // point to movie
    l_Ptr->m_data = m;
    // next null
    l_Ptr->next = nullptr;
    // if first transaction is null
    if (front == nullptr) {
        l_Ptr->next = front;
        front = l_Ptr;
    } else {
        List * current = front;
        // loop till the last
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = l_Ptr;
    }
    return true;
}
// ========End of Transaction==============

// ========Borrow Movie====================
// check if movie has empty stock and borrow
// borrow movie and save transaction
// to customer history
bool Customer::borrowMovie(Movie* m) {
    // check if stock is not empty
    // call borrow movie to add transaction log
    if (m->getStock() != 0 && checkBorrow(m)) {
        m->stockDecrease();
        return addTransaction('B', m);
    }
    return false;
}
// =======End of Borrow Movie==============

// =======Return Movie=====================
// check if the movie is already borrowed
// and save it into customer history
bool Customer::returnMovie(Movie* m) {
    if (checkReturn(m)) {
        m->stockIncrease(stock_increment);
        return addTransaction('R', m);
    }
    return false;
}
// =======End Return Movie=================

// =======Movie History====================
// print customer history
// borrowing and returning movies
void Customer::movieHistory() {
    cout << endl;
    cout << "History of " << getCustomerData() << endl;
    List* current = front;
    // traverse
    while (current != nullptr) {
        // insert data to vector
        if (current->transaction == 'B') {
            array.push_back("B, " + to_string(getID()) + ", "
            + current->m_data->dataOutputForCustomer());
        } else {
            array.push_back("R, " + to_string(getID()) + ", "
            + current->m_data->dataOutputForCustomer());
        }
        current = current->next;
    }
    // print the history
    vector<string>::reverse_iterator it;
    for (it = array.rbegin(); it != array.rend(); ++it) {
        cout << *it << endl;
    }
    cout << endl;
}
// =======End of Movie History=============

// ======Get Customer Data=================
// return data about customer in string
string Customer::getCustomerData() {
    ostringstream os;
    os << "Customer ID: " << getID() << " (" << last << " " << first << ")";
    return  os.str();
}
// ======End of Get Customer Data==========

// ======Check Borrow======================
// insert transaction into transaction log
bool Customer::checkBorrow(Movie* m) {
    TransactionList* tPtr = new TransactionList;
    tPtr->next = nullptr;
    tPtr->movie = m;
    if (tFront == nullptr) {
        tPtr->next = tFront;
        tFront = tPtr;
    } else {
        TransactionList* current = tFront;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = tPtr;
    }
    return true;
}
// ======End of Check Borrow===============

// ======Check Return======================
// check if passed movie contains in current log
// if movie exist then delete data
// that borrowed movie.
bool Customer::checkReturn(Movie * mPtr) {
    // check if the front is null
    if (tFront == nullptr) {
        return false;
    }
    TransactionList* current = tFront->next;
    TransactionList* temp = tFront;
    // check first node
    if (temp->movie->isEqual(mPtr)) {
        temp->movie = nullptr;
        delete temp;
        tFront = current;
        return true;
    }
    while (current != nullptr) {
        if (current->movie->isEqual(mPtr)) {
            temp->next = current->next;
            current->movie = nullptr;
            delete  current;
            return true;
        }
        // move
        temp = current;
        current = current->next;
    }
    // not found
    return false;
}
// ======End of Check Return===============
