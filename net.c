#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "net.h"
//STRUCT AREA
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
//END OF STRUCT AREA
//STATIC FUNCTIONS AREA
static char * adjustString(char * name){
    char * space = (char *)malloc(strlen(name)*sizeof(char)+1);
    strcpy(space, name);
    return space;
}

static Terminal * findTerminal(Terminal * tlist, char * name){
    while(tlist != NULL && strcmp(tlist->name,name)){
        tlist = tlist->Next;
    }
    return tlist;
}

static Router * findRouter(Router * rlist, char * name){
    while(rlist != NULL && strcmp(rlist->name,name)){
        rlist = rlist->Next;
    }
    return rlist;
}

static void printRoutersLinks(Router * rlist, Terminal * tlist) {
    Terminal * t = tlist;
    while(t != NULL) {
      if(t->r != NULL)
        printf("%s --- %s\n", t->name, t->r->name);
      t = t->Next;
    }
    return;
}
//END OF STATIC FUNCTIONS AREA
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

void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist) {
    Terminal * t = findTerminal(tlist, tname);
    Router * r = findRouter(rlist, rname);
    if(r != NULL && t != NULL)
      t->r = r;
    else printf("\nError: NOT FOUND\n\n");
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

Router * removeRouter(Router * r, Terminal * ter, char * rn) {
    while(r->Next != NULL && strcmp(r->Next->name, rn)) {
      r = r->Next;
    }
    Router * tem = r->Next;
    r->Next = tem->Next;
    while(ter->r != NULL && strcmp(ter->r->name, rn)) {
      ter = ter->Next;
    }
    ter->r = NULL;
    free(tem);
    return r;
}

Terminal * removeTerminal(Router * r, Terminal * ter, char * tn) {
    while(ter->Next != NULL && strcmp(ter->Next->name, tn)) {
      ter = ter->Next;
    }
    Terminal * tem = ter->Next;
    ter->Next = tem->Next;
    free(tem);
    return ter;
}

void unlinkTerminal(char * tname, Terminal * tlist) {
    Terminal * t = findTerminal(tlist, tname);
    t->r = NULL;
    return;
}
