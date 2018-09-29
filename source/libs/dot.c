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
    static int counter = 0;
    counter++;
    if(counter > 1) fprintf(f, "//intermediario\n");
    fprintf(f, "strict graph {\n");
    Terminal * auxt = t;
    Router * auxr = r;
    Connect * auxc;
    while(auxt != NULL) {
        if(thereIsTRConnection(auxt))
            fprintf(f, "\t%s -- %s;\n", terminalName(auxt), connectedRouterName(auxt));
        else
            fprintf(f,"\t%s;\n", terminalName(auxt));
        auxt = nextTerminal(auxt);
    }
    while(auxr != NULL) {
        if(thereIsRRConnection(auxr)) {
            auxc = getCNT(auxr);
            while(auxc != NULL) {
                fprintf(f, "\t%s -- %s;\n", routerName(auxr), cntRouterName(auxc));
                auxc = nextCNT(auxc);
            }
        }
        else
            fprintf(f, "\t%s;\n", routerName(auxr));
        auxr = nextRouter(auxr);
    }
    fprintf(f, "}\n");
}
