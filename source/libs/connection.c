#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"
#include "connection.h"
//STRUCT AREA
struct connections {
    Router * r;
    int flag;
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

Connect * webConnectRouterLL(Connect * w, void * rlist, char * rn) {
    rlist = (Router *) rlist;
    Router * temp = findRouter(rlist, rn);
    if(w != NULL) {
        Connect * temp1;
        temp1 = (Connect *)malloc(sizeof(Connect));
        temp1->r = temp;
        temp1->flag = 0;
        temp1->Next = NULL;
        Connect * temp2 = findLastConnection(w);
        temp2->Next = temp1;
    } else {
        w = (Connect *)malloc(sizeof(Connect));
        w->Next = NULL;
        w->r = temp;
        w->flag = 0;
    }
    return w;
}

Connect * destroyConnection(Connect * w, char * rn) {
    Connect * w1 = findConnectionByRouter(w, rn);
    if(w1 == NULL) {
        printf("ERROR: Routers are not linked.\n");
    } else {
        Connect * w2 = findPreviousConnection(w, w1);
        if(w2 != NULL) w2->Next = w1->Next;
        else w = w1->Next;
        free(w1);
    }
    return w;
}

char * routerConnected(Connect * w) {
    return routerName(w->r);
}

Connect * nextCNT(Connect * w) {
    return w->Next;
}

char * cntRouterName(Connect * w) {
    return routerName(w->r);
}

Connect * flag(Connect * c) {
    c->flag = 1;
}

Connect * unflag(Connect * c) {
    c->flag = 0;
}

int isFlagged(Connect * c) {
    return c->flag;
}

Connect * findConnectionByRouter(Connect * w, char * rn) {
    while(strcmp(routerName(w->r), rn)) w = w->Next;
    return w;
}
