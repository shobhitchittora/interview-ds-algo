#include "queue.h"

#define SIZE 5

int main()
{
  Queue *q = new Queue(SIZE);
  q->push(1);
  q->push(2);
  q->push(3);
  q->push(4);

  // PUSH
  q->push(5);
  assert(q->getSize() == 5);

  // OVERFLOW
  q->push(6);
  assert(q->getSize() == 5);

  // CHECK
  assert(q->front() == 1);
  assert(q->getSize() == 5);

  // POP
  for (int i = 1; i <= 5; i++)
  {
    assert(q->pop() == i);
    assert(q->getSize() == SIZE - i);
  }

  // UNDERFLOW
  assert(q->pop() == INT_MIN);

  // PUSH
  q->push(10);
  q->push(11);
  q->pop();
  q->push(12);

  assert(q->front() == 11);
  assert(q->getSize() == 2);
}