#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
  int *items;
  int capacity;
  int count;
  int first;
} Queue;

Queue initQ(void);

void addQ(Queue *q, int x);

int removeQ(Queue *q);

void resizeQ(Queue *q);

#endif // !QUEUE_H
