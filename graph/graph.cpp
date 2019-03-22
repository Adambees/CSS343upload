#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <functional>
#include <vector>
#include "graph.h"

using namespace std;

Graph::Graph(bool directionalEdges) {
  direction = directionalEdges;
}
// =================== Deconstructor =======================
// delete all
// loop through delete
Graph::~Graph() {
  for (map<string, Vertex*>::iterator itr_first = vertices.begin(),
  itr_end = vertices.end();
  itr_first != itr_end; itr_first++) {
    delete itr_first->second;
  }
  vertices.clear();
}
// =================Number of Vertices ====================
// return number of vertices
// use map size
int Graph::NumberOfVertices() const {
  int numberOfVertice = vertices.size();
  return numberOfVertice;
}
// ========================Number of Edges ======================
// return number of edges
// const iterator const f
// use map size
int Graph::NumberOfEdges() const {
  int numberOfEdge = 0;
  map<string, Vertex*>::const_iterator itr;
  for ( itr = vertices.begin(); itr != vertices.end(); itr++ ) {
    Vertex * tempVer = itr->second;
    numberOfEdge += tempVer->startEdge.size();
  }
  return numberOfEdge;
}
// ==========================Has Vertex =========================
/** return true if vertex already in graph */
// used map count
// count not zero return true
// else return false
bool Graph::HasVertex(const std::string &label) const {
  if (vertices.count(label) > 0) {
    return true;
  } else {
    return false;
  }
}
// ================number of edges ===============
// @param label string
// use hasvertex function
// use map find(), size()
// return -1 if hasvertex is false
// return num edge
int Graph::NumberOfEdges(const string &label) const {
  if (!HasVertex(label)) {
    return -1;
  } else {
    int numberOfEdge = 0;
    Vertex * tempVertex = vertices.find(label)->second;
    numberOfEdge = tempVertex->startEdge.size();
    return numberOfEdge;
  }
}
// =====================Add Vertex ===================
// add vertex
// return true if add
// return false if fail to add (exist in graph)
// use hasvertex true = false (no duplicate)
bool Graph::AddVertex(const string &label) {
  if (HasVertex(label)) {
    return false;
  }
  if (!HasVertex(label)) {
    Vertex * newVertex = new Vertex;
    newVertex->vertexLabel = label;
    vertices[label] = newVertex;
    return true;
  }
}

// =================Get Edges ========================
// use iter
// use hasvertex if no just return ""
// map erase
// loop though iteration and add it to edge and return it
// careful with the space
string Graph::GetEdges(const string &label) const {
  string edges = "";
  if (!HasVertex(label)) {
    return edges;
  }
  if (NumberOfEdges(label) <= 0) {
    return edges;
  }
  if (HasVertex(label)) {
    Vertex * tempVer = vertices.at(label);
    map<string, int>::iterator iter1 = tempVer->startEdge.begin();
    map<string, int>::iterator iter2 = tempVer->startEdge.end();
    string firstResult;
    string secondResult;
    for ( iter1; iter1 != iter2; iter1++ ) {
      firstResult = iter1->first;
      secondResult = "(" + to_string(iter1->second) + "),";
      edges += firstResult + secondResult;
    }
    edges.erase(edges.end()-1);
    return edges;
  }
}

// =====================Connect==================================
// add edge between labels
// vertex cannot be connect to itself return false
// if two label is different
// use map at function
// if Vertices does not exist add them (use addvertex)
// check all situation
// check if already connected
// return true
bool Graph::Connect(const string &fromLabel,
                    const string &toLabel, int edgeWeight) {
  if (fromLabel == toLabel) {
    return false;
  }
  Vertex * from;
  Vertex * end;
  if (fromLabel != toLabel) {
    AddVertex(fromLabel);
    AddVertex(toLabel);
    if (HasVertex(fromLabel)) {
      from = vertices.at(fromLabel);
    }
    if (HasVertex(toLabel)) {
      end = vertices.at(toLabel);
    }
    if (from->startEdge.count(toLabel) > 0) {
      return false;
    }
    if (!direction) {
      from->startEdge[toLabel] = edgeWeight;
      end->startEdge[fromLabel] = edgeWeight;
    } else {
      from->startEdge[toLabel] = edgeWeight;
    }
    return true;
  } else {
    return false;
  }
}
// ==============DisConnect =======================
// remove edge from graph
// if label are same does not make sense false
// check count
// return true if delete
// else just retun false
bool Graph::Disconnect(const string &fromLabel, const string &toLabel) {
  if (fromLabel == toLabel) {
    return false;
  }
  if (fromLabel != toLabel) {
    Vertex * tempVer1 = vertices.at(fromLabel);
    Vertex * tempVer2 = vertices.at(toLabel);
    if (!direction) {
      if (tempVer1->startEdge.count(toLabel) == 1
      && tempVer2->startEdge.count(toLabel) == 1) {
        tempVer1->startEdge.erase(toLabel);
        tempVer2->startEdge.erase(fromLabel);
        return true;
      }
    } else if (direction) {
      if (tempVer1->startEdge.count(toLabel) == 1
      && tempVer2->startEdge.count(fromLabel) != 1) {
        tempVer1->startEdge.erase(toLabel);
        return true;
      } else {
        return false;
      }
    }
  } else {
    return false;
  }
}
// =================DFS ===============
// call recursive function
// private function
// use set clear function
void Graph::DFS(const string &startLabel, void visit(const string &)) {
  visited.clear();
  dfsHelper(startLabel, visit);
}

// Incomplete
void Graph::BFS(const string &startLabel, void visit(const string &)) {
  visited.clear();
  queue<string> myQueue;
  if (HasVertex(startLabel)) {
    myQueue.push(startLabel);
    while (!myQueue.empty()) {
      string popped = myQueue.front();
      myQueue.pop();
      visit(popped);
    }
  }
}

// Incomplete
// store the weights in a map
// store the previous label in a map
void Graph::Dijkstra(const string &startLabel,
                     map<string, int> &weights,
                     map<string, string> &previous) const {
  // TODO(me)
}

/**
 * minimum spanning tree
 * @param function to be called on each edge
 * @return length of the minimum spanning tree or -1 if start vertex not found
 * Incomplete
 */
int Graph::MST(const string &startLabel,
               void visit(const string &from,
                          const string &to, int weight)) const {
  // TODO(me)
  return 0;
}

bool Graph::ReadFile(const string &filename) {
  ifstream myfile(filename);
  if (!myfile.is_open()) {
    cerr << "Failed to open " << filename << endl;
    return false;
  }
  int edges, weight;
  string fromVertex, toVertex;
  myfile >> edges;
  for (int i = 0; i < edges; ++i) {
    myfile >> fromVertex >> toVertex >> weight;
    Connect(fromVertex, toVertex, weight);
  }
  myfile.close();
  return true;
}
// ==============dfs helper ==================
// helper for dfs function
// recursive function
// Hasvertex
void Graph::dfsHelper(const string &startLabel, void visit(const string &)) {
  if (HasVertex(startLabel)) {
    // bool visitFond = visited.count(startLabel) != 0;
    Vertex * tempVer = vertices.at(startLabel);
    if (!(visited.count(startLabel) != 0)) {
      visit(startLabel);
      visited.insert(startLabel);
      map<string, int>::iterator itr1 = tempVer->startEdge.begin();
      map<string, int>::iterator itr2 = tempVer->startEdge.end();
      for (itr1; itr1 != itr2; itr1++) {
        string second = itr1->first;
        if (!(visited.count(second) != 0)) {
          DFS(second, visit);
        }
      }
    }
  }
}
