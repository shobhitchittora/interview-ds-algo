#ifndef TREE_H
#define TREE_H

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
  Node(int value) : value(value), left(NULL), right(NULL) {}
};

typedef queue<Node *> QUE;

class Tree
{
public:
  Node *root;

  Tree(int rootValue)
  {
    root = new Node(rootValue);
  }

  void inorder(Node *root)
  {
    if (!root)
    {
      return;
    }

    if (root->left)
      inorder(root->left);

    cout << root->value << " ";

    if (root->right)
      inorder(root->right);
  }

  void preorder(Node *root)
  {
    if (!root)
    {
      return;
    }

    cout << root->value << " ";

    if (root->left)
      preorder(root->left);

    if (root->right)
      preorder(root->right);
  }

  void postorder(Node *root)
  {
    if (!root)
    {
      return;
    }

    if (root->left)
      postorder(root->left);

    if (root->right)
      postorder(root->right);

    cout << root->value << " ";
  }

  void printTree(string type)
  {
    if (type == "pre")
    {
      preorder(this->root);
    }

    if (type == "in")
    {
      inorder(this->root);
    }

    if (type == "post")
    {
      postorder(this->root);
    }
    cout << endl;
  }

  int insert(int value)
  {
    QUE q;
    q.push(this->root);

    while (!q.empty())
    {
      Node *node = q.front();
      q.pop();
      if (!node->left)
      {
        node->left = new Node(value);
        break;
      }
      else
      {
        q.push(node->left);
      }

      if (!node->right)
      {
        node->right = new Node(value);
        break;
      }
      else
      {
        q.push(node->right);
      }
    }
    return value;
  }
};

#endif