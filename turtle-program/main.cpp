/**
 * main.cpp is not used all test cases are in xxxcatch.cpp files
 * used using namespace std
 * manage the test case that is in turtleprogramcatch.cpp
 * mamage the general output
 * general output contains all the testes too
 * @author Jun Hyung Park
 * @date Jan 15 2019
 */


#include <iostream>
#include "turtleprogram.h"

using namespace std;

// forward declaration, implementation in turtle
// testTurtleAll function located in turtleprogramcatch.cpp
void testTurtleAll();

/**
 * Contains print the output
 * Contains no parameter constructor
 * Contains 1 parameter consturctor
 * Contains 2 parameter constructor
 * Contain addition and addition assignment operator
 * Contain multiplication and its assignment operator
 * Contain copy constructor and assignment operator
 * Contain bool operator inequality and equality
 */

int main() {
  testTurtleAll();
  cout << "***Finish Assert***" << endl;
  cout << "** Just Display Output Turtle Output ***" << endl;
  TurtleProgram tp1;
  cout << "tp1: " << tp1 << endl;
  TurtleProgram tp2("F", "10");
  cout << "tp2: " << tp2 << endl;
  TurtleProgram tp3("R", "90");
  tp1 = tp2 + tp3;
  cout << "tp1 now as tp2+tp3: " << tp1 << endl;
  tp1 = tp2 * 3;
  cout << "tp1 now as tp2 * 3: " << tp1 << endl;
  TurtleProgram tp4(tp1);
  cout << "tp4 is a copy of tp1: " << tp4 << endl;
  TurtleProgram tp5("F", "10");
  cout << "tp5: " << tp5 << endl;
  cout << boolalpha;
  cout << "tp2 and tp5 are == " << (tp2 == tp5) << endl;
  cout << "tp2 and tp3 are != " << (tp2 != tp3) << endl;
  cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
  tp2.setIndex(0, "R");
  tp2.setIndex(1, "90");
  cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
  cout << "tp2 and tp3 are == " << (tp2 == tp3) << endl;
  TurtleProgram tp10("E");
  cout << "Tp10: " << tp10 << endl;
  TurtleProgram tp11 = tp10;
  cout << "Tp11: " << tp11 << endl;
  tp1 += tp1;
  cout << "Super Tp1: " << tp1 << endl;
  TurtleProgram tp12("C", "10");
  tp12 *= 2;
  cout << "tp12: " << tp12 << endl;
  tp12 *= 4;
  cout << "tp12: " << tp12 << endl;
  cout << "Done" << endl;
  return 0;
}
