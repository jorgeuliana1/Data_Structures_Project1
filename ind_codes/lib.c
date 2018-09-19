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
    char * place;
    Terminal * Next;
    Router * r;
};

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

static Terminal * findPreviousTerminal(Terminal * tlist, Terminal * t) {
    while(t != NULL && tlist->Next != t){
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

void * inicializeList(){
    return NULL;
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

Terminal * registerTerminal(Terminal * tlist, char * n, char * l) {
    Terminal * newTerminal = (Terminal*)malloc(sizeof(Terminal));
    newTerminal->name = adjustString(n);
    newTerminal->place = adjustString(l);
    newTerminal->r = NULL;

    if(!tlist) { //If terminal list is empty
        newTerminal->Next = NULL;
    } else { //If terminal list has elements
        newTerminal->Next = tlist;
    }
    return newTerminal;
}

void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist) {
    Terminal * t = findTerminal(tlist, tname);
    Router * r = findRouter(rlist, rname);

    if(wasntFound(t)){
        printf("ERROR: Terminal not found!\n");
        return;
    }
    if(wasntFound(r)){
        printf("ERROR: Router not found!\n");
        return;
    }
    
    if(wasntFound(t->r)) //If is not already connected to something
        t->r = r;
    else
        printf("ERROR: Terminal is already connected to '%s'!\n", t->r->name);
}

void unlinkTerminal(char * tname, Terminal * tlist) {
    Terminal * t = findTerminal(tlist, tname);

    if(wasntFound(t)) //End of list
        printf("ERROR: Terminal not found!\n");
    else
        t->r = NULL;
}

Terminal * removeTerminal(Terminal * tlist, char * tname){
    Terminal * wanted = findTerminal(tlist, tname);
    Terminal * before = findPreviousTerminal(tlist, wanted);
    if(wasntFound(wanted)) { //End of list
        printf("ERROR: Terminal not found!\n");
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

void carrierFrequency(Router * rlist, char * carrier){
    int i = 0;
    while(rlist != NULL){
        if(!strcmp(rlist->carrier,carrier))
            i++;
        rlist = rlist->Next;
    }
    i ? printf("There are %d routers from '%s'.\n", i, carrier) :
    printf("There are no routers from '%s'.\n", carrier);
}

void printRouterAndTerminal(Router * r, Terminal * t) {
    while(r){
        printf("name: %s\n", r->name);
        printf("carrier: %s\n________________________\n", r->carrier);
        r = r->Next;
    }
    while (t) {
        printf("name: %s\n", t->name);
        printf("place: %s\n", t->place);
        t->r ? printf("\t\t %s -- %s\n", t->name, t->r->name) : printf("No connection in %s\n________________________\n", t->name);
        t = t->Next;
    }
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
}
