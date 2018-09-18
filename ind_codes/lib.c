#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

typedef struct connections Connect;

struct connections {
    Router * rs;
    Connect * Next;
};

struct router {
    char * name;
    char * carrier;
    Connect * cnt;
    Router * Next;
};

struct terminal {
    char * name;
    char * local;
    Terminal * Next;
    Router * r;
};

static char * adjustString(char * name){
    char * space = (char *)malloc(strlen(name)*sizeof(char)+1);
    strcpy(space, name);
    return space;
}

Router * registerRouter(Router * r, char * n, char * o) {
    Router * newRouter = (Router *)malloc(sizeof(Router));
    newRouter->name = adjustString(n);
    newRouter->carrier = adjustString(o);
    newRouter->cnt = NULL;

    if(!r) { //If router list is empty
        newRouter->Next = NULL;
    } else { //If router list has elements
        newRouter->Next = r;
    }
    return newRouter;
}

void printRouterAndTerminal(Router * r, Terminal * t) {
    while(r){
        printf("name: %s\n", r->name);
        printf("carrier: %s\n\n", r->carrier);
        r = r->Next;
    }
    while (t) {
        printf("name: %s\n", t->name);
        printf("place: %s\n", t->local);
        t->r ? printf("\t\t %s -- %s\n", t->name, t->r->name) : printf("No connection in %s\n", t->name);
        t = t->Next;
    }
}

Terminal * registerTerminal(Terminal * t, char * n, char * l) {
    Terminal * newTerminal = (Terminal*)malloc(sizeof(Terminal));
    newTerminal->name = adjustString(n);
    newTerminal->local = adjustString(l);
    newTerminal->r = NULL;

    if(!t) { //If terminal list is empty
        newTerminal->Next = NULL;
    } else { //If terminal list has elements
        newTerminal->Next = t;
    }
    return newTerminal;
}

static Terminal * findTerminal(Terminal * tlist, char * name){
    while(strcmp(tlist->name,name)){
        tlist = tlist->Next;
    }
    return tlist;
}

static Router * findRouter(Router * rlist, char * name){
    while(strcmp(rlist->name,name)){
        rlist = rlist->Next;
    }
    return rlist;
}

void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist) {
    Terminal * t = findTerminal(tlist, tname);
    Router * r = findRouter(rlist, rname);
    t->r = r;
}

/*
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



void inicializeList(List * l) {
l = (List*)malloc(sizeof(List));
l->first = NULL;
return;
}*/
