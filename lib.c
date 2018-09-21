#include "router.h"
#include "terminal.h"
#include <stdlib.h>
#include <stdio.h>
void printRouterAndTerminal(Router * r, Terminal * t) {
    printRouters(r);
    printTerminals(t);
}

void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist) {
    Terminal * t = findTerminal(tlist, tname);
    Router * r = findRouter(rlist, rname);
    if(r != NULL && t != NULL) //t->r = r;
      printf("Jorge\n");
    else printf("\nError: NOT FOUND\n\n");
}

void destroyRouter(Router * r, Terminal * t, char * rn) {
    disconnectRouter(t, rn);
    r = removeRouter(r, rn);
}
