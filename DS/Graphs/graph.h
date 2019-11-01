#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > VECVECINT;
typedef vector<int> VECINT;
typedef queue<int> QUEINT;
typedef stack<int> STKINT;

class Graph
{

public:
  int vertices;
  bool isDirected;
  vector<int> *graph;

  Graph(int vertices, bool isDirected = false)
  {
    this->vertices = vertices;
    this->isDirected = isDirected;
    graph = new vector<int>[vertices];
  }

  void addEdge(int a, int b)
  {
    if (isDirected)
    {
      graph[a].push_back(b);
    }
    else
    {
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
  }

  void printGraph()
  {
    for (int i = 0; i < this->vertices; i++)
    {
      cout << "V = " << i << " -> ";
      for (VECINT::iterator it = graph[i].begin(); it != graph[i].end(); it++)
      {
        cout << *it << " ";
      }
      cout << endl;
    }
  }

  void printVec(VECINT v)
  {
    for (VECINT::iterator it = v.begin(); it != v.end(); it++)
    {
      cout << *it << " ";
    }
    cout << endl;
  }

  Graph *reverseEdges()
  {
    Graph *g = new Graph(this->vertices, this->isDirected);

    for (int i = 0; i < this->vertices; i++)
    {
      for (VECINT::iterator it = this->graph[i].begin(); it != this->graph[i].end(); it++)
      {
        g->graph[*it].push_back(i);
      }
    }

    g->printGraph();

    return g;
  }

  VECINT bfs(int root)
  {
    QUEINT qu;
    VECINT bfs;
    VECINT visited(this->vertices, 0);

    qu.push(root);

    while (!qu.empty())
    {
      int temp = qu.front();
      visited[temp] = 1;
      qu.pop();
      bfs.push_back(temp);

      for (VECINT::iterator it = this->graph[temp].begin(); it != this->graph[temp].end(); it++)
      {
        if (visited[*it] == 0)
        {
          qu.push(*it);
        }
      }
    }

    return bfs;
  }

  void printBFS(int root)
  {
    printVec(bfs(root));
  }

  VECINT dfs(int root, VECINT &visited, bool checkAll = false)
  {
    if (visited.empty())
    {
      visited = VECINT(this->vertices, 0);
    }

    VECINT result;

    if (checkAll)
    {
      for (int i = 0; i < this->vertices; i++)
      {
        dfsUtil(i, visited, result);
      }
    }
    else
    {
      dfsUtil(root, visited, result);
    }

    return result;
  }

  void dfsUtil(int root, VECINT &visited, VECINT &result)
  {

    if (visited[root] == 0)
    {
      visited[root] = 1;
      result.push_back(root);
    }

    for (VECINT::iterator it = this->graph[root].begin(); it != this->graph[root].end(); it++)
    {
      if (visited[*it] == 0)
      {
        dfsUtil(*it, visited, result);
      }
    }
  }

  void printDFS(int root, VECINT &visited, bool checkAll = false)
  {
    printVec(dfs(root, visited));
  }

  STKINT dfsStack(int root)
  {
    VECINT visited(this->vertices, 0);
    STKINT stk;
    dfsUtilStk(root, visited, stk);

    return stk;
  }

  void dfsUtilStk(int root, VECINT &visited, STKINT &stk)
  {
    visited[root] = 1;

    for (VECINT::iterator it = this->graph[root].begin(); it != this->graph[root].end(); it++)
    {
      if (visited[*it] == 0)
      {
        dfsUtilStk(*it, visited, stk);
      }
    }

    stk.push(root);
  }
};

#endif