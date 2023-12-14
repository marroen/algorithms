#include <iostream>
#include "graph.h"
#include "dfs/dfs.h"

using namespace std;

int main() {
  cout << "\n" << "Testing graph implementation: \n";
  testGraph();
  cout << "\n" << "Testing DFS implementation: \n";
  testDfs();
}
