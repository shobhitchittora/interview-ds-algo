/**
 * Kosaraju SCC algo - DIRECTED GRAPH
 * 
 * Uses 2 DFS to get the strongly connected components
 * 
 * 1. 1st DFS gets the nodes in a stack in the order of their distance from the root selected. We can select any node as the root.
 * 2. 2nd DFS processed these nodes in the stack and does a DFS on the reversed directed graph to print SCC.
*/

#include "graph.h"
using namespace std;

#define V 5

int main()
{
  Graph *g = new Graph(V, true);
  g->addEdge(0, 2);
  g->addEdge(2, 1);
  g->addEdge(1, 0);
  g->addEdge(0, 3);
  g->addEdge(3, 4);

  STKINT stk = g->dfsStack(0);

  Graph *revGraph = g->reverseEdges();

  VECINT visited(V, 0);
  while (!stk.empty())
  {
    int x = stk.top();
    stk.pop();

    revGraph->printDFS(x, visited, false);
  }
  return 0;
}