#include "queue.h"
#include <stdlib.h>

Queue initQ(void) {
  Queue newQ;
  newQ.capacity = 1;
  newQ.items = (int *)malloc(newQ.capacity * sizeof(int));
  newQ.count = 0;
  newQ.first = 0;

  return newQ;
}

void addQ(Queue *q, int x) {
  if (q->count + 1 > q->capacity)
    resizeQ(q);

  int index = (q->first + q->count) % q->capacity;
  q->items[index] = x;
  q->count++;
}

int removeQ(Queue *q) {
  int x = q->items[q->first];
  q->first = (q->first + 1) % q->capacity;

  q->count--;
  if (3 * q->count < q->capacity)
    resizeQ(q);

  return x;
}
