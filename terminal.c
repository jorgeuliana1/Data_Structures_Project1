#include <string.h>
#include <stdlib.h>
#include "terminal.h"
#include "router.h"

struct terminal {
  char * name;
  char * local;
  Router * r;
};

void registerTerminal(Terminal * t, char * n, char * l) {
  t = (Terminal *)malloc(sizeof(Terminal));
  t->name = (char *)malloc(strlen(n)*sizeof(char)+1);
  strcpy(t->name, n);
  t->local = (char *)malloc(strlen(l)*sizeof(char)+1);
  strcpy(t->local, l);
  t->r = NULL;
  return;
}
