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
static Connect * findConnectionByRouter(Connect * w, char * rn) {
    while(strcmp(routerName(w->r), rn)) w = w->Next;
    return w;
}

static Connect * findConnectionBefore(Connect * w, Connect * w1) {
    while(w != NULL && w->Next != NULL && strcmp(routerName(w->r), routerName(w->Next->r)))
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
    }
    if(w == NULL) {
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
        w = w1->Next;
        free(w1);
    }
    return w;
}

char * routerConnected(Connect * w) {
    return routerName(w->r);
}

void printConnections(Connect * w) {
    Connect * temp = w;
    if(temp == NULL) printf("No connections here.\n");
    while(temp != NULL) {
        printf("%s\n", routerName(temp->r));
        temp = temp->Next;
    }
}
