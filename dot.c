#include <stdio.h>
#include <stdlib.h>
#include "router.h"
#include "terminal.h"
//STATIC FUNTIONS AREA
FILE * openGVFile() {
    FILE * f = fopen("saida.dot", "w");
    return f;
}

FILE * closeGVFile(FILE * f) {
    fclose(f);
    return f;
}
//END OF STATIC FUNCTIONS AREA
void createDot(Terminal * t, Router * r) {
    FILE * f = openGVFile();
    fprintf(f, "strict graph {\n");
    Terminal * auxt = t;
    fprintf(f, "\tsubgraph clusterA {\n");
    fprintf(f, "\t\tlabel = \"Terminais\";\n");
    while(auxt != NULL) {
        fprintf(f, "\t\t%s;\n", terminalName(auxt));
        auxt = nextTerminal(auxt);
    }
    fprintf(f, "\t}\n");
    auxt = t;
    Router * auxr = r;
    Connect * auxc;
    fprintf(f, "\tsubgraph clusterB {\n");
    fprintf(f, "\t\tlabel = \"Roteadores\";\n");
    while(auxt != NULL) {
        if(thereIsTRConnection(auxt))
            fprintf(f, "\t\t%s -- %s;\n", terminalName(auxt), connectedRouterName(auxt));
        auxt = nextTerminal(auxt);
    }
    while(auxr != NULL) {
        if(thereIsRRConnection(auxr)) {
            auxc = getCNT(auxr);
            while(auxc != NULL) {
                if(!isFlagged(auxc))
                    fprintf(f, "\t\t%s -- %s\n", routerName(auxr), cntRouterName(auxc));
                flagConnection(r, routerName(auxr), cntRouterName(auxc));
                auxc = nextCNT(auxc);
            }
        }
        auxr = nextRouter(auxr);
    }
    unflagAll(r);
    fprintf(f, "\t}\n");
    fprintf(f, "}");
    f = closeGVFile(f);
}
