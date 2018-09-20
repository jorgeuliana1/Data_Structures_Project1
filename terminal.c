#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//STRUCT AREA
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

static void printTerminalLinks(Terminal * tlist) {
    Terminal * t = tlist;
    while(t != NULL) {
      if(t->r != NULL)
        printf("%s --- %s\n", t->name, routerName(t->r));
      t = t->Next;
    }
    return;
}
//END OF STATIC FUNCTIONS AREA
void disconnectRouter(Terminal * t) {
    t->r = NULL;
}

Terminal * findTerminalbyRouter(Terminal * t, char * rn) {
    while(t != NULL && strcmp(routerName(t->r), rn)) {
        t = t->Next;
    }
    return t;
}

Terminal * findTerminal(Terminal * tlist, char * name) {
    while(tlist != NULL && strcmp(tlist->name, name)) {
        tlist = tlist->Next;
    }
    return tlist;
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

void printTerminals(Terminal * t) {
    while(t) {
        printf("name: %s\n", t->name);
        printf("place: %s\n", t->local);
        t->r ? printf("\t\t %s -- %s\n", t->name, routerName(t->r)) : printf("No connection in %s\n", t->name);
        t = t->Next;
    }
}
