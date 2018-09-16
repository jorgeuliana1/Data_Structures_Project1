#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "router.h"
#include "terminal.h"

struct router {
  char * name;
  char * oper;
  Terminal * t;
  Router * link;
};

void registerRouter(Router * r, char * n, char * o) {
  r = (Router *)malloc(sizeof(Router));
  r->name = (char *)malloc(strlen(n)*sizeof(char)+1);
  strcpy(r->name, n);
  r->oper = (char *)malloc(strlen(o)*sizeof(char)+1);
  strcpy(r->oper, o);
  r->link = NULL;
  r->t = NULL;
  return;
}
