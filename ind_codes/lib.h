#ifndef LIB_H
#define LIB_H

typedef struct router Router;
typedef struct terminal Terminal;

Router * registerRouter(Router * r, char * n, char * o);
Terminal * registerTerminal(Terminal * t, char * n, char * l);
Terminal * removeTerminal(Terminal * tlist, char * tname);
void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist);
void unlinkTerminal(char * tname, Terminal * tlist);
void carrierFrequency(Router * rlist, char * carrier);
void terminalFrequency(Terminal * tlist, char * place);
void printRouterAndTerminal(Router * r, Terminal * t);
void * inicializeList();

#endif
