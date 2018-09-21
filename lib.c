#include "router.h"
#include "terminal.h"

void printRouterAndTerminal(Router * r, Terminal * t) {
    printRouters(r);
    printTerminals(t);
}

void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist) {
    Terminal * t = findTerminal(tlist, tname);
    Router * r = findRouter(rlist, rname);
    if(r != NULL && t != NULL)
      t->r = r;
    else printf("\nError: NOT FOUND\n\n");
}
