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
  vector<vertex> data;

  bool vertexExists(int v)
  {
    for (auto x : data)
      if (x.value == v)
        return true;
    return false;
  }

  int findIndexOfVertex(int v)
  {
    for (int i = 0; i < data.size(); i++)
      if (data[i].value == v)
        return i;
    return -1;
  }

  bool edgeExists(int start, int end)
  {
    int index = findIndexOfVertex(start);
    if (index == -1)
      return false;
    else
      return find(data[index].outwards.begin(), data[index].outwards.end(), end) != data[index].outwards.end();
  }

  void addVertex(int v)
  {
    if (!vertexExists(v))
      data.push_back(vertex(v));
  }

  void addEdge(int start, int end)
  {
    int index = findIndexOfVertex(start);
    if (index != -1)
      if (find(data[index].outwards.begin(), data[index].outwards.end(), end) == data[index].outwards.end())
        data[index].outwards.push_back(end);
  }

  void printGraph()
  {
    for (auto x : data)
    {
      cout << "|" << x.value << "|";
      for (auto y : x.outwards)
        cout << " -> " << y;
      cout << endl;
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
}