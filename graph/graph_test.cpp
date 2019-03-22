/**
 * Testing ass3 graph functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include <iostream>
#include <map>
#include <sstream>
#include <cassert>

#include "graph.h"

using namespace std;

/**
 * Trying to avoid global variables,
 * by creating a singleton class with our visitor functions
 * stringstream SS contains the output from visitor
 */
class Tester {
 public:
  Tester() = delete;

  // insert output to SS rather
  // than cout, so we can test it
  static stringstream SS;

  static string GetSS() {
    return SS.str();
  }

  static void ResetSS() {
    SS.str(string());
  }

  // visitor function used for DFS and BFS
  static void labelVisitor(const string &label) {
    SS << label;
  }

  // visitor function used for edges for minimum spanning tree
  static void edgeVisitor(const string &from, const string &to, int weight) {
    SS << "[" << from << to << " " << weight << "]";
  }
};

// initialize the static variable
stringstream Tester::SS;

// convert a map to a string so we can compare it
template<typename T>
static string map2string(const map<string, T> &mp) {
  stringstream ss;
  for (auto &p : mp) {
    ss << "[" << p.first << ":" << p.second << "]";
  }
  return ss.str();
}

void testGraphBasic() {
  Graph g;
  bool bresult = g.AddVertex("a");
  assert(bresult);
  bresult = g.AddVertex("b");
  assert(bresult);
  bresult = g.AddVertex("c");
  assert(bresult);
  bresult = g.AddVertex("d");
  assert(bresult);
  bresult = g.AddVertex("e");
  assert(bresult);
  // duplicate add
  bresult = g.AddVertex("b");
  assert(!bresult);
  cout << "Adding Pass?" << endl;
  bresult = g.Connect("a", "b", 10);
  assert(bresult);
  // duplicate connect a b
  bresult = g.Connect("a", "b", 50);
  assert(!bresult);
  cout << "Duplicate add check pass?" << endl;
  // self connect
  bresult = g.Connect("a", "a", 1);
  assert(!bresult);
  cout << "Self Connect pass?" << endl;
  g.Connect("a", "d", 40);
  g.Connect("a", "c", 20);
  cout << "Connecting Pass?" << endl;
  assert(g.NumberOfVertices() == 5);
  assert(g.NumberOfEdges() == 3);
  assert(g.NumberOfEdges("a") == 3);
  cout << "num vertices, edge, edge() pass?" << endl;
  // no outgoing edges c
  assert(g.NumberOfEdges("c") == 0);
  // no edges for nonexistent vertex
  assert(g.NumberOfEdges("xxx") == -1);
  assert(!g.HasVertex("xxxx"));
  assert(g.HasVertex("a"));
  cout << "HasVertex should be pass" << endl;
  // check that they are sorted based on edge end label
  string result = "b(10),c(20),d(40)";
  assert(g.GetEdges("a") == result);
  cout << "GetEdge pass?" << endl;
  // disconnect non-existent edge/vertex
  assert(!g.Disconnect("a", "e"));
  cout << "disconnect pass?" << endl;
  assert(g.NumberOfEdges() == 3);
  assert(g.Disconnect("a", "c"));
  assert(g.NumberOfEdges() == 2);
  assert(g.NumberOfEdges("a") == 2);
  // removing middle edge
  result = "b(10),d(40)";
  assert(g.GetEdges("a") == result);
  cout << "testGraphBasic()" << endl;
}

void testGraph0DFS() {
  cout << "testGraph0DFS" << endl;
  Graph g;
  if (!g.ReadFile("graph0.txt"))
    return;
  assert(g.HasVertex("A"));
  assert(g.HasVertex("B"));
  assert(g.HasVertex("C"));
  cout << "test has vertex dfs" << endl;
  string result = "B(1),C(8)";
  assert(g.GetEdges("A") == result);
  result = "C(3)";
  assert(g.GetEdges("B") == result);
  result = "";
  assert(g.GetEdges("C") == result);
  cout << "test getedge" << endl;

  Tester::ResetSS();
  g.DFS("A", Tester::labelVisitor);
  result = "ABC";
  assert(Tester::GetSS() == result);

  Tester::ResetSS();
  g.DFS("B", Tester::labelVisitor);
  result = "BC";
  assert(Tester::GetSS() == result);

  Tester::ResetSS();
  g.DFS("C", Tester::labelVisitor);
  result = "C";
  assert(Tester::GetSS() == result);

  Tester::ResetSS();
  g.DFS("X", Tester::labelVisitor);
  result = "";
  assert(Tester::GetSS() == result);
  cout << "dfs test 1 done?" << endl;
}

void testGraph0BFS() {
  cout << "testGraph0BFS" << endl;
  Graph g;
  if (!g.ReadFile("graph0.txt"))
    return;
  Tester::ResetSS();
  g.BFS("A", Tester::labelVisitor);
  string result = "ABC";
  assert(Tester::GetSS() == result);

  Tester::ResetSS();
  g.DFS("B", Tester::labelVisitor);
  result = "BC";
  assert(Tester::GetSS() == result);

  Tester::ResetSS();
  g.DFS("C", Tester::labelVisitor);
  assert(Tester::GetSS() == result);

  Tester::ResetSS();
  g.DFS("X", Tester::labelVisitor);
  result = "";
  assert(Tester::GetSS() == result);
}

void testGraph0Dijkstra() {
  cout << "testGraph0Dijkstra" << endl;
  Graph g;
  if (!g.ReadFile("graph0.txt"))
    return;
  map<string, int> weights;
  map<string, string> previous;
  g.Dijkstra("A", weights, previous);
  // cout << "Dijkstra(A) weights is " << map2string(weights) << endl;
  string result = "[B:1][C:4]";
  assert(map2string(weights) == result);
  // cout << "Dijkstra(A) previous is " << map2string(previous) << endl;
  result = "[B:A][C:B]";
  assert(map2string(previous) == result);

  weights.clear();
  previous.clear();
  g.Dijkstra("B", weights, previous);
  result = "[C:3]";
  assert(map2string(weights) == result);
  result = "[C:B]";
  assert(map2string(previous) == result);

  weights.clear();
  previous.clear();
  g.Dijkstra("X", weights, previous);
  result = "";
  assert(map2string(weights) == result);
  assert(map2string(previous) == result);
}

void testGraph1() {
  cout << "testGraph1" << endl;
  Graph g;
  if (!g.ReadFile("graph1.txt"))
    return;
  Tester::ResetSS();
  g.DFS("A", Tester::labelVisitor);
  string result = "ABCDEFGH";
  assert(Tester::GetSS() == result);

  Tester::ResetSS();
  g.BFS("A", Tester::labelVisitor);
  result = "ABHCGDEF";
  assert(Tester::GetSS() == result);

  Tester::ResetSS();
  g.DFS("B", Tester::labelVisitor);
  result = "BCDEFG";
  assert(Tester::GetSS() == result);

  Tester::ResetSS();
  g.BFS("B", Tester::labelVisitor);
  result = "BCDEFG";
  assert(Tester::GetSS() == result);

  map<string, int> weights;
  map<string, string> previous;
  g.Dijkstra("A", weights, previous);
  result = "[B:1][C:2][D:3][E:4][F:5][G:4][H:3]";
  assert(map2string(weights) == result);
  result = "[B:A][C:B][D:C][E:D][F:E][G:H][H:A]";
  assert(map2string(previous) == result);
}

void testGraphAll() {
  testGraphBasic();
  testGraph0DFS();
  //  testGraph0BFS();
  //  testGraph0Dijkstra();
  //  testGraph1();
}
