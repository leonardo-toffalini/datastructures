#include "list.h"
#include <stdlib.h>

List initList(void) {
  List newList;
  newList.capacity = 1;
  newList.items = (int *)malloc(newList.capacity * sizeof(int));
  newList.count = 0;

  return newList;
}

int getList(List l, int i) { return l.items[i]; }

int setList(List l, int i, int x) {
  int y = l.items[i];
  l.items[i] = x;
  return y;
}

int removeList(List l, int i) {
  int x = l.items[i];
  for (int j = i; j < l.count; j++) {
    l.items[j] = l.items[j + 1];
  }
  l.count--;
  if (3 * l.count <= l.capacity)
    resizeList(l);

  return x;
}

void addList(List l, int i, int x) {
  if (l.count == l.capacity)
    resizeList(l);

  int temp = l.items[i];
  for (int j = i + 1; j < l.count; j++) {
    temp = l.items[j + 1];
    l.items[j] = temp;
  }

  l.count++;
}

void resizeList(List l) {
  l.count = (l.count < 8) ? 8 : (l.count * 2);
  l.items = (int *)realloc(l.items, l.capacity * sizeof(int));
}

void freeList(List l) { free(l.items); }
