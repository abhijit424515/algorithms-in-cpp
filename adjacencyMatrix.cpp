#include <bits/stdc++.h>
using namespace std;

// ---- ASSUMPTIONS ----
// weight = 0 => no edge
// vertices are 0 to n-1

struct graph
{
private:
  int **matrix;
  int noOfVertices = 0;

public:
  graph(int noOfVertices) : noOfVertices(noOfVertices)
  {
    matrix = new int *[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
      matrix[i] = new int[noOfVertices]{0};
  }

  bool vertexExists(int v)
  {
    return v >= 0 && v < noOfVertices;
  }

  bool edgeExists(int start, int end)
  {
    if (vertexExists(start) && vertexExists(end))
      return (matrix[start][end] > 0);

    return false;
  }

  void addEdge(int start, int end, int weight = 1)
  {
    matrix[start][end] = weight;
  }

  void print()
  {
    cout << "VERTICES: " << noOfVertices << endl
         << endl;

    for (int i = 0; i < noOfVertices; i++)
      for (int j = 0; j < noOfVertices; j++)
      {
        if (j != noOfVertices - 1)
          cout << matrix[i][j] << " ";
        else
          cout << matrix[i][j] << endl;
      }
  }

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

      for (int i = 0; i < noOfVertices; i++)
      {
        if (matrix[currentVertex][i] > 0 && !visited[i])
        {
          int nextVertex = i;
          visited[nextVertex] = true;
          pending.push(nextVertex);
        }
      }
    }
  }

  // assuming noOfVertices > 0
  void dfs(int startVertex = 0)
  {
    // base case
    if (!vertexExists(startVertex))
      return;

    // initialize data structures
    stack<int> pending;

    bool visited[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
      visited[i] = false;

    // first, mark off starting vertex as visited
    visited[startVertex] = true;
    // insert starting vertex in pending queue, so as to follow looping
    pending.push(startVertex);

    while (!pending.empty())
    {
      int currentVertex = pending.top();
      cout << currentVertex << endl;
      pending.pop();

      for (int i = 0; i < noOfVertices; i++)
      {
        if (matrix[currentVertex][i] > 0 && !visited[i])
        {
          int nextVertex = i;
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
  g.print();
  g.bfs();
  cout << "---" << endl;
  g.dfs();
}