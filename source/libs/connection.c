#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"
#include "connection.h"
#define FALSE 0
#define TRUE 1

//STRUCT AREA
struct connections {
    Router * r;
    Connect * Next;
};
//END OF STRUCT AREA
//STATIC FUNCTIONS AREA
static Connect * findPreviousConnection(Connect * origin, Connect * target) {
    Connect * aux = origin;

    //Start of "While"
    while(aux != NULL &&
    aux->Next != NULL &&
    target != NULL &&
    strcmp(routerName(target->r), routerName(aux->Next->r)))
        aux = aux->Next;
    //End of "While"
    
    if(aux->Next != NULL && !strcmp(routerName(target->r), routerName(aux->Next->r)))
        return aux;
    else return NULL;
}

static Connect * findLastConnection(Connect * w) {
    while(w != NULL && w->Next != NULL) w = w->Next;
    return w;
}
//END OF STATIC FUNCTIONS AREA

Connect * inicializeConnection(Connect * connect) {
    return NULL;
}

Connect * addConnection(Connect * w, void * rlist, char * rn) {
    //Casting to avoid problems with void pointer.
    /*
    NOTE: VOID POINTER WAS USED BECAUSE IT WASN'T POSSIBLE TO ADD THE ROUTER
    TYPE TO THE HEADER FILE.
    */
    rlist = (Router *) rlist;
    Router * temp = findRouter(rlist, rn);
    if(w != NULL) {
        //If there isn't any connection.
        Connect * temp1;
        temp1 = (Connect *)malloc(sizeof(Connect));
        temp1->r = temp;
        temp1->Next = NULL;
        Connect * temp2 = findLastConnection(w);
        if(temp2 != NULL) temp2->Next = temp1;
        else w = temp1;
    } else {
        //If there is at least one connection.
        w = (Connect *)malloc(sizeof(Connect));
        w->Next = NULL;
        w->r = temp;
    }
    return w;
}

Connect * removeConnection(Connect * w, char * rn) {
    Connect * w1 = findConnectionByRouter(w, rn);
    if(w1 != NULL) {
        //If w1 is NULL there isn't any connection to be deleted.
        Connect * w2 = findPreviousConnection(w, w1);
        if(w2 != NULL) w2->Next = w1->Next;
        else w = w1->Next;
        free(w1);
    }
    return w;
}

Connect * nextCNT(Connect * w) {
    return w->Next;
}

char * cntRouterName(Connect * w) {
    return routerName(w->r);
}

Connect * findConnectionByRouter(Connect * w, char * rn) {
    while(strcmp(routerName(w->r), rn)) w = w->Next;
    return w;
    //If the connection wasn't found it will return NULL.
}
