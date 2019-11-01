#include <bits/stdc++.h>

using namespace std;
typedef vector<int> VEC;

#define V 5

void printGraph(VEC v[])
{
  for (int i = 0; i < V; i++)
  {
    cout<< "V = " << i << " -> ";
    for (VEC::iterator it = v[i].begin(); it != v[i].end(); it++)
    {
      cout << *it << " ";
    }
    cout << endl;
  }
}

void addEdge(VEC v[], int a, int b)
{
  v[a].push_back(b);
  v[b].push_back(a);
}

int main()
{
  VEC v[V];

  addEdge(v, 0, 1);
  addEdge(v, 0, 2);
  addEdge(v, 1, 2);
  addEdge(v, 1, 3);

  printGraph(v);

  return 0;
}