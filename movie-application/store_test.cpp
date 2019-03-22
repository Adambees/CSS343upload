/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <cassert>
#include "storeManager.h"

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;
  string cfile = "data4movies.txt";
  stringstream out;
  ifstream fs(cfile);
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  // cout << out.str() << endl;
  string result = "CCCFDDDFFDDFFFDDCZCCCCCCCZCCCFDF";
  assert(out.str() == result);
  cout << "End testStore2" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  ifstream infile1("data4movies.txt");
  ifstream infile2("data4commands.txt");
  ifstream infile3("data4customers.txt");
  StoreManager store;
  store.buildStore(infile1, infile3);
  store.readCommand(infile2);
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  cout << endl;
  testStore2();
  cout << endl;
  testStoreFinal();
}
