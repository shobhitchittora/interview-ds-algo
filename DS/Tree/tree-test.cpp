#include "tree.h"

int main(){
  Tree *tree = new Tree(1);
  tree->insert(2);
  tree->insert(3);
  tree->insert(4);
  tree->insert(5);

  tree->printTree("pre");
  tree->printTree("in");
  tree->printTree("post");

  return 0;
}