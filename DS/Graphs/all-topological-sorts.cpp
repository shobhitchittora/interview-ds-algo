/**
 * 
 *  All topological sort of a DAG
 *  
 *  Get all indegrees and start with vertices with indegree as zero. This is because those vertices would be first in the sort order
 *  as those are the ones from where the edges only start.
 *  
 *  Backtrack to find other paths in DFS.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VECINT;
typedef VECINT::iterator VECITR;

#define V 6

class Graph
{
public:
  int vertices;
  VECINT indegree;
  VECINT *graph;

  Graph(int vertices)
  {
    this->vertices = vertices;
    this->graph = new VECINT[vertices];
    for (int i = 0; i < vertices; i++)
    {
      this->indegree.push_back(0);
    }
  }

  void addEdge(int a, int b)
  {
    this->graph[a].push_back(b);
    this->indegree[b]++;
  }

  void printVec(VECINT &v)
  {
    for (VECITR it = v.begin(); it != v.end(); it++)
    {
      cout << *it << " ";
    }
    cout << endl;
  }

  void dfs()
  {
    VECINT currentPath;
    VECINT visited(vertices, 0);
    dfsUtil(currentPath, visited);
  }

  void dfsUtil(VECINT &currentPath, VECINT &visited)
  {

    bool allVisited = true;

    for (int i = 0; i < this->vertices; i++)
    {
      if (this->indegree[i] == 0 && visited[i] == 0)
      {

        currentPath.push_back(i);
        visited[i] = 1;

        for (VECITR it = this->graph[i].begin(); it != this->graph[i].end(); it++)
        {
          this->indegree[*it]--;
        }

        dfsUtil(currentPath, visited);

        visited[i] = 0;
        currentPath.erase(currentPath.end() - 1);

        for (VECITR it = this->graph[i].begin(); it != this->graph[i].end(); it++)
        {
          this->indegree[*it]++;
        }

        // backtracked that means some node with indegree 0 is pending
        allVisited = false;
      }
    }

    if (allVisited)
    {
      // print currentPath
      printVec(currentPath);
    }
  }
};

int main()
{
  Graph *g = new Graph(V);
  g->addEdge(5, 2);
  g->addEdge(5, 0);
  g->addEdge(4, 0);
  g->addEdge(4, 1);
  g->addEdge(2, 3);
  g->addEdge(3, 1);

  g->dfs();

  return 0;
}