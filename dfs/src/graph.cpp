#include "graph.h"
#include <iostream>

using namespace std;

struct compare {
  bool operator() (const ImmutableVertex &a, const ImmutableVertex &b) const;
};

bool operator< (const ImmutableVertex &a, const ImmutableVertex &b) {
  return a.getData() < b.getData();
}

bool operator== (const ImmutableVertex &a, const ImmutableVertex &b) {
  return a.getData() == b.getData();
}

ImmutableVertex::ImmutableVertex(int data) {
  v_data = data;
}

void ImmutableVertex::setNeighbors(set<ImmutableVertex> neighbors) {
  v_neighbors = neighbors;
}

ImmutableGraph::ImmutableGraph(set<ImmutableVertex> vertices, set<pair<ImmutableVertex, ImmutableVertex>> edges) {
  g_vertices = vertices;
  g_edges = edges;
}

void ImmutableGraph::print() {
  set<pair<ImmutableVertex, ImmutableVertex>> edges = getEdges();
  set<int> visited;
  
  cout << "Graphical representation only works with n edges per vertex where n == 2 only once per graph\n";
  cout << "All edges: \n";
  for (pair<ImmutableVertex, ImmutableVertex> const& edge : edges) {
    int firstData = edge.first.getData();
    int secondData = edge.second.getData();
    if ( visited.find(firstData) == visited.end() && visited.find(secondData) == visited.end() ) {
      cout << firstData << '-' << secondData << "\n";
      visited.insert(firstData);
      visited.insert(secondData);
      continue;
    }
    if ( visited.find(firstData) != visited.end() ) {
      cout << ' ' << '\\' << "\n" << ' ' << ' ' << secondData << "\n";
      visited.insert(secondData);
      continue;
    }
    if ( visited.find(secondData) != visited.end() ) {
      cout << ' ' << '/' << "\n" << firstData << "\n";
      visited.insert(firstData);
      continue;
    }
  }

  cout << "All vertices: \n";
  int i = 0;
  for (ImmutableVertex const& vertex : getVertices()) {
    cout << vertex.getData() << ' ';
    if (!(i % 2 == 0)) cout << "\n";
    i++;
  }
}

// Undirected
ImmutableGraph createTestGraph() {
  ImmutableVertex vertex1 = ImmutableVertex(1);
  ImmutableVertex vertex3 = ImmutableVertex(3);
  ImmutableVertex vertex5 = ImmutableVertex(5);
  ImmutableVertex vertex7 = ImmutableVertex(7);
  set<ImmutableVertex> vertices = { vertex1, vertex3, vertex5, vertex7 };
  set<pair<ImmutableVertex, ImmutableVertex>> edges;

  // Edge 1 - 5
  vertex1.setNeighbors({vertex5});
  vertex5.setNeighbors({vertex1});
  edges.insert(pair(vertex1, vertex5));

  // Edge 1 - 7
  vertex1.setNeighbors({vertex7});
  vertex7.setNeighbors({vertex1});
  edges.insert(pair(vertex1, vertex7));

  // Edge 3 - 7
  vertex3.setNeighbors({vertex7});
  vertex7.setNeighbors({vertex3});
  edges.insert(pair(vertex3, vertex7));

  return ImmutableGraph(vertices, edges);
}

void testGraph() {
  ImmutableGraph graph = createTestGraph();
  graph.print();
}
