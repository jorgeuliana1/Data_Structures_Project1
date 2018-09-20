#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

Router * removeRouter(Router * r, Terminal * ter, char * rn) {
    Router * tem = findRouter(r, rn);
    r->Next = tem->Next;
    ter = findTerminalbyRouter(ter, rn);
    disconnectRouter(ter);
    free(tem);
    return r;
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
