#include <stdlib.h>
#include <stdio.h>
#include "router.h"
#include "terminal.h"
#include "connection.h"
#include "readFile.h"
#include "dot.h"
//STATIC FUNCTIONS AREA
static Router * destroyRouter(Router * r, Terminal * t, char * rn, FILE * logfile) {
    t = disconnectRouter(t, rn);
    Router * auxr = findRouter(r, rn);
    Connect * auxc;
    if(auxr != NULL && thereIsRRConnection(auxr)) {
        auxc = getCNT(auxr);
        while(auxc != NULL) {
            webDisconnectRouters(r, rn, cntRouterName(auxc), NULL, 0);
            auxc = nextCNT(auxc);
        }
    }
    r = removeRouter(r, rn, logfile);
}
//END OF STATIC FUNCTIONS AREA
FILE * startLogFile() {
    FILE * logFile = fopen("log.txt", "w");
}

FILE * startOutputFile() {
    FILE * output = fopen("saida.txt", "w");
}

FILE * closeFile(FILE * a) {
    fclose(a);
    return NULL;
}

void runScript(FILE * f, FILE * logFile, FILE * output) {
    int i = 1;
    Command * c;
    FILE * gv = openGVFile();
    Router * r = inicializeRouters();
    Terminal * t = inicializeTerminals();
    //ERROR FILE
    int id;
    char * str1;
    char * str2;
    while(i) {
        c = readCommand(f);
        id = getFID(c);
        switch(id) {
            case 1:
                //REGISTERROUTER
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                r = registerRouter(r, str1, str2, logFile);
                break;
            case 2:
                //REGISTERTERMINAL
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                t = registerTerminal(t, str1, str2, logFile);
                break;
            case 3:
                //REMOVEROUTER
                str1 = getArgument(c, 0);
                r = destroyRouter(r, t, str1, logFile);
                break;
            case 4:
                //CONNECTTERMINAL
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                linkRouterToTerminal(r, str2, t, str1, logFile);
                break;
            case 5:
                //DISCONNECTTERMINAL
                str1 = getArgument(c, 0);
                unlinkTerminal(t, str1, logFile);
                break;
            case 6:
                //REMOVETERMINAL
                str1 = getArgument(c, 0);
                t = removeTerminal(t, str1, logFile);
                break;
            case 7:
                //CONNECTROUTERS
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                r = webConnectRouters(r, str1, str2, logFile, 1);
                break;
            case 8:
                //DISCONNECTROUTERS
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                r = webDisconnectRouters(r, str1, str2, logFile, 1);
                break;
            case 9:
                //TERMINALFREQUENCY
                str1 = getArgument(c, 0);
                terminalFrequency(t, str1, output);
                break;
            case 10:
                //CARRIERFREQUENCY
                str1 = getArgument(c, 0);
                carrierFrequency(r, str1, output);
                break;
            case 11:
                //SENDDATAPACKAGE
                //WE DON'T HAVE THIS RIGHT NOW
                break;
            case 12:
                //PRINTNETMAP
                createDot(t, r, gv);
                break;
            case 13:
                //END
                i = 0;
                break;
        }
        c = destroyCommand(c);
    }
    r = decimateRouters(r);
    t = decimateTerminals(t);
    gv = closeFile(gv);
    return;
}
