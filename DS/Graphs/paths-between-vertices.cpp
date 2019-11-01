
/**
 * Precondition - No cycle in the graph
*/

#include "graph.h"
using namespace std;

#define V 5

class GRAPH : public Graph
{
public:
  GRAPH(int vertices, bool isDirected = false) : Graph(vertices, isDirected)
  {
  }

  VECVECINT dfs(int src, int dst)
  {
    VECVECINT result;
    VECINT path;
    dfsUtil(src, dst, path, result);

    return result;
  }

  void dfsUtil(int current, int dst, VECINT &path, VECVECINT &result)
  {

    bool wasVisited = false;

    path.push_back(current);
    wasVisited = true;

    if (current == dst)
    {
      // found path
      result.push_back(path);
    }

    for (VECINT::iterator it = this->graph[current].begin(); it != this->graph[current].end(); it++)
    {
      dfsUtil(*it, dst, path, result);
    }

    if (wasVisited)
    {
      path.pop_back();
    }
  }
};

int main()
{
  GRAPH *g = new GRAPH(V, true);
  g->addEdge(0, 1);
  g->addEdge(0, 2);
  g->addEdge(0, 3);
  g->addEdge(2, 3);
  g->addEdge(2, 4);
  g->addEdge(4, 3);
  g->addEdge(1, 4);

  int src = 0, dst = 3;

  VECVECINT v = g->dfs(src, dst);

  for (int i = 0; i < v.size(); i++)
  {
    for (VECINT::iterator it = v[i].begin(); it != v[i].end(); it++)
    {
      cout << *it << " ";
    }
    cout << endl;
  }

  return 0;
}