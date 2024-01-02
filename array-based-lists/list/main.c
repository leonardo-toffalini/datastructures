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
  setList(&l, 2, 10);
  printList(&l);
  addList(&l, 3, 3);
  printList(&l);
  printf("l.count = %d\n", l.count);

  freeList(&l);
  return 0;
}
