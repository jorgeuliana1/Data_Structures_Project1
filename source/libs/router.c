#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"
#include "connection.h"
#define FALSE 0
#define TRUE 1

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

Router * registerRouter(Router * r, char * n, char * o, FILE * l) {
    Router * aux = findRouter(r, n);
    if(aux != NULL) {
        fprintf(l, "ERROR: %s can't be registered, there's a router with the same name.\n\n", n);
        return r;
    }
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

Router * removeRouter(Router * rlist, char * rn, FILE * l, int veriFile) {
    Router * temp = findRouter(rlist, rn);
    if(temp == NULL) {
        if(veriFile) fprintf(l, "ERROR: It wasn't possible to remove %s router because it doesn't exist.\n\n", rn);
        return rlist;
    }
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

void carrierFrequency(Router * rlist, char * carrier, FILE * o){
    int i = 0;
    while(rlist != NULL){
        if(!strcmp(rlist->carrier,carrier))
            i++;
        rlist = rlist->Next;
    }
    fprintf(o, "CARRIERFREQUENCY %s: %d\n\n", carrier, i);
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

Router * decimateRouters(Router * r) {
    Router * temp;
    while(r != NULL) {
        temp = r->Next;
        removeRouter(r, r->name, NULL, FALSE);
        r = temp;
    }
    return NULL;
}

Router * webConnectRouters(Router * rlist, char * rn1, char * rn2, FILE * l, int veriFile) {
    Router * r1 = findRouter(rlist, rn1);
    Router * r2 = findRouter(rlist, rn2);
    if(r1 == NULL || r2 == NULL) {
        if(veriFile) {
            if(r1 == NULL) {
                fprintf(l, "ERROR: %s can't be connected, there isn't a router with this name.\n\n", rn1);
            }
            if(r2 == NULL) {
                fprintf(l, "ERROR: %s can't be connected, there isn't a router with this name.\n\n", rn2);
            }
        }
        return rlist;
    }
    r1->cnt = webConnectRouterLL(r1->cnt, rlist, rn2);
    r2->cnt = webConnectRouterLL(r2->cnt, rlist, rn1);
    return rlist;
}

Router * webDisconnectRouters(Router * rlist, char * rn1, char * rn2, FILE * l, int veriFile) {
    Router * temp1 = findRouter(rlist, rn1);
    Router * temp2 = findRouter(rlist, rn2);
    if(temp1 == NULL || temp2 == NULL) {
        if(temp1 == NULL) {
            if(veriFile) fprintf(l, "ERROR: %s can't be disconnected, there isn't a router with this name.\n\n", rn1);
        }
        if(temp2 == NULL) {
            if(veriFile) fprintf(l, "ERROR: %s can't be disconnected, there isn't a router with this name.\n\n", rn2);
        }
        return rlist;
    }
    temp1->cnt = destroyConnection(temp1->cnt, rn2);
    temp2->cnt = destroyConnection(temp2->cnt, rn1);
    return rlist;
}

int thereIsRRConnection(Router * r) {
    if(r->cnt != NULL) return 1;
    else return 0;
}

Connect * getCNT(Router * r) {
    return r->cnt;
}

Router * nextRouter(Router * r) {
    return r->Next;
}

void flagConnection(Router * r, char * r1n, char * r2n) {
    Router * aux = findRouter(r, r1n);
    Connect * auxc;
    if(aux != NULL) {
        if(thereIsRRConnection(aux)) {
            auxc = findConnectionByRouter(getCNT(aux), r2n);
            auxc = flag(auxc);
        }
        aux = findRouter(r, r2n);
        if(aux != NULL) {
            if(thereIsRRConnection(aux)) {
                auxc = findConnectionByRouter(getCNT(aux), r1n);
                auxc = flag(auxc);
            }
        }
    }
    return;
}

void unflagAll(Router * r) {
    Router * aux = r;
    Connect * c;
    while(aux != NULL) {
        c = getCNT(aux);
        while(c != NULL) {
            unflag(c);
            c = nextCNT(c);
        }
        aux = aux->Next;
    }
    return;
}

/*
void printRouterAndConnections(Router * r) {
    Router * auxr = r;
    Connect * auxc;
    while(auxr != NULL) {
        auxc = auxr->cnt;
        printf("Router: %s\n", routerName(auxr));
        while(auxc != NULL) {
            printf("%s;", routerConnected(auxc));
            auxc = nextCNT(auxc);
        }
        printf("\n");
        auxr = nextRouter(auxr);
    }
    printf("\n");
    return;
}
*/
