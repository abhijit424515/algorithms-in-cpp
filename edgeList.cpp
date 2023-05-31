#include <bits/stdc++.h>
#include <queue>
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
private:
  vector<int> vertices;
  vector<edge> edges;

public:
  bool vertexExists(int v)
  {
    return find(vertices.begin(), vertices.end(), v) != vertices.end();
  }

  bool edgeExists(int start, int end)
  {
    if (start == end)
      return false;

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

  // assuming connected graph
  // assuming noOfVertices > 0
  void bfs(int startVertex = 0)
  {
    // base case
    if (!vertexExists(startVertex))
      return;

    // initialize data structures
    queue<int> pending;

    bool visited[vertices.size()];
    for (int i = 0; i < vertices.size(); i++)
      visited[i] = false;

    // first, mark off starting vertex as visited
    visited[startVertex] = true;
    // insert starting vertex in pending queue, so as to follow looping
    pending.push(startVertex);

    while (!pending.empty())
    {
      int currentVertex = pending.front();
      cout << currentVertex << endl;
      pending.pop();

      for (int i = 0; i < edges.size(); i++)
      {
        if (edges[i].start == currentVertex && !visited[edges[i].end])
        {
          int nextVertex = edges[i].end;
          visited[nextVertex] = true;
          pending.push(nextVertex);
        }
      }
    }
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
  g.bfs();
}