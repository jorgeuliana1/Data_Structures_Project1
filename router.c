#include <string.h>
#include <stdlib.h>
#include "router.h"
#include "terminal.h"

struct router {
  char * name;
  char * oper;
  Router * nextLink;
};

void registerRouter(Router * r, char * n, char * o) {
  r = (Router *)malloc(sizeof(Router));
  r->name = (char *)malloc(strlen(n)*sizeof(char)+1);
  strcpy(r->name, n);
  r->oper = (char *)malloc(strlen(o)*sizeof(char)+1);
  strcpy(r->oper, o);
  r->nextLink = NULL;
  return;
}

void insertRout(RouterList * l, Router * t) {
  if(l->first == NULL) {
    l->first->item = t;
    l->first->next = NULL;
  }
  else {
    RouterCell * p = l->first;
    while(p!=NULL) {
      p->next;
    }
    p->item = t;
    p->next = NULL;
  }
  return;
}
