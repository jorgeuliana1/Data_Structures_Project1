#include <stdio.h>
#include <stdlib.h>
#include "connections.h"
#include "router.h"
#include "terminal.h"
#include "readFile.h"
#include "lib.h"

void script2(int argv, char * argc[]) {
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
    printf("\n----1----\n\n");
    printRouterAndTerminal(r, t);
    linkRouterToTerminal("Router1", r, "Terminal1", t);
    linkRouterToTerminal("Router1", r, "Terminal2", t);
    linkRouterToTerminal("Router1", r, "Terminal3", t);
    linkRouterToTerminal("Router1", r, "Terminal4", t);
    linkRouterToTerminal("Router1", r, "Terminal5", t);
    linkRouterToTerminal("Router2", r, "Terminal6", t);
    linkRouterToTerminal("Router2", r, "Terminal7", t);
    linkRouterToTerminal("Router3", r, "Terminal8", t);
    linkRouterToTerminal("Router4", r, "Terminal9", t);
    linkRouterToTerminal("Router5", r, "Terminal10", t);
    linkRouterToTerminal("Router3", r, "Terminal11", t);
    linkRouterToTerminal("Router4", r, "Terminal12", t);
    printf("\n----2----\n\n");
    printRouterAndTerminal(r, t);
    r = destroyRouter(r, t, "Router5");
    printf("\n----3----\n\n");
    printRouterAndTerminal(r, t);
    r = decimateRouters(r);
    t = decimateTerminals(t);
    printRouterAndTerminal(r, t);
    return;
}

int main(int argv, char* argc[]) {
    script1();
    script2(argv, argc);
    return 0;
}
