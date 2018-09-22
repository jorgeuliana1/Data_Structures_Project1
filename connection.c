#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"
#include "connection.h"
//STRUCT AREA
struct connections {
    Router * r1;
    Router * r2;
    Connect * Next;
};
//END OF STRUCT AREA
//STATIC FUNCTIONS AREA
static Connect * findConnectionByRouters(Connect * w, char * rn1, char * rn2) {
    while(strcmp(routerName(w->r1), rn1) || strcmp(routerName(w->r2), rn2)) w = w->Next;
    return w;
}

static Connect * findConnectionBefore(Connect * w, Connect * w1) {
    while(w != NULL && w->Next != NULL && (strcmp(routerName(w->Next->r1), routerName(w->r1)) || strcmp(routerName(w->Next->r2), routerName(w->r2))))
        w = w->Next;
    return w;
}

static Connect * findLastConnection(Connect * w) {
    while(w != NULL && w->Next != NULL) w = w->Next;
    return w;
}
//END OF STATIC FUNCTIONS AREA

Connect * inicializeConnection(Connect * connect) {
    return NULL;
}

Connect * webConnectRoutersLL(Connect * w, void * rlist, char * rn1, char * rn2) {
    rlist = (Router *) rlist;
    Router * temp1 = findRouter(rlist, rn1);
    Router * temp2 = findRouter(rlist, rn2);
    if(w != NULL) {
        w = findLastConnection(w);
        w->Next->r1 = temp1;
        w->Next->r2 = temp2;
        w->Next->Next = NULL;
        w = w->Next;
    }
    if(w == NULL) {
        w = (Connect *)malloc(sizeof(Connect));
        w->Next = NULL;
        w->r1 = temp1;
        w->r2 = temp2;
    }
    return w;
}

Connect * destroyConnection(Connect * w, char * rn1, char * rn2) {
    Connect * w1 = findConnectionByRouters(w, rn1, rn2);
    Connect * w0 = findConnectionBefore(w, w1);
    if(w0 == NULL && w1->Next != NULL) w = w1->Next;
    if(w0 != NULL && w1->Next != NULL) w0->Next = w1->Next;
    if(w0 == NULL && w1->Next == NULL) w = NULL;
    free(w1);
    return w;
}

void printConnections(Connect * w) {
    while(w != NULL) {
        printf("%s -- %s\n", routerName(w->r1), routerName(w->r2));
        w = w->Next;
    }
}
