#include <stdlib.h>
#include "list.h"

struct list {
  Cell * first;
};

struct cell {
  void * item;
  Cell * next;
};

void inicializeList(List * l) {
  l = (List*)malloc(sizeof(List));
  l->first = NULL;
  return;
}
