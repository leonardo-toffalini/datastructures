#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List initList(void) {
  List newList;
  newList.capacity = 1;
  newList.items = (int *)malloc(newList.capacity * sizeof(int));
  newList.count = 0;

  return newList;
}

void printList(List *l) {
  for (int i = 0; i < l->count; i++) {
    printf("%d ", l->items[i]);
  }
  printf("\n");
}

int getList(List *l, int i) { return l->items[i]; }

int setList(List *l, int i, int x) {
  int y = l->items[i];
  l->items[i] = x;
  return y;
}

int removeList(List *l, int i) {
  int x = l->items[i];

  // Optimized approach
  memmove(&l->items[i], &l->items[i + 1],
          (l->count - i - 1) * sizeof(*l->items));

  // Naive approach
  // for (int j = i; j < l->count; j++) {
  //   l->items[j] = l->items[j + 1];
  // }

  l->count--;
  if (3 * l->count <= l->capacity)
    resizeList(l);

  return x;
}

void addList(List *l, int i, int x) {
  if (l->count == l->capacity)
    resizeList(l);
  l->count++;

  // Optimized approach
  memmove(&l->items[i + 1], &l->items[i],
          (l->count - i - 1) * sizeof(*l->items));

  l->items[i] = x;

  // Naive approach
  // int prev = l->items[i];
  // l->items[i] = x;
  // for (int j = i + 1; j < l->count; j++) {
  //   int cur = l->items[j];
  //   l->items[j] = prev;
  //   prev = cur;
  // }
}

void appendList(List *l, int x) { addList(l, l->count, x); }

int popList(List *l) { return removeList(l, l->count - 1); }

void resizeList(List *l) {
  l->capacity = (l->capacity < 8) ? 8 : (l->capacity * 2);
  l->items = (int *)realloc(l->items, l->capacity * sizeof(int));
}

void freeList(List *l) { free(l->items); }
