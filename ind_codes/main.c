
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char* argc[]) {

    Router * rlist = (Router *)inicializeList();
    Terminal * tlist = (Terminal *)inicializeList();

    rlist = registerRouter(rlist, "router1", "gvt");
    rlist = registerRouter(rlist, "router2", "gvt");
    rlist = registerRouter(rlist, "router3", "vivo");
    rlist = registerRouter(rlist, "router4", "oi");

    tlist = registerTerminal(tlist, "terminal1", "vilavelha");
    tlist = registerTerminal(tlist, "terminal2", "maruipe");
    tlist = registerTerminal(tlist, "terminal3", "maruipe");

    printRouterAndTerminal(rlist,tlist);

    terminalFrequency(tlist, "maruipe");
    carrierFrequency(rlist, "gvt");

    linkRouterToTerminal("router1", rlist, "terminal1", tlist);
    linkRouterToTerminal("router2", rlist, "terminal3", tlist);
    linkRouterToTerminal("router3", rlist, "terminal2", tlist);

    printRouterAndTerminal(rlist,tlist);

    tlist = removeTerminal(tlist, "terminal2");
    tlist = removeTerminal(tlist, "terminal5");

    linkRouterToTerminal("router5", rlist, "terminal2", tlist);

    printRouterAndTerminal(rlist,tlist);

    return 0;
}
