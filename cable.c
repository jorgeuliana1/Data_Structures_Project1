#include <stdlib.h>
#include <stdio.h>
#include "router.h"
#include "terminal.h"
#include "connection.h"
#include "readFile.h"
#include "dot.h"
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

void executeScript(FILE * f) {
    int i = 1;
    Command * c;
    Router * r = inicializeRouters();
    Terminal * t = inicializeTerminals();
    int id;
    char * str1;
    char * str2;
    char * str3;
    while(i) {
        c = readCommand(f);
        id = getFID(c);
        //DEBUGGING
        char * str1 = getArgument(c, 0);
        char * str2 = getArgument(c, 1);
        char * str3= getHeader(c);
        printf("%s %s %s\n", str3, str1, str2);
        printf("function\n");
        //END OF DEBUGGING
        switch(id) {
            case 1:
                //REGISTERROUTER
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                r = registerRouter(r, str1, str2);
                break;
            case 2:
                //REGISTERTERMINAL
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                t = registerTerminal(t, str1, str2);
                break;
            case 3:
                //REMOVEROUTER
                str1 = getArgument(c, 0);
                r = removeRouter(r, str1);
                break;
            case 4:
                //CONNECTTERMINAL
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                linkRouterToTerminal(r, str2, t, str1);
                break;
            case 5:
                //DISCONNECTTERMINAL
                str1 = getArgument(c, 0);
                unlinkTerminal(t, str1);
                break;
            case 6:
                //REMOVETERMINAL
                str1 = getArgument(c, 0);
                t = removeTerminal(t, str1);
                break;
            case 7:
                //CONNECTROUTERS
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                r = webConnectRouters(r, str1, str2);
                break;
            case 8:
                //DISCONNECTROUTERS
                str1 = getArgument(c, 0);
                str2 = getArgument(c, 1);
                r = webDisconnectRouters(r, str1, str2);
                break;
            case 9:
                //TERMINALFREQUENCY
                str1 = getArgument(c, 0);
                terminalFrequency(t, str1);
                break;
            case 10:
                //CARRIERFREQUENCY
                str1 = getArgument(c, 0);
                carrierFrequency(r, str1);
                break;
            case 11:
                //SENDDATAPACKAGE
                //WE DON'T HAVE THIS RIGHT NOW
                break;
            case 12:
                //PRINTNETMAP
                createDot(t, r);
                break;
            case 13:
                i = 0;
                break;
        }
        c = destroyCommand(c);
    }
    r = decimateRouters(r);
    t = decimateTerminals(t);
    return;
}
