#include <stdio.h>
#include <stdlib.h>
#include "net.h"

int main(int argv, char* argc[]) {
    Router * rlist = NULL;
    Terminal * tlist = NULL;

    rlist = registerRouter(rlist, "router1", "gvt");
    tlist = registerTerminal(tlist, "terminal1", "vilavelha");
    tlist = registerTerminal(tlist, "terminal2", "vitoria");
    tlist = registerTerminal(tlist, "terminal3", "maruipe");

    printRouterAndTerminal(rlist,tlist);

    linkRouterToTerminal("router1", rlist, "terminal1", tlist);

    printRouterAndTerminal(rlist,tlist);

    return 0;
}
