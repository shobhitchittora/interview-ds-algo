#include <bits/stdc++.h>

using namespace std;
typedef vector<int> VEC;
typedef queue<int> QUE;

#define V 5

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

void addEdge(VEC v[], int a, int b)
{
  v[a].push_back(b);
  v[b].push_back(a);
}

void bfs(VEC v[], int root)
{
  cout << "BFS" << endl;

  QUE q;
  VEC visited(V, 0);

  q.push(root);

  while (!q.empty())
  {
    int x = q.front();
    if (visited[x] == 0)
    {
      visited[x] = 1;
      cout << x << " ";
    }

    q.pop();

    for (VEC::iterator it = v[x].begin(); it != v[x].end(); it++)
    {
      if (visited[*it] == 0)
      {
        q.push(*it);
      }
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
  addEdge(v, 2, 3);
  addEdge(v, 3, 3);

  bfs(v, 2);

  return 0;
}