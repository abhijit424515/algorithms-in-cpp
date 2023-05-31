#include <bits/stdc++.h>
using namespace std;

// Vertices are denoted by numbers (no 2 distinct vertices will have the same value)
// vertices are 0 to n-1
// Adjacency list for each vertex, maintaining outgoing edges only

struct graph
{
private:
  int noOfVertices;
  vector<int> *adj;

public:
  graph(int noOfVertices) : noOfVertices(noOfVertices)
  {
    adj = new vector<int>[noOfVertices];
  }

  bool vertexExists(int v)
  {
    return v >= 0 && v < noOfVertices;
  }

  bool edgeExists(int start, int end)
  {
    if (vertexExists(start))
      if (find(adj[start].begin(), adj[start].end(), end) != adj[start].end())
        return true;
    return false;
  }

  void addEdge(int start, int end)
  {
    adj[start].push_back(end);
  }

  void printGraph()
  {
    for (int i = 0; i < noOfVertices; i++)
    {
      cout << "|" << i
           << "|";
      for (auto x : adj[i])
        cout << " -> " << x;
      cout << endl;
    }
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

    bool visited[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
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

      for (int i = 0; i < adj[currentVertex].size(); i++)
      {
        if (!visited[adj[currentVertex][i]])
        {
          int nextVertex = adj[currentVertex][i];
          visited[nextVertex] = true;
          pending.push(nextVertex);
        }
      }
    }
  }
};

int main()
{
  graph g(5);
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