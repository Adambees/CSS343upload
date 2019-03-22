/**
 * TurtleProgram.cpp
 * Contains functionality of turtleprogram.h
 * Contains 3 Constructor
 * Contains deconstructor
 * Contains boolean operator overloading functions
 * Contains assignment operator and copy constructor
 * Contains Mathmatic operators
 * Contains function to return length
 * Contains function to return index
 * Contains function to set the index and value
 * CSS 343 Assignment_1
 * @author Jun Hyung Park
 * @date Jan 15 2019
 */

#include "turtleprogram.h"

/*
    TODO(Park): default constructor
    1. Constructor set the private variable to nullptr and zero
*/
TurtleProgram::TurtleProgram()
:length(0), arr(nullptr)
{}
// ----------------------------------------------------------
/*
    2. Constructor with One Parameter
    Set the private variable length to 1
    Assign one string data to private arr
*/
TurtleProgram::TurtleProgram(const std::string& a) {
    arr = new std::string[1];
    arr[0] = a;
    length = 1;
}
// ----------------------------------------------------------
/*
    3. Constructor with Two Parameter
    Set the private variable length to 2
    Assign two string data to private arr 
*/
TurtleProgram::TurtleProgram(const std::string& a, const std::string& b) {
    arr = new std::string[2];
    arr[0] = a;
    arr[1] = b;
    length = 2;
}
// -----------------------------------------------------------
/*
    Copy Constructor
    Copy the data
*/
TurtleProgram::TurtleProgram(const TurtleProgram& copy) {
    length = copy.getLength();
    arr = new std::string[copy.getLength()];
    for ( int i = 0; i < copy.getLength(); i++ ) {
        arr[i] = copy.arr[i];
    }
}
// -----------------------------------------------------------
/*
    Deconstructor
    Delete all memory that is allocated in arr
*/
TurtleProgram::~TurtleProgram() {
    delete [] arr;
}
// -----------------------------------------------------------
/*
    getLength function returns the number of strings in the program
*/
int TurtleProgram::getLength() const {
    return length;
}
// ----------------------------------------------------------
/*
    check index bound error
    did not use try catch
    implemented with if else statement
    getIndex returns the nth string in the program
    [F 10 PENUP R 90 F 100] get index(0) would return F
*/
const std::string& TurtleProgram::getIndex(int idx) const {
    if ( (length > 0) && (idx >= 0) && (idx < length) ) {
        return arr[idx];
    } else {
        std::cout << "Error Out of Bound" << std::endl;
        std::cout << "Just returning last value ";
        return arr[getLength() - 1];
    }
}
// ----------------------------------------------------------
/*
    Set Index similar to getIndex 
    but is used to replace the string at the given index
    check the index error used if else statement
*/
void TurtleProgram::setIndex(int idx, const std::string& newValue) {
    if ( idx < this->getLength() && idx >= 0 ) {
        this->arr[idx] = newValue;
    } else {
        std::cout << "Invalid Index Value" << std::endl;
        return;
    }
}
/*
    An Empty Program is printed with just square brackets, 
    no space: []
    A program with 
    multiple strings has a single space separating strings: [F 50 R 90]
    use if else statement to handle the last data space
*/
std::ostream& operator << (std::ostream& output, const TurtleProgram& turtle) {
    output << "[";
    for (int i = 0; i < turtle.getLength(); i++) {
        if (i == turtle.getLength() - 1) {
            output << turtle.getIndex(i);
        } else {
            output << turtle.getIndex(i) << " ";
        }
    }
    output << "]";
    return output;
}
// ----------------------------------------------------------
/*
    boolean check equality operators
    contains boolean variable isTrue
    set up the condition
    return isTrue varaible
*/
bool TurtleProgram::operator == (const TurtleProgram& rhs) const {
    bool isTrue = true;
    if ( getLength() == rhs.getLength() ) {
        for ( int i = 0; i < getLength(); i++ ) {
            if ( arr[i] != rhs.arr[i] ) {
                isTrue = false;
            }
        }
    } else {
        isTrue = false;
    }
    return isTrue;
}
// ---------------------------------------------------------
/*
    boolean check inequality operator
    contains boolean variabel isFalse
    set up the condition
    return boolean variable
*/ 
bool TurtleProgram::operator != (const TurtleProgram& rhs) const {
    bool isFalse = false;
    if ( getLength() == rhs.getLength() ) {
        for ( int i = 0; i < getLength(); i++ ) {
            if ( arr[i] != rhs.arr[i] ) {
                isFalse = true;
            }
        }
    } else {
        isFalse = true;
    }
    return isFalse;
}
// -------------------------------------------------------------
/*
    Assignment operator
    delete if previous data exist
    handle the length of the data
    deep copy the data
    return the deep copied data
*/
TurtleProgram& TurtleProgram::operator = (const TurtleProgram& rhs) {
    if (this == &rhs) {
        return *this;
    }
    if ( length ) {
        delete [] arr;
    }
    arr = nullptr;
    length = rhs.length;
    if ( rhs.length ) {
        arr = new std::string[rhs.length];
    } else {
        arr = nullptr;
    }
    for ( int i = 0; i < length; i++ ) {
        arr[i] = rhs.arr[i];
    }
    return *this;
}
// ----------------------------------------------------------------------
/*
    Addition operator
    create temporary obj
    delete the previous data just in case
    add up the length to make space
    assign the data
    return the temp obj data
*/
TurtleProgram TurtleProgram::operator + (const TurtleProgram& rhs) const {
    TurtleProgram result;
    delete [] result.arr;
    result.length = getLength() + rhs.getLength();
    result.arr = new std::string[result.getLength()];
    for ( int i = 0; i < getLength(); i++ ) {
        result.setIndex(i, getIndex(i));
    }
    for ( int i = getLength(); i < result.getLength(); i++ ) {
        result.setIndex(i, rhs.getIndex(i - getLength()));
    }
    return result;
}
// --------------------------------------------------------------------
/*
    Addition assignment operator
    used operator +
    return the modified data
*/
TurtleProgram TurtleProgram::operator += (const TurtleProgram& rhs) {
    *this = (*this + rhs);
    return *this;
}
// --------------------------------------------------------------------
/*
    Multiplication operator
    create temp obj
    take as const
    check the parameter is valid or not
    check the arr contains data or not
    used if and else statement instead of try and catch
    reutnr the temp obj
*/
TurtleProgram TurtleProgram::operator * (const int times) const {
    TurtleProgram result;
    if ( times > 0 && this->arr != nullptr ) {
        for ( int i = 0; i < times; i++ ) {
            result += *this;
        }
    } else {
        std::cout << "Multiplication has to be bigger than 0" << std::endl;
    }
    return result;
}
// ----------------------------------------------------------------------
/*
    Multiplication assignment operator
    const parameter
    check the parameter valid
    if not valid jsut return the original without modidy
    if valid modify and return
*/
TurtleProgram& TurtleProgram::operator *= (const int times) {
    if ( (times > 0) && (this->arr != nullptr) ) {
        *this = (*this * times);
    }
    return *this;
}
