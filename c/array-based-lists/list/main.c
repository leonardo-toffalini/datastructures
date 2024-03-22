#include "list.h"
#include <stdio.h>

int main(void) {
  List l = initList();
  printf("l.count = %d\n", l.count);

  printList(&l);
  for (int i = 0; i < 10; i++) {
    appendList(&l, i);
  }
  printList(&l);
  setList(&l, 2, 20);
  printList(&l);
  addList(&l, 3, 30);
  printList(&l);
  int x = removeList(&l, 2);
  printf("removed element: %d\n", x);
  printList(&l);
  int y = popList(&l);
  printf("popped element: %d\n", y);
  printList(&l);
  printf("l.count = %d\n", l.count);

  freeList(&l);
  return 0;
}
