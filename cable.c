#include <stdlib.h>
#include <stdio.h>
#include "router.h"
#include "terminal.h"
#include "connection.h"
//STATIC FUNCTIONS AREA


//END OF STATIC FUNCTIONS
void printRouterAndTerminal(Router * r, Terminal * t) {
    if(r != NULL)
        printRouters(r);
    if(t != NULL)
        printTerminals(t);
}

Router * destroyRouter(Router * r, Terminal * t, char * rn) {
    t = disconnectRouter(t, rn);
    r = removeRouter(r, rn);
}
