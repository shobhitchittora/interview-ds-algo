#include <bits/stdc++.h>

using namespace std;
typedef vector<int> VEC;
typedef queue<int> QUE;

#define V 5

VEC visited(V, 0);

void printGraph(VEC v[])
{
  for (int i = 0; i < V; i++)
  {
    cout << "V = " << i << " -> ";
    for (VEC::iterator it = v[i].begin(); it != v[i].end(); it++)
    {
      cout << *it << " ";
    }
    cout << endl;
  }
}

void printVec(VEC v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

void addEdge(VEC v[], int a, int b)
{
  if (find(v[a].begin(), v[a].end(), b) == v[a].end())
  {
    v[a].push_back(b);
  }

  // if (find(v[b].begin(), v[b].end(), a) == v[b].end())
  // {
  //   v[b].push_back(a);
  // }
}

void dfsUtil(VEC v[], int root)
{
  cout << root << " ";
  visited[root] = 1;

  for (VEC::iterator it = v[root].begin(); it != v[root].end(); it++)
  {
    if (visited[*it] == 0)
    {
      dfsUtil(v, *it);
    }
  }
}

void dfs(VEC v[], int root)
{
  cout << "DFS" << endl;
  for (int i = 0; i < V; i++)
  {
    if ((v[i].size()) != 0 && visited[i] == 0)
    {
      dfsUtil(v, i);
    }
  }
}

int main()
{
  VEC v[V];

  addEdge(v, 0, 1);
  addEdge(v, 0, 2);
  addEdge(v, 1, 2);
  addEdge(v, 2, 0);
  // addEdge(v, 2, 3);
  addEdge(v, 3, 3);

  printGraph(v);
  dfs(v, 2);

  return 0;
}