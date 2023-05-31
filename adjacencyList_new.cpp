#include <bits/stdc++.h>
using namespace std;

struct vertex
{
  int value;
  vector<int> outwards;

  vertex(int value) : value(value){};
};

struct graph
{
private:
  vector<vertex> adj;

  int findIndexOfVertex(int v)
  {
    for (int i = 0; i < adj.size(); i++)
      if (adj[i].value == v)
        return i;
    return -1;
  }

public:
  bool vertexExists(int v)
  {
    for (auto x : adj)
      if (x.value == v)
        return true;
    return false;
  }

  bool edgeExists(int start, int end)
  {
    int index = findIndexOfVertex(start);
    if (index == -1)
      return false;
    else
      return find(adj[index].outwards.begin(), adj[index].outwards.end(), end) != adj[index].outwards.end();
  }

  void addVertex(int v)
  {
    if (!vertexExists(v))
      adj.push_back(vertex(v));
  }

  void addEdge(int start, int end)
  {
    int index = findIndexOfVertex(start);
    if (index != -1)
      if (find(adj[index].outwards.begin(), adj[index].outwards.end(), end) == adj[index].outwards.end())
        adj[index].outwards.push_back(end);
  }

  void printGraph()
  {
    for (auto x : adj)
    {
      cout << "|" << x.value << "|";
      for (auto y : x.outwards)
        cout << " -> " << y;
      cout << endl;
    }
  }

  void bfs(int startVertex = 0)
  {
    // base case
    if (!vertexExists(startVertex))
      return;

    // initialize adj structures
    queue<int> pending;

    bool visited[adj.size()];
    for (int i = 0; i < adj.size(); i++)
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

      for (int i = 0; i < adj[currentVertex].outwards.size(); i++)
      {
        if (!visited[adj[currentVertex].outwards[i]])
        {
          int nextVertex = adj[currentVertex].outwards[i];
          visited[nextVertex] = true;
          pending.push(nextVertex);
        }
      }
    }
  }
};

int main()
{
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