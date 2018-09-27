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
    if(counter > 1) fprintf(f, "//intermediario\n\n");
    fprintf(f, "strict graph {\n");
    Terminal * auxt = t;
    Router * auxr = r;
    //Cluster
    fprintf(f, "\tsubgraph clusterA {\n");
    fprintf(f, "\t\tlabel = \"Terminals\";\n");
    while(auxt != NULL) {
        fprintf(f, "\t\t%s;\n", terminalName(auxt));
        auxt = nextTerminal(auxt);
    }
    fprintf(f, "\t}\n");

    fprintf(f, "\tsubgraph clusterB {\n");
    fprintf(f, "\t\tlabel = \"Routers\";\n");
    while(auxr != NULL) {
        fprintf(f, "\t\t%s;\n", routerName(auxr));
        auxr = nextRouter(auxr);
    }
    auxt = t;
    auxr = r;
    fprintf(f, "\t}\n");
    //End of Cluster
    Connect * auxc;
    while(auxt != NULL) {
        if(thereIsTRConnection(auxt))
            fprintf(f, "\t%s -- %s;\n", terminalName(auxt), connectedRouterName(auxt));
        auxt = nextTerminal(auxt);
    }
    while(auxr != NULL) {
        if(thereIsRRConnection(auxr)) {
            auxc = getCNT(auxr);
            while(auxc != NULL) {
                if(!isFlagged(auxc))
                    fprintf(f, "\t%s -- %s\n", routerName(auxr), cntRouterName(auxc));
                flagConnection(r, routerName(auxr), cntRouterName(auxc));
                auxc = nextCNT(auxc);
            }
        }
        auxr = nextRouter(auxr);
    }
    unflagAll(r);
    fprintf(f, "}\n");
}
