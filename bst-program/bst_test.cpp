/**
 * Testing BST - Binary Search Tree functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

#include "bst.hpp"

using namespace std;

/**
 * Trying to avoid global variables,
 * by creating a singleton class with our visitor functions
 * stringstream SS contains the output from visitor
 */
class TreeVisitor {
 public:
  TreeVisitor() = delete;

  // insert output to SS rather than cout, so we can test it
  static stringstream SS;

  static string GetSS() {
    return SS.str();
  }

  static void ResetSS() {
    SS.str(string());
  }
  // instead of cout, insert item into a string stream
  static void visitor(const string &item) {
    SS << item;
  }

  // instead of cout, insert item into a string stream
  static void visitor(const int &item) {
    SS << item;
  }
};

// initialize the static variable
stringstream TreeVisitor::SS;

void testBSTConstructors() {
  cout << "\n\n* Testing 0 param constructor, ==, !=, IsEmpty, and XTraverse"
       << endl;
  BST<string> b1;
  BST<string> b2;
  BST<string> b3;
  // == and != for empty trees
  assert(b1 == b2 && (!(b1 != b2)));
  b1.Add("c");
  b2.Add("c");
  b3.Add("b");
  // == and !- for 1-node trees b1, b2, b3
  assert(b1 == b2 && (!(b1 != b2)));
  assert(b1 != b3 && (!(b1 == b3)));

  b1.Add("a");
  b1.Add("f");
  b1.Add("g");
  b1.Add("x");
  b2.Add("a");
  b2.Add("f");
  b2.Add("g");
  b2.Add("x");

  cout << "Done Adding" << endl;
  // == for 5-node trees b1, b2
  assert(b1 == b2 && (!(b1 != b2)));

  BST<string> b4(b3);
  // copy constructor for 1-node trees b3, b4
  assert(b3 == b4 && (!(b3 != b4)));

  BST<string> b5(b1);
  // copy constructor for 5-node trees b1, b5
  assert(b1 == b5 && (!(b5 != b1)));

  BST<string> b7("b");
  // 1-param constructor for 1-node trees b3, b7
  assert(b3 == b7 && (!(b3 != b7)));

  cout << "Done Copy Constructor" << endl;

  cout << "b1 is: " << endl;
  cout << b1 << endl;

  TreeVisitor::ResetSS();
  b1.InorderTraverse(TreeVisitor::visitor);
  string result = "acfgx";
  assert(TreeVisitor::GetSS() == result);
  cout << "Inorder Pass" << endl;

  TreeVisitor::ResetSS();
  b1.PreorderTraverse(TreeVisitor::visitor);
  result = "cafgx";
  assert(TreeVisitor::GetSS() == result);
  TreeVisitor::ResetSS();

  cout << "Preorder Pass" << endl;

  b1.PostorderTraverse(TreeVisitor::visitor);
  result = "axgfc";
  assert(TreeVisitor::GetSS() == result);

  cout << "Postorder pass" << endl;

  cout << "Done testBSTConstructors" << endl;
}

void test_jhpp114() {
  cout << "Starting test_jhpp114" << endl;
  cout << "Test add, numberOfNode function" << endl;
  BST<int> b1;
  b1.Add(1);
  assert(b1.NumberOfNodes() == 1);
  b1.Add(2);
  b1.Add(3);
  b1.Add(4);
  b1.Add(5);
  b1.Add(6);
  assert(b1.Contains(1));
  assert(b1.Contains(2));
  assert(b1.Contains(6));
  assert(!b1.Contains(8));
  cout << "Contain pass" << endl;
  assert(b1.NumberOfNodes() == 6);
  cout << "Pass number of nodes" << endl;
  assert(b1.getHeight() == 6);
  cout << "Testing isEmpty, clear, != operator" << endl;
  cout << "Pass Get Height" << endl;
  assert(b1.IsEmpty() == 0);
  cout << "Pass isEmpty" << endl;
  b1.Clear();
  assert(b1.IsEmpty() == 1);
  assert(b1.NumberOfNodes() == 0);
  cout << "Pass clear" << endl;
  BST<int> b2;
  b2.Add(1);
  assert(b1 != b2);
  cout << "pass !=" << endl;
  cout << "Ending test_jhpp114" << endl;
}

/*
  From igthub ass2-bst-test.cpp
  lizz
*/
void test_lizzypld() {
    // create local scope array
    string arr[6]{"a", "b", "c", "x", "y", "z"};
    // construct tree
    BST<string> arrayTree1(arr, 6);
    cout << "Pass arr" << endl;
    // test that array is not empty
    assert(!arrayTree1.IsEmpty());
    // test that array has all 6 items
    assert(arrayTree1.NumberOfNodes() == 6);
    // test that array is balanced correctly per assignment specifications
    assert(arrayTree1.getHeight() == 3);
    cout << "arr contain" << endl;
    assert(arrayTree1.Contains("a"));
    cout << "Pass numnode, height, empty" << endl;
    // create another tree from same array
    BST<string> arrayTree2(arr, 6);
    // test that 2nd array is not empty
    assert(!arrayTree2.IsEmpty());
    // test that 2nd array has all 6 items
    assert(arrayTree2.NumberOfNodes() == 6);
    // test that 2nd array is balanced correctly per assignment specifications
    assert(arrayTree2.getHeight() == 3);
    // confirm that the two trees are identical
    assert(arrayTree1 == arrayTree2);
    assert(!(arrayTree1 != arrayTree2));
    cout << "pass arr equality" << endl;
}
/*
// Test_iqbalo01
// From github
*/
void test_iqbalo01() {
    cout << "Starting test_iqbalo01" << endl;
    BST<int> tree1;
    BST<int> tree2;

    tree1.Add(3);
    tree1.Add(2);
    tree1.Add(4);
    tree1.Add(1);
    tree1.Add(6);
    tree1.Add(8);
    tree1.Add(5);
    cout << "Done adding number tree1" << endl;
    tree2.Add(3);
    tree2.Add(2);
    tree2.Add(4);
    tree2.Add(1);
    tree2.Add(6);
    tree2.Add(8);
    tree2.Add(5);
    cout << "Done adding numbers tree2" << endl;

    assert(tree1.IsEmpty() == false);
    assert(tree1 == tree2);
    tree1.Remove(3);
    assert(tree1 != tree2);
    cout << "Ending test_iqbalo01" << endl;
}
/*
  // github from reavsneha
*/
void test_ravsneha() {
  cout << "SNEHA'S TESTS ARE STARTING" << endl;
  BST<string> b1;
  b1.Add("s");
  b1.Add("n");
  b1.Add("e");
  b1.Add("h");
  b1.Add("a");

  BST<string> b2;
  b2.Add("s");
  b2.Add("n");
  b2.Add("e");
  b2.Add("h");
  b2.Add("a");
  // Print th
  cout << b1 << endl;
  cout << b2 << endl;
  cout << "Testing Equals Operator (true)" << endl;
  bool testBool = (b1 == b2);
  assert(testBool == true);
  cout << "Testing Remove (true)" << endl;
  bool testBool1 = b1.Remove("a");
  cout << b1 << endl;
  assert(testBool1 == true);
  cout << "Testing Equals Operator (false)" << endl;
  bool testBool2 = (b1 == b2);
  assert(testBool2 == false);
  cout << "SNEHA'S TESTS ARE COMPLETE" << endl;
}
/*
  // test_jstwe 701 from github
*/
void test_jstew701() {
  cout << "Starting test_jstew701" << endl;
  cout << "* Testing Add, Contains, and Clear" << endl;
  BST<string> b1;
  BST<string> b2;
  b1.Add("a");
  b1.Add("f");
  b1.Add("g");
  b1.Add("x");
  b2.Add("c");
  b2.Add("a");
  b2.Add("e");
  b2.Add("d");
  assert(b1.Contains("a"));
  assert(b1.Contains("f"));
  assert(b1.Contains("g"));
  assert(b1.Contains("x"));
  assert(!(b1.Contains("z")));
  assert(b2.Contains("c"));
  assert(b2.Contains("a"));
  assert(b2.Contains("e"));
  assert(b2.Contains("d"));
  assert(!(b2.Contains("z")));
  b1.Clear();
  assert(b1.IsEmpty());
  cout << "Ending test_jstew701" << endl;
}
/*
  // test_hsoko18 from github
*/
void test_hsokol8() {
  cout << "test_hsoko18" << endl;
  BST<int> b1;
  BST<int> b2;
  assert(b1 == b2);
  b1.Add(4);
  assert(b1 != b2);
  b2.Add(4);
  assert(b1 == b2);
  b2.Add(4);
  assert(b1 == b2);
  b2.Remove(4);
  assert(b1 != b2);
  cout << "End hsoko18" << endl;
}
/*
// Test_biryua
// From github
*/
void test_biryua() {
  BST<string> bt;
  // Removing when there's an empty BST
  bt.Remove("a");
  // Adding nodes
  bt.Add("q");
  bt.Add("u");
  bt.Add("i");
  bt.Add("c");
  bt.Add("k");
  bt.Add("l");
  bt.Add("y");
  assert(bt.NumberOfNodes() == 7);
  // Removing something that doesn't exist
  bt.Remove("z");
  assert(bt.NumberOfNodes() == 7);
  cout << "Check remvoe z and number node 7 pass" <<endl;
  // Removing all nodes individually
  bt.Remove("i");
  cout << "Pass i?" << endl;
  assert(bt.NumberOfNodes() == 6);
  cout << "Pass number of node corresponding with i" << endl;
  assert(!bt.Contains("i"));;
  cout << "Pass i" << endl;
  bt.Remove("q");
  cout << "Removed q" << endl;
  assert(bt.NumberOfNodes() == 5);
  cout << "number node 5 pass" << endl;
  assert(!bt.Contains("q"));
  cout << "Contain q pass?" << endl;
  bt.Remove("c");
  bt.Remove("l");
  bt.Remove("u");
  bt.Remove("y");
  bt.Remove("k");
  assert(!(bt.Remove("C")));
  cout << "assert" << endl;
  cout << "Remove c,l,u,y,k pass" << endl;
  assert(bt.NumberOfNodes() == 0);
  cout << "number node == 0?" << endl;
  assert(bt.IsEmpty());
  cout << "Ending test_biryua" << endl;
}
void test_emilylk() {
    cout << "\n\n* Running test_emilylk" << endl;
    BST<string> e1;
    BST<string> e2;
    assert(e1 == e2 && (!(e1 != e2)));
    e1.Add("d");
    e1.Add("b");
    e1.Add("c");
    e1.Add("g");
    e1.Add("w");
    cout << "e1 is: " << endl;
    cout << e1 << endl;
    cout << "e3 is a copy of e1" << endl;
    BST<string> e3(e1);
    assert(e1.NumberOfNodes() == 5);
    assert(e1.getHeight() == 3);
    assert(e1 == e3 && (!(e1 != e3)));
    cout << "Remove c and w from e1" << endl;
    e1.Remove("c");
    e1.Remove("w");
    assert(e1 != e3 && (!(e1 == e3)));
    assert(e1.NumberOfNodes() == 3);
    assert(e1.getHeight() == 2);
    cout << "Clear e1" << endl;
    e1.Clear();
    assert(e1.IsEmpty());
    assert(!e3.IsEmpty());
    assert(e3.Contains("w") && e3.Contains("b"));
    cout << "test_emilylk done" << endl;
}
/*
  test philp12 contians rebalance
  from github
*/
void test_philip12() {
  BST<int> binary(10);
  binary.Add(5);
  binary.Add(15);
  binary.Add(7);
  binary.Add(13);
  binary.Add(3);
  binary.Add(17);
  binary.Add(2);
  binary.Add(12);
  binary.Add(1);
  cout << binary << endl;
  assert(binary.getHeight() == 5);
  assert(binary.NumberOfNodes() == 10);
  cout << "Remove 10" << endl;
  binary.Remove(10);
  assert(binary.NumberOfNodes() == 9);
  binary.Rebalance();
  cout << "Rebalancing" << endl;
  cout << binary << endl;
  binary.Clear();
  assert(binary.IsEmpty());
  cout << "test_philip12 done" << endl;
}

void testBSTAll() {
  testBSTConstructors();
  test_jhpp114();
  test_lizzypld();
  test_iqbalo01();
  test_ravsneha();
  test_jstew701();
  test_hsokol8();
  test_biryua();
  test_emilylk();
  test_philip12();
}
