#include <bits/stdc++.h>
using namespace std;

// Vertices are denoted by numbers (no 2 distinct vertices will have the same value)
// Two unsorted sequences, one for vertices, one for edges

struct edge
{
  int start;
  int end;
  int weight;

  edge(int start, int end, int weight = 1) : start(start), end(end), weight(weight){};
};

struct graph
{
  vector<int> vertices;
  vector<edge> edges;

  bool vertexExists(int v)
  {
    return find(vertices.begin(), vertices.end(), v) != vertices.end();
  }

  bool edgeExists(int start, int end)
  {
    for (int i = 0; i < edges.size(); i++)
      if (edges[i].start == start && edges[i].end == end)
        return true;
    return false;
  }

  void addVertex(int v)
  {
    if (!vertexExists(v))
      vertices.push_back(v);
  }

  void addEdge(int start, int end)
  {
    if (!edgeExists(start, end) && vertexExists(start) && vertexExists(end))
      edges.push_back(edge(start, end));
  }

  void printGraph()
  {
    cout << "Vertices\n";
    for (auto x : vertices)
      cout << x << " ";
    cout << "\n\n";

    cout << "Edges\n";
    for (auto x : edges)
      cout << x.start << " -> " << x.end << endl;
  }
};

int main()
{
  // Default edge weight is 1

  graph g;
  g.addVertex(0);
  g.addVertex(1);
  g.addVertex(2);
  g.addVertex(3);
  g.addVertex(4);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.printGraph();
}