#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"

//STRUCT AREA
struct router {
    char * name;
    char * carrier;
    Connect * cnt;
    Router * Next;
};
//END OF STRUCT AREA

//STATIC FUNCTIONS AREA
static char * adjustString(char * name){
    char * space = (char *)malloc(strlen(name)*sizeof(char)+1);
    strcpy(space, name);
    return space;
}
//END OF STATIC FUNCTIONS AREA

Router * inicializeList(){
    return NULL;
}

Router * findRouter(Router * rlist, char * name) {
    while(rlist != NULL && strcmp(rlist->name,name)){
        rlist = rlist->Next;
    }
    return rlist;
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

//  PROBLEMATIC
Router * removeRouter(Router * rlist, Terminal * tlist, char * rn) {
    Router * temporary = findRouter(rlist, rn);
    rlist->Next = temporary->Next; //what if router is first in list?
    tlist = findTerminalbyRouter(tlist, rn); //There could be many terminals w one router
    unlinkTerminal(tlist);
    free(temporary); //What about its name and stuff
    return rlist;
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

void printRouters(Router * r) {
    while(r){
        printf("name: %s\n", r->name);
        printf("carrier: %s\n\n", r->carrier);
        r = r->Next;
    }
}

char * routerName(Router * r) {
    return r->name;
}
