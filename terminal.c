#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"

//STRUCT AREA
struct terminal {
    char * name;
    char * place;
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

static void freeTerminal(Terminal * t){
    free(t->name);
    free(t->place);
    free(t);
}

static int wasntFound(void * a){
    if(a == NULL)
        return 1;
    else
        return 0;
}

static Terminal * findPreviousTerminal(Terminal * t, Terminal * tw) {
    while(t != NULL && t->Next != tw) {
        t = t->Next;
    }
    return t;
}
//END OF STATIC FUNCTIONS AREA

Terminal * inicializeTerminals() {
    return NULL;
}

Terminal * findTerminal(Terminal * tlist, char * name) {
    while(tlist != NULL && strcmp(tlist->name, name)) {
        tlist = tlist->Next;
    }
    return tlist;
}

Terminal * findTerminalbyRouter(Terminal * t, char * rn) {
    while(t != NULL && strcmp(routerName(t->r), rn)) {
        t = t->Next;
    }
    return t;
}

Terminal * registerTerminal(Terminal * t, char * n, char * l) {
    Terminal * newTerminal = (Terminal*)malloc(sizeof(Terminal));
    newTerminal->name = adjustString(n);
    newTerminal->place = adjustString(l);
    newTerminal->r = NULL;

    if(!t) { //If terminal list is empty
        newTerminal->Next = NULL;
    } else { //If terminal list has elements
        newTerminal->Next = t;
    }
    return newTerminal;
}

Terminal * removeTerminal(Terminal * tlist, char * tname){
    Terminal * wanted = findTerminal(tlist, tname);
    Terminal * before = findPreviousTerminal(tlist, wanted);
    if(wasntFound(wanted)) { //End of list
        printf("Error: Terminal not found!\n");
        return NULL;
    }else if (before == NULL) { //First item
        tlist = wanted->Next;
    }else if(wanted->Next == NULL){ //Last item
        before->Next == NULL;
    }else { //Middle item
        before->Next = wanted->Next;
    }
    freeTerminal(wanted);
    return tlist;
}

void terminalFrequency(Terminal * tlist, char * place){
    int i = 0;
    while(tlist != NULL){
        if(!strcmp(tlist->place,place))
            i++;
        tlist = tlist->Next;
    }
    if(i != 0)
        printf("There are %d terminals in %s.\n", i, place);
    else
        printf("There are no terminals in %s.\n",place);
}

void unlinkTerminal(Terminal * tlist, char * tname) {
    Terminal * t = findTerminal(tlist, tname);
    if(wasntFound(t))
        printf("Error: Terminal not found!\n");
    else
        t->r = NULL;
}

void disconnectRouter(Terminal * tlist, char * rn) {
    Terminal * t;
    while(tlist != NULL) {
        t = findTerminalbyRouter(tlist, rn);
        if(strcmp(routerName(t->r), rn)) unlinkTerminal(tlist, t->name);
    }
}

void printTerminals(Terminal * t) {
    while(t) {
        printf("name: %s\n", t->name);
        printf("place: %s\n", t->place);
        t->r ? printf("\t\t %s -- %s\n", t->name, routerName(t->r)) : printf("No connection in %s\n", t->name);
        t = t->Next;
    }
}

void insertRouterHere(Terminal * t, void * a) {
    a = (Router *) a;
    t->r = a;
}
