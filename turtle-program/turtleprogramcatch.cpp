/**
 * Test Cases for turtle program
 * Use assert
 * Contains Constructor test case
 * Contains equality test case
 * Contains math operator test case
 * @author Jun Hyung Park
 * @date Jan 15 2019
 */

#include <sstream>
#include <cassert>
#include "turtleprogram.h"

using namespace std;

// TODO(Park): Writing down the Test Cases
// TestConstructor
// Contains tests for Three Constructor
// Contains tests for getLength function
// Contains tests for setIndex function
// Contains tests for getIndex function
void testTurtleConstructor() {
    TurtleProgram tp1;
    TurtleProgram tp2("F", "10");
    TurtleProgram tp3("R", "90");
    TurtleProgram tp4("E");
    assert(tp1.getLength() == 0);
    assert(tp2.getLength() == 2);
    assert(tp3.getLength() == 2);
    assert(tp4.getLength() == 1);
    tp2.setIndex(0, "G");
    tp2.setIndex(1, "90");
    assert(tp2.getIndex(0) == "G");
    assert(tp2.getIndex(1) == "90");
    cout << "Constructor, getLength, setIndex, getIndex Pass" << endl;
}

// Test operator<<
// Test all three types of constructor prints
void testTurtleInsert() {
    ostringstream output;
    TurtleProgram tp5;
    operator<<(output, tp5);
    assert(output.str() == "[]");
    output.str("");
    TurtleProgram tp6("F", "10");
    operator<<(output, tp6);
    assert(output.str() == "[F 10]");
    output.str("");
    TurtleProgram tp7("E");
    operator<<(output, tp7);
    cout << "Ostream function had Pass" << endl;
}

// Test Math operators
// Contains test for addition operator
// Contains test for addition assignment operator
// Contains test for multiplication operator
// Contains test for multiplication assignment operator
void testTurtleMath() {
    TurtleProgram tp8("F", "10");
    TurtleProgram tp9("R", "90");
    TurtleProgram tp10 = tp8 + tp9;
    assert(tp10.getLength() == 4);
    assert(tp10.getIndex(0) == "F");
    assert(tp10.getIndex(1) == "10");
    assert(tp10.getIndex(2) == "R");
    assert(tp10.getIndex(3) == "90");
    tp8 += tp8;
    assert(tp8.getLength() == 4);
    assert(tp8.getIndex(0) == "F");
    assert(tp8.getIndex(1) == "10");
    assert(tp8.getIndex(2) == "F");
    assert(tp8.getIndex(3) == "10");
    TurtleProgram tp11("E");
    TurtleProgram tp12 = tp11 * 3;
    assert(tp12.getLength() == 3);
    assert(tp12.getIndex(0) == "E");
    assert(tp12.getIndex(1) == "E");
    assert(tp12.getIndex(2) == "E");
    tp11 *= 2;
    assert(tp11.getLength() == 2);
    assert(tp11.getIndex(0) == "E");
    assert(tp11.getIndex(1) == "E");
    cout << "Math Operator function Pass" << endl;
}

// Test Equality operator
// Contains test for equality ==
// Contains test for inequality !=
void testTurtleEquality() {
    TurtleProgram tp13;
    TurtleProgram tp14;
    TurtleProgram tp15("F", "10");
    TurtleProgram tp16("E", "10");
    TurtleProgram tp17("F", "10");
    assert(tp13 == tp14);
    assert(tp13 != tp15);
    assert(tp15 != tp16);
    assert(tp15 == tp17);
    cout << "Equaliy Test had Pass" << endl;
}

// wrap up All test functions
// to simplify
// and efficiency of calling just one function
// on main
void testTurtleAll() {
    testTurtleConstructor();
    testTurtleInsert();
    testTurtleMath();
    testTurtleEquality();
    cout << "All Test Pass" << endl;
}
