#include "graph.h"
using namespace std;

#define V 6

int main()
{
  Graph *g = new Graph(V, true);
  g->addEdge(5, 2);
  g->addEdge(5, 0);
  g->addEdge(4, 0);
  g->addEdge(4, 1);
  g->addEdge(2, 3);
  g->addEdge(3, 1);

  // g->printGraph();

  STKINT stk = g->dfsStack(0, true);

  while (!stk.empty())
  {
    int value = stk.top();
    cout << value << " ";
    stk.pop();
  }
  return 0;
}
