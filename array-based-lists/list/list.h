#ifndef LIST_H
#define LIST_H

typedef struct List {
  int *items;
  int capacity;
  int count;
} List;

List initList(void);

void printList(List *l);

int getList(List *l, int i);

int setList(List *l, int i, int x);

int removeList(List *l, int i);

void addList(List *l, int i, int x);

void appendList(List *l, int x);

void resizeList(List *l);

void freeList(List *l);

#endif // !LIST_H
