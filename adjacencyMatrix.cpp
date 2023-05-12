#include <iostream>
#include <cstring>
using namespace std;

// ---- ASSUMPTIONS ----
// weight = 0 => no edge

struct graph
{
  int **matrix;
  int noOfVertices = 0;

  graph(int noOfVertices) : noOfVertices(noOfVertices)
  {
    matrix = new int *[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
      matrix[i] = new int[noOfVertices]{0};
  }

  void addEdge(int start, int end, int weight)
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
};

int main()
{
  graph g(5);
  g.print();
}