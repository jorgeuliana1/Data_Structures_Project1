#include "router.h"
#include "terminal.h"
#include <stdlib.h>
#include <stdio.h>
void printRouterAndTerminal(Router * r, Terminal * t) {
    if(r != NULL)
      printRouters(r);
    if(t != NULL)
      printTerminals(t);
}

void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist) {
    Terminal * t = findTerminal(tlist, tname);
    Router * r = findRouter(rlist, rname);
    if(r != NULL && t != NULL) //t->r = r;
      insertRouterHere(t, r);
      //Deveria linkar o roteador ao terminal aqui, que pena...
    else printf("\nError: NOT FOUND\n\n");
}

Router * destroyRouter(Router * r, Terminal * t, char * rn) {
    t = disconnectRouter(t, rn);
    r = removeRouter(r, rn);
}
