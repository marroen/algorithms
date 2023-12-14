#include "dfs.h"
#include <iostream>

using namespace std;

// For (un)directed graphs
void dfs(ImmutableGraph graph, ImmutableVertex vertex) {
  vertex.discover();
  cout << vertex.getData() << " discovered\n"; 
  for (ImmutableVertex const& neighbor : vertex.getNeighbors()) {
    if (!neighbor.isDiscovered())
      dfs(graph, neighbor);
  }
}

void testDfs() {
  ImmutableGraph graph = createTestGraph();
  for (ImmutableVertex const& vertex : graph.getVertices()) {
    dfs(graph, vertex);
  }
}
