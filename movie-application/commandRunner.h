/*
// Author: Hyuk Gi Lee, Jun Hyung Park
// Class: CSS343
// Version: Final Version
*/

#ifndef MOVIESTORE_COMMANDRUNNER_H
#define MOVIESTORE_COMMANDRUNNER_H

#include "movie.h"
#include "manageInventory.h"
#include "manageCustomer.h"
#include "runTransaction.h"

using namespace std;

/*
// Command Runner
// manager class that run the command
// use the factory pattern
*/

class CommandRunner {
 public:
    // constructor
    CommandRunner();
    // deconstructor
    virtual ~CommandRunner();
    // read the command
    void readCommand(ifstream&, ManageCustomer&, ManageInventory&);
    // display error
    void displayErrors() const;

 private:
    string invalid;
};

#endif //MOVIESTORE_COMMANDRUNNER_H
