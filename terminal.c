#include "router.h"
#include "terminal.h"
#include <string.h>
#include <stdlib.h>

struct terminal {
  char * name;
  char * local;
  Router * r;
};

void registerTerminal(Terminal * t, char * n, char * l) {
  r = (Terminal *)malloc(sizeof(Terminal));
  r->name = (char *)malloc(strlen(n)*sizeof(char)+1);
  strcpy(r->name, n);
  r->oper = (char *)malloc(strlen(l)*sizeof(char)+1);
  strcpy(r->local, l);
  r->r = NULL;
  return;
}

void insertTerm(TerminalList * l, Terminal * t) {
  if(l->first == NULL) {
    l->first->item = t;
    l->first->next = NULL;
  }
  else {
    TerminalCell * p = l->first;
    while(p!=NULL) {
      p->next;
    }
    p->item = t;
    p->next = NULL;
  }
  return;
}
