/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#include "commandRunner.h"

// =========Constructor=======================
CommandRunner::CommandRunner() {}
// empty
// =========End of Constructor================

// =========Deconstructor=====================
CommandRunner::~CommandRunner() {}
// empty
// =========End of Deconstructor==============

// =========Read Command =====================
// process the file by line
// send each line to runTransaction
// then process each transaction and then delete it
// reference the manageCustomer manageInventory
void CommandRunner::readCommand(ifstream & infile2,
    ManageCustomer& mc, ManageInventory& mi) {
    // temp string
    string temp;
    // transaction pointer
    Transaction * t = nullptr;
    char type;
    for (;;) {
        // insert the type
        infile2 >> type;
        // alloc obj
        t = RunTransaction::runTransaction(type);
        // hit end of line then break
        if (infile2.eof()) break;
        switch (type) {
            case 'I':
                // get transaction data
                getline(infile2, temp);
                // transaction process
                t->doTransaction(temp, mc, mi);
                // add error report
                invalid += t->showErrors();
                // delete the transaction
                delete t;
                break;
            case 'H':
                // get transaction data
                getline(infile2, temp);
                // transaction process
                t->doTransaction(temp, mc, mi);
                // add error report
                invalid += t->showErrors();
                // delete the transaction
                delete t;
                break;
            case 'B':
                // get transaction data
                getline(infile2, temp);
                // transaction process
                t->doTransaction(temp, mc, mi);
                // add error report
                invalid += t->showErrors();
                // delete the transaction
                delete t;
                break;
            case 'R':
                // get transaction data
                getline(infile2, temp);
                // transaction process
                t->doTransaction(temp, mc, mi);
                // add error report
                invalid += t->showErrors();
                delete t;
                break;
            // invalid transaction type
            default:
                // get invalid movie data
                getline(infile2, temp);
                string str(1, type);
                // add invalid transaction
                invalid += "Warning: Invalid Command type: " + str +"\n";
                break;
        }
    }
    // delete transaction
    delete t;
    // display error
    displayErrors();
}

// ========Display Error======================
// display all errors during reading transaction
void CommandRunner::displayErrors() const {
    cout << endl;
    cout << "ERROR Report" << endl;
    cout << invalid;
    cout << endl;
}
// ========End of Display Error===============
