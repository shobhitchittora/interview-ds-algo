#ifndef QUEUE_H
#define QUEUE_H

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
  int *arr;
  int length;
  int size;

  Queue(int length)
  {
    this->length = length;
    this->size = 0;
    this->arr = new int[length];
  }

  int front()
  {
    return arr[0];
  }

  int getSize()
  {
    return this->size;
  }

  void push(int value)
  {
    if (this->size >= this->length)
    {
      cout << "Overflow! stop." << endl;
      return;
    }

    if (size < length)
    {
      this->arr[size] = value;
      this->size++;
    }
  }

  int pop()
  {
    if (this->size == 0)
    {
      cout << "Underflow! stop." << endl;
      return INT_MIN;
    }

    int size = this->size;

    if (size == 1)
    {
      int value = arr[0];
      arr[0] = INT_MAX;
      this->size--;
      return value;
    }

    int value = arr[0];
    arr[0] = INT_MAX;
    this->size--;
    if (size != 1)
    {
      for (int i = 1; i < size; i++)
      {
        arr[i - 1] = arr[i];
      }
    }

    return value;
  }

  void printAll()
  {
    for (int i = 0; i < this->size; i++)
    {
      cout << this->arr[i] << " ";
    }
    cout << endl;
  }
};

#endif