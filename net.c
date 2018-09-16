#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "router.h"
#include "terminal.h"

void linkRouterToTerminal(Router * r, Terminal * t) {
  t->r = r;
  r->t = t;
  return;
}

void insertRouter(List * l, Router * r) {
  if(l->first == NULL) {
    l->first->item = r;
    l->first->next = NULL;
  }
  else {
    Cell * p = l->first;
    while(p!=NULL) {
      p->next;
    }
    p->item = r;
    p->next = NULL;
  }
  return;
}

void insertTerminal(List * l, Terminal * t) {
  if(l->first == NULL) {
    l->first->item = t;
    l->first->next = NULL;
  }
  else {
    Cell * p = l->first;
    while(p!=NULL) {
      p->next;
    }
    p->item = t;
    p->next = NULL;
  }
  return;
}

void printRouter(Router * r) {
  printf("name: %s\n", r->name);
  printf("oper: %s\n", r->oper);
  if(r->t != NULL)
    printf("name: %s\n", r->t->name);
  if(r->link != NULL)
    printf("link: %s\n", r->link->name);
  return;
}
