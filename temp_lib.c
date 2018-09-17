#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_lib.h"

struct terminal {
  char * name;
  char * local;
  Router * r;
};

struct router {
  char * name;
  char * oper;
  Terminal * t;
  Router * link;
};

struct list {
  Cell * first;
};

struct cell {
  void * item;
  Cell * next;
};

void linkRouterToTerminal(Router * r, Terminal * t) {
  t->r = r;
  r->t = t;
  return;
}

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

void registerTerminal(Terminal * t, char * n, char * l) {
  t = (Terminal *)malloc(sizeof(Terminal));
  t->name = (char *)malloc(strlen(n)*sizeof(char)+1);
  strcpy(t->name, n);
  t->local = (char *)malloc(strlen(l)*sizeof(char)+1);
  strcpy(t->local, l);
  t->r = NULL;
  return;
}

void inicializeList(List * l) {
  l = (List*)malloc(sizeof(List));
  l->first = NULL;
  return;
}
