#pragma once
#include <set>

using namespace std;

class ImmutableVertex;

struct compare;

class ImmutableVertex {
  private:
    int v_data;
    int v_discovered = false;
    set<ImmutableVertex> v_neighbors{};
  public:
    ImmutableVertex(int data);
    int getData() const { return v_data; }
    void discover() { v_discovered = true; }
    void undiscover() { v_discovered = false; }
    bool isDiscovered() const { return v_discovered; }
    void setNeighbors(set<ImmutableVertex> neighbors);
    set<ImmutableVertex> getNeighbors() const { return v_neighbors; }    
    friend bool operator< (const ImmutableVertex &a, const ImmutableVertex &b);
    friend bool operator== (const ImmutableVertex &a, const ImmutableVertex &b);
};

class ImmutableGraph {
  private:
    set<ImmutableVertex> g_vertices{};
    set<pair<ImmutableVertex, ImmutableVertex>> g_edges{};
  public:
    ImmutableGraph(set<ImmutableVertex> vertices, set<pair<ImmutableVertex, ImmutableVertex>> edges);
    set<ImmutableVertex> getVertices() const { return g_vertices; }
    set<pair<ImmutableVertex, ImmutableVertex>> getEdges() const { return g_edges; }
    bool adjacent(ImmutableVertex x, ImmutableVertex y);
    set<ImmutableVertex> neighbors(ImmutableVertex x);
    void print();
};

ImmutableGraph createTestGraph();
void testGraph();

