#include <stdio.h>
#include <stdlib.h>
#include "router.h"
#include "terminal.h"
//STATIC FUNTIONS AREA

//END OF STATIC FUNCTIONS AREA
FILE * openGVFile() {
    FILE * f = fopen("saida.dot", "w");
    return f;
}

void createDot(Terminal * t, Router * r, FILE * f) {
    /*
    --VARIABLES--
    t: Terminals list.
    r: Routers list.
    f: File where the graph will be printed at.
    */

    /*
    If it is not the first time it calls the funtion "//intermediario" will
    be printed.
    */
    static int counter = 0;
    counter++;
    if(counter > 1) fprintf(f, "//intermediario\n\n");
    /*
    PRINTING STRICT GRAPH { AND INICIALIZING VARIABLES.
    */
    fprintf(f, "strict graph {\n");
    Terminal * auxt = t;
    Router * auxr = r;
    Connect * auxc;
    /*
    While there is any connection it is going to print.
    */
    //First it prints the terminal-router connections.
    while(auxt != NULL) {
        if(thereIsTRConnection(auxt))
            fprintf(f, "\t%s -- %s;\n", terminalName(auxt), connectedRouterName(auxt));
        else
            fprintf(f,"\t%s;\n", terminalName(auxt));
        auxt = nextTerminal(auxt);
    }
    //Then it prints the router-router connections.
    while(auxr != NULL) {
        if(thereIsRRConnection(auxr)) {
            auxc = getCNT(auxr);
            while(auxc != NULL) {
                fprintf(f, "\t%s -- %s;\n", routerName(auxr), cntRouterName(auxc));
                auxc = nextCNT(auxc);
            }
        }
        //If the router hasn't any connection it will be printed alone.
        else
            fprintf(f, "\t%s;\n", routerName(auxr));
        auxr = nextRouter(auxr);
    }
    //Printing the "}"
    fprintf(f, "}\n");
}
