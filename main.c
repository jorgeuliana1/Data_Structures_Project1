#include <stdio.h>
#include <stdlib.h>
#include "net.h"

int main(int argv, char* argc[]) {
    Router * rlist = NULL;
    Terminal * tlist = NULL;

    rlist = registerRouter(rlist, "router1", "gvt");
    rlist = registerRouter(rlist, "router2", "oivelox");
    rlist = registerRouter(rlist, "router3", "gatonet");
    tlist = registerTerminal(tlist, "terminal1", "vilavelha");
    tlist = registerTerminal(tlist, "terminal2", "vitoria");
    tlist = registerTerminal(tlist, "terminal3", "maruipe");

    printRouterAndTerminal(rlist, tlist);

    rlist = removeRouter(rlist, tlist, "router2");
    tlist = removeTerminal(rlist, tlist, "terminal2");

    printRouterAndTerminal(rlist, tlist);

    linkRouterToTerminal("router1", rlist, "terminal1", tlist);

    printRouterAndTerminal(rlist,tlist);

    return 0;
}
