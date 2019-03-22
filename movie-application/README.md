# Movie Store

Author(s): Hyuk Gi, Lee, Jun Hyung Park

GitHub URL: https://github.com/2018WI343/store-leeh54/commit/ca3b23c242ccdbc04bfb9ae975ab434c7229aa9b

Expected Mark: 100/120? maybe

## Checklist

Development Platform: visual studio code, cLion

Tested on CSS Linux Lab: Yes

Tested on Travis: No

Warning
6 warnings pops up
We all aware that it is due to inheritance
*  Warning: unused parameter, it is due to inheritance function
from transaction virtual function doTransaction which contains 3 parameters but
some of the class do not require of using all three parameter and that is why 
it is giving us the warning of unused parameter

cpplint messages:
Total Errors found 11
Except 3 following errors
*  movieMaker.cpp:18 Using C-Style cast. Use reinterpret_cast<Movie*>(...) [readability/casting]
*  movieMaker.cpp:22 Using C-Style cast. Use reinterpret_cast<Movie*>(...) [readability/casting]
*  movieMaker.cpp:26 Using C-Style cast. Use reinterpret_cast<Movie*>(...) [readability/casting]

and other 9 errors is
*  BSTree.cpp: None: BSTree.cpp shold include its header file BSTree.h [build/include]
*  commandRunner.cpp:None: commandRunner.cpp should include its header file commandRunner.h [build/include]
*  hashTable.cpp:None: hashTable.cpp should include its header file hashTable.h [build/include]
*  manageCustomer.cpp:None: managerCustoer.cpp should include its header file manageCusutomer.h [build/include]
*  manageInventory.cpp: None: manageInventory.cpp should include its header file manageInventory.h [build/include]
*  movieMaker.cpp:NOne: movieMkaer.cpp should include its header file movieMaker.h [build/include]
*  runTransaction.cpp:None: runTransaction.cpp should include its header file runTransaction.h [build/include]
*  storeManager.cpp:None: storeManager.cpp should include its header file storeManager.h [build/include]

Base on my understanding, it is giving this error becauase I didn't include the h file which we did.
Therfore, I am not fully aware.

cppcheck messages:
*  [borrow.cpp]: (style) the scope of the variable movie_T can be reduced
*  [borrow.cpp]: (style) the scope of the variable yr can be reduced
*  [borrow.cpp]: (style) the scope of the variable month can be reduced
*  [borrow.cpp]: (style) the scope of the variable m can be reduced
*  [borrow.cpp]: (style) the scope of the variable temp can be reduced

*  [classic.cpp] (performance) varaible mainActor is assigned in constructor body
*  [comedy.cpp]: (style) C-style pointer casiting

*  [customer.cpp] (warning): customer::front is not initialized in the constructor
*  [customer.cpp] (warning): customer::tFront is not initialized in the constructor

*  [customer.cpp] (performance) variable first is assigned in constructor body.

Other feedbacks from cppheck, are same
We are aware of this and we decdied to leave it the way due to our comfortness.

valgrind messages: 
*  NO Definite lost
* Although we have 
*  still reachable 72,704 byes

## Command Functionality Checklist

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full

## Location of error message or functionality

State the file and function where the information can be found

invalid command code:
function readCommand which is
located in commandRunner.cpp shows the invalid command
that found in the data4commands.txt
which are in line 30 (X), and Line 36 (Z).
Our error report also displays as:

"
Warning: Invalid Command type: X
Warning: Invalid Command type: Z
"

invalid movie type:
readTransaction function in the Borrow and Return
class finds invalid movie type from data4commands.txt
Our error report also displays as:

"
Warning: Invalid Movie type: Z 2 1971 Malcolm McDowell
"

invalid customer ID:
checkCustomer function in Transaction finds the invalid
customer ID.
We found out that in the data4commands.txt has invalid
customer ID which is 1234.
Our error report also displays as:

"
Warning: Invalid Customer ID: 1234
"
 
invalid movie:
function runInventory in manageInventory class finds invalid
movie and outputs the errors from data4movies.txt.
Our error report also displays as:

"
Invalid Movie Report

Z, 10, Hal Ashby, Harold and Maude, Bud Cort 3 1971
Z, 10, Frank Capra, It's a Wonderful Life, James Steward 11 1946

"

factory classes:
We used pattern of factory method in the runTransaction class
and movieMaker class.

hashtable:
We have hashTable that holds customers which makes easy access
to reach customer by customer ID.

container used for comedy movies:
The container for all the movies including comedy will be on
BST where the movie gets retrieve, display, and called through
manageInventory.

function for sorting comedy movies:
isEqual and compareMovie function in comedy class makes sorting.

function where comedy movies are sorted:
Insert the data through manageInventory to
Function putInto BST makes the comedy movie sorted and retrieve BST to
through manageInventory

functions called when retrieving a comedy movie based on title and year:
In our class Borrow and Return, our system reads the txt file through
readTransaction function in the class and sets title and year from
the txt and allocate new comedy movie object as temp and it retrieve
actual pointer to the movie.

functions called for retrieving and printing customer history:
Function movieHistory in the Customer class prints the customer history
by finding the correct customer in the hash table and pulling all the
history data by using dataOutputForCustomer function in Movie class
that is inherited through it's child class.

container used for customer history:
We used hash table to create an array of customer and this customer
has key which is customer ID which can linked to it's data or history.

functions called when borrowing a movie:
function readCommand first notices the command 'B' which is borrow.
This toss to the function doTransaction in the Borrow class which
uses readTransaction to read the information and calls borrowMovie
function in the Borrow class to process borrowing a movie.

explain borrowing a movie that does not exist:
In our output for the Error report, it prints the following:

"
Warning: Invalid Borrow D, F,  Bogus Title, , 2001
[NO SUCH MOVIE IN THE STORE]
Warning: Invalid Borrow D, D,  Steven Spielberg,  Bogus Title, 0
[NO SUCH MOVIE IN THE STORE]
"

This indicates that the title of the movie is not listed in the
list of the movies in our movie store inventory. Also,
our function borrowMovie finds the error by calling out the
addError function from the Transaction class.


explain borrowing a movie that has 0 stock:
In our Customer class, if returnMovie and borrowMovie function
is called, it checks the stock by calling functions
stockIncrease and stockDecrease from Movie Class. If the stock
is 0 or it does not successfully go through the transaction,
it shows the error. Below is the output result for the error.

"
Warning: Invalid Borrow Customer ID: 9000 (Lizard Larry) D, C,
Hal Ashby,  Harold and Maude, Ruth Gordon, 3, 1971 [OUT OF STOCK]
Warning: Invalid Borrow Customer ID: 3333 (Witch Wicked) D, C,
Hal Ashby,  Harold and Maude, Ruth Gordon, 3, 1971 [OUT OF STOCK]
Warning: Invalid Borrow Customer ID: 7777 (Spider Sammy) D, C,
Hal Ashby,  Harold and Maude, Ruth Gordon, 3, 1971 [OUT OF STOCK]
"

explain returning a movie that customer has not checked out:
Through the function returnMovie in the Return class, our system
can find that if the customer didn't checked out or borrowed
the movie from our movie store, it shows an error and gets
the output that displays [DIDNT BORROWED] in the last sentence.
Our output shows that there is no error for checked out issue
for the returning movie.

any static_cast or dynamic_cast used:
Class of movieMaker, Classic, Comedy, and Drama used cast.




https://codegolf.stackexchange.com/questions/16587/print-a-smiley-face

```

                            $$$$$$$$$$$$$$$$$$$$
                       $$$$$$$$$$$$$$$$$$$$$$$$$$$
                    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$         $$   $$$$$
    $$$$$$        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$$$$$$$$
 $$ $$$$$$      $$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$       $$$$$$$$
 $$$$$$$$$     $$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$    $$$$$$$$
   $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$
   $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  $$$$$$
    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$
     $$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$$
    $$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$$
    $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$
   $$$$$$$$$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$$$$$$$$$$$$$$$$
   $$$$$$$$$$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$$$$$$$$$
  $$$$       $$$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      $$$$
             $$$$$     $$$$$$$$$$$$$$$$$$$$$$$$$         $$$
               $$$$          $$$$$$$$$$$$$$$           $$$$
                $$$$$                                $$$$$
                 $$$$$$      $$$$$$$$$$$$$$        $$$$$
                   $$$$$$$$     $$$$$$$$$$$$$   $$$$$$$
                      $$$$$$$$$$$  $$$$$$$$$$$$$$$$$
                         $$$$$$$$$$$$$$$$$$$$$$
                                 $$$$$$$$$$$$$$$
                                     $$$$$$$$$$$$
                                      $$$$$$$$$$$
                                       $$$$$$$$


```

