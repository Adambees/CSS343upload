/**
 * CSS 343 Assignemt 1
 * Assignment contains Public Functions of 
 * Three Constructor and One Copy constructor
 * Single Deconstrutor
 * Output Operator
 * Check equality operators
 * Addition and Addition Assignemnt operator
 * Multiplication and Multiplication Assignment operator
 * Get Index, Set Index and get Length
 * As Private, contains array and length
 * @author Jun Hyung Park
 * @date Jan 15 2018
 */

#ifndef TURTLEPROGRAM_H
#define TURTLEPROGRAM_H

#include <iostream>
#include <string>

class TurtleProgram {
    // Insertion Operator <<
friend std::ostream& operator<< (std::ostream&, const TurtleProgram&);

 private:
int length;
std::string* arr;

 public:
// Constructor with no parameter
TurtleProgram();
// Copy Constructor
TurtleProgram(const TurtleProgram& copy);
// Constructor with One Parameter
explicit TurtleProgram(const std::string& a);
// Constructor with two Parameter
TurtleProgram(const std::string& a, const std::string& b);
// Deconstructor
~TurtleProgram();
// Operators
// Equality operator
bool operator==(const TurtleProgram& rhs) const;
// Inequality operator
bool operator!=(const TurtleProgram& rhs) const;
// Copy assignment operator
TurtleProgram& operator=(const TurtleProgram& rhs);
// Addition operator
TurtleProgram operator+(const TurtleProgram& rhs) const;
// Addition assignment operator
TurtleProgram operator+=(const TurtleProgram& rhs);
// Multiplication operator
TurtleProgram operator*(const int times) const;
// Multiplication assignment operator
TurtleProgram& operator*=(const int times);
// get Length
int getLength() const;
// get index
const std::string& getIndex(int idx) const;
// set index
void setIndex(int idx, const std::string& newValue);
};

#endif  // TURTLEPROGRAM_H
