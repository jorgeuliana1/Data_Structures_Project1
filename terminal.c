#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"

//STRUCT AREA

typedef struct terminal {
    char * name;
    char * place;
    Terminal * Next;
    Router * r;
} Terminal;

typedef struct termlist {
    Terminal * first;
    Terminal * last;
} TermList;

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

TermList * inicializeTerminals() {
    TermList * list = (TermList*)malloc(sizeof(TermList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

Terminal * findTerminal(TermList * tlist, char * name) {
    Terminal * aux = tlist->first;
    while(aux != NULL && strcmp(aux->name, name)) {
        aux = aux->Next;
    }
    return aux;
}

Terminal * findTerminalbyRouter(Terminal * t, char * rn) {
    while(t != NULL) {
      if(t->r != NULL) {
        if(strcmp(routerName(t->r),rn)) {
          t = t->Next;
        } else return t;
      } else t = t->Next;
    }
    return t;
}

void registerTerminal(TermList * t, char * n, char * l) {
    Terminal * newTerminal = (Terminal*)malloc(sizeof(Terminal));
    newTerminal->name = adjustString(n);
    newTerminal->place = adjustString(l);
    newTerminal->r = NULL;

    if(t->first == NULL) { //If terminal list is empty
        newTerminal->Next = NULL;
        t->last = t->first = newTerminal;
        
    }else { //If terminal list has elements
        newTerminal->Next = t->first;
        t->first = newTerminal;
    }
}

void removeTerminal(TermList * t, char * tname){
    Terminal * wanted = findTerminal(t, tname);
    Terminal * before = findPreviousTerminal(t, wanted);
    if(wasntFound(wanted)) { //End of list
        printf("Error: Terminal not found!\n");
    }else if (before == NULL) { //First item
        t->first = wanted->Next;
    }else if(wanted->Next == NULL){ //Last item
        t->last = NULL;
    }else { //Middle item
        before->Next = wanted->Next;
    }
    freeTerminal(wanted);
}

void terminalFrequency(TermList * tlist, char * place){
    int i = 0;
    Terminal * aux = tlist->first;
    while(aux != NULL){
        if(!strcmp(aux->place,place))
            i++;
        aux = aux->Next;
    }
    if(i != 0)
        printf("There are %d terminals in %s.\n", i, place);
    else
        printf("There are no terminals in %s.\n",place);
}

void unlinkTerminal(TermList * tlist, char * tname) {
    Terminal * t = findTerminal(tlist, tname);
    if(wasntFound(t))
        printf("Error: Terminal not found!\n");
    else
        t->r = NULL;
}

Terminal * disconnectRouter(Terminal * tlist, char * rn) {
    Terminal * t = tlist;
    while(t != NULL) {
        t = findTerminalbyRouter(tlist, rn);
        if(t != NULL && !strcmp(routerName(t->r), rn)) unlinkTerminal(tlist, t->name);
    }
    return t;
}

void printTerminals(Terminal * t) {
    while(t) {
        printf("name: %s\n", t->name);
        printf("place: %s\n", t->place);
        t->r ? printf("\t\t %s -- %s\n", t->name, routerName(t->r)) : printf("No connection in %s\n", t->name);
        t = t->Next;
    }
}

void plugRouter(Terminal * t, void * a) {
    a = (Router *) a;
    t->r = a;
}

void decimateTerminals(TermList * t) {
    Terminal * temp, * aux;
    aux = t->first;
    while(aux != NULL) {
        temp = aux->Next;
        removeTerminal(aux, aux->name);
        aux = temp;
    }
}

char * terminalName(Terminal * t) {
    return t->name;
}
