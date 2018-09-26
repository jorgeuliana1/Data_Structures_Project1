#include <stdio.h>
#include <stdlib.h>
#include "router.h"
#include "terminal.h"
#include "readFile.h"
#include "cable.h"
#include "dot.h"

void script3(int argv, char * argc[]) {
    FILE * f = openReadingFile(argv, argc);
    executeScript(f);
    closeReadingFile(f);
}

void script2(int argv, char * argc[]) {
    /*
    printf("\n");
    FILE * f = openReadingFile(argv, argc);
    Command * c = readCommand(f);
    c = destroyCommand(c);
    c = readCommand(f);
    char * str2 = getArgument(c, 0);
    char * str3 = getArgument(c, 1);
    char * str = getHeader(c);
    printf("%s %s %s\n", str, str2, str3);
    destroyCommand(c);
    closeReadingFile(f);
    return;
    */
}

void script1() {
    //TESTING SCRIPT
    Router * r = inicializeRouters();
    Terminal * t = inicializeTerminals();
    r = registerRouter(r, "Router1", "Vivo");
    r = registerRouter(r, "Router2", "Claro");
    r = registerRouter(r, "Router3", "Oi");
    r = registerRouter(r, "Router4", "Tim");
    r = registerRouter(r, "Router5", "Fibra");
    t = registerTerminal(t, "Terminal1", "Vix");
    t = registerTerminal(t, "Terminal2", "Vix");
    t = registerTerminal(t, "Terminal3", "Vix");
    t = registerTerminal(t, "Terminal4", "Vix");
    t = registerTerminal(t, "Terminal5", "Vix");
    t = registerTerminal(t, "Terminal6", "VV");
    t = registerTerminal(t, "Terminal7", "VV");
    t = registerTerminal(t, "Terminal8", "Serra");
    t = registerTerminal(t, "Terminal9", "Cariacica");
    t = registerTerminal(t, "Terminal10", "Viana");
    t = registerTerminal(t, "Terminal11", "Guarapari");
    t = registerTerminal(t, "Terminal12", "Fundao");
    printf("\n----1----\n");
    printRouterAndTerminal(r, t);
    linkRouterToTerminal(r, "Router1", t, "Terminal1");
    linkRouterToTerminal(r, "Router1", t, "Terminal2");
    linkRouterToTerminal(r, "Router1", t, "Terminal3");
    linkRouterToTerminal(r, "Router1", t, "Terminal4");
    linkRouterToTerminal(r, "Router1", t, "Terminal5");
    linkRouterToTerminal(r, "Router2", t, "Terminal6");
    linkRouterToTerminal(r, "Router2", t, "Terminal7");
    linkRouterToTerminal(r, "Router3", t, "Terminal8");
    linkRouterToTerminal(r, "Router4", t, "Terminal9");
    linkRouterToTerminal(r, "Router5", t, "Terminal10");
    linkRouterToTerminal(r, "Router3", t, "Terminal11");
    linkRouterToTerminal(r, "Router4", t, "Terminal12");
    printf("\n----2----\n");
    printRouterAndTerminal(r, t);
    r = destroyRouter(r, t, "Router5");
    printf("\n----3----\n");
    printRouterAndTerminal(r, t);
    r = registerRouter(r, "Router6", "URSAL");
    r = webConnectRouters(r, "Router3", "Router4");
    r = webConnectRouters(r, "Router3", "Router6");
    r = webConnectRouters(r, "Router1", "Router6");
    r = webConnectRouters(r, "Router4", "Router6");
    printf("\n----4----\n");
    PrintRouterConnections(r);
    r = webDisconnectRouters(r, "Router3", "Router4");
    printf("\n----5----\n");
    PrintRouterConnections(r);
    createDot(t, r);
    r = webDisconnectRouters(r, "Router3", "Router6");
    r = webDisconnectRouters(r, "Router1", "Router6");
    r = webDisconnectRouters(r, "Router4", "Router6");
    printf("\n----6----\n");
    PrintRouterConnections(r);
    r = decimateRouters(r);
    t = decimateTerminals(t);
    printRouterAndTerminal(r, t);
    return;
}

int main(int argv, char* argc[]) {
    //script1();
    //script2(argv, argc);
    script3(argv, argc);
    return 0;
}
