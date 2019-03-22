/**
 * A graph is made up of vertices and edges.
 * Vertex labels are unique.
 * A vertex can be connected to other vertices via weighted, directed edge.
 * A vertex cannot connect to itself or have multiple edges to the same vertex
 */

#ifndef ASS3_GRAPHS_GRAPH_H
#define ASS3_GRAPHS_GRAPH_H

#include <map>
#include <set>
#include <queue>
#include <string>

// vertex strcut for graph
typedef struct Vertex {
  std::string vertexLabel;
  std::map<std::string, int> startEdge;
} Vertex;

class Graph {
 public:
  /** constructor, empty graph */
  explicit Graph(bool directionalEdges = true);

  /** destructor, delete all vertices and edges */
  ~Graph();

  /**
   * @return total number of vertices
   * */
  int NumberOfVertices() const;

  /**
   * @return total number of edges
   * */
  int NumberOfEdges() const;

  /**
   * @param label
   * @return number of edges from given vertex, -1 if vertex not found
   * */
  int NumberOfEdges(const std::string &label) const;

  /**
   * Add a vertex to the graph, no duplicates allowed
   * @param label
   * @return true if vertex added, false if it already is in the graph
   * */
  bool AddVertex(const std::string &label);

  /**
   * @param label
   * @return true if vertex is in the graph
   * */
  bool HasVertex(const std::string &label) const;

  /**
   * Get edges of the vertex in a readable format
   * such as b(10),c(20),d(40)
   * @param label
   * @return string representing edges and weights, "" if vertex not found
   * */
  std::string GetEdges(const std::string &label) const;

  /**
   * Add a new edge between start and end vertex
   * If the vertices do not exist, create them
   * A vertex cannot connect to itself
   * or have multiple edges to the same vertex
   * @param fromLabel
   * @param toLabel
   * @param edgeWeight optional, defaults to 0
   * @return true if successfully connected
   * */
  bool Connect(const std::string &fromLabel,
               const std::string &toLabel, int edgeWeight = 0);

  /**
   * Remove edge from graph
   * @param fromLabel starting vertex label
   * @param edge ending vertex label
   * @return true if edge successfully deleted
   * */
  bool Disconnect(const std::string &fromLabel, const std::string &toLabel);

  /**
   * Read edges from file
   * first line of file is an integer, indicating number of edges
   * each line represents an edge in the form of "string string int"
   * vertex labels cannot contain spaces
   * @param filename
   * @return true if file successfully read
   * */
  bool ReadFile(const std::string &filename);

  /**
   * depth-first traversal starting from given startLabel
   * @param startLabel starting vertex label
   * @param visit function to be called on each vertex label
   * */
  void DFS(const std::string &startLabel, void visit(const std::string &));

  /** breadth-first traversal starting from startLabel
      call the function visit on each vertex label */
  /**
   * breadth-first traversal starting from given startLabel
   * @param starting vertex label
   * @param function to be called on each vertex label
   * */
  void BFS(const std::string &startLabel, void visit(const std::string &));

  /**
   * dijkstra's algorithm to find shortest distance to all other vertices
   * and the path to all other vertices
   * Path cost is recorded in the map passed in, e.g. weight["F"] = 10
   * How to get to vertex is recorded in map passed in, previous["F"] = "C"
   * @param starting vertex label
   * @param map of <string, int> to record shortest path to vertex
   * @param map of <string, string> to record previous node in path to vertex
   * */
  void Dijkstra(const std::string &startLabel,
                std::map<std::string, int> &weights,
                std::map<std::string, std::string> &previous) const;
  /**
   * minimum spanning tree
   * @param starting vertex label
   * @param function to be called on each edge
   * @return length of the minimum spanning tree or -1 if start vertex not found
   * */
  int MST(const std::string &startLabel,
          void visit(const std::string &from,
                     const std::string &to, int weight)) const;


 private:
    bool direction = false;
    // mapping vertex label quick and easy
    std::map<std::string, Vertex*> vertices;
    std::set<std::string> visited;
    void dfsHelper(const std::string &startLabel, void visit(const std::string &));
};

#endif  // ASS3_GRAPHS_GRAPH_H
