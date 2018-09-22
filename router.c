#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"
#include "connections.h"

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

static Router * findPreviousRouter(Router * r, Router * rw) {
    while(r != NULL && r->Next != rw) {
        r = r->Next;
    }
    return r;
}

static int isFirst(Router * r, Router * rw) {
    Router * temp = findPreviousRouter(r, rw);
    if(temp == NULL && rw->Next != NULL) return 1;
    else return 0;
}

static int isMiddle(Router * r, Router * rw) {
    Router * temp = findPreviousRouter(r, rw);
    if(temp != NULL && rw->Next != NULL) return 1;
    else return 0;
}

static int isLast(Router * r, Router * rw) {
    Router * temp = findPreviousRouter(r, rw);
    if(temp != NULL && rw->Next == NULL) return 1;
    else return 0;
}
//END OF STATIC FUNCTIONS AREA
Router * inicializeRouters() {
    return NULL;
}
Router * findRouter(Router * rlist, char * name) {
    while(rlist != NULL && strcmp(rlist->name, name)){
        rlist = rlist->Next;
    }
    return rlist;
}

Router * registerRouter(Router * r, char * n, char * o) {
    Router * newRouter = (Router *)malloc(sizeof(Router));
    newRouter->name = adjustString(n);
    newRouter->carrier = adjustString(o);
    newRouter->cnt = NULL;
    if(r == NULL) { //If router list is empty
        newRouter->Next = NULL;
    } else { //If router list has elements
        newRouter->Next = r;
    }
    return newRouter;
}

Router * removeRouter(Router * rlist, char * rn) {
    Router * temp = findRouter(rlist, rn);
    if(isLast(rlist, temp)) {
        rlist = findPreviousRouter(rlist, temp);
        rlist->Next = NULL;
    }
    else if(isMiddle(rlist, temp)) {
        rlist = findPreviousRouter(rlist, temp);
        rlist->Next = temp->Next;
    }
    else if(isFirst(rlist, temp)) {
        rlist = temp->Next;
    }
    rlist->cnt = temp->cnt;
    free(temp->name);
    free(temp->carrier);
    free(temp);
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
    while(r != NULL){
        printf("name: %s\n", r->name);
        printf("carrier: %s\n\n", r->carrier);
        r = r->Next;
    }
}

char * routerName(Router * r) {
    if(r != NULL) return r->name;
    else return NULL;
}
