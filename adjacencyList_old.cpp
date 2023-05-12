#include <bits/stdc++.h>
using namespace std;

// Vertices are denoted by numbers (no 2 distinct vertices will have the same value)
// Adjacency list for each vertex, maintaining outgoing edges only

struct graph
{
  int V;
  vector<int> *adj;

  graph(int V) : V(V)
  {
    adj = new vector<int>[V];
  }

  void addEdge(int start, int end)
  {
    adj[start].push_back(end);
  }

  void printGraph()
  {
    for (int i = 0; i < V; i++)
    {
      cout << "|" << i
           << "|";
      for (auto x : adj[i])
        cout << " -> " << x;
      cout << endl;
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
}