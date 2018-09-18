#ifndef LIB_H
#define LIB_H

typedef struct router Router;
typedef struct terminal Terminal;

Router * registerRouter(Router * r, char * n, char * o);
//void inicializeList(List * l);
Terminal * registerTerminal(Terminal * t, char * n, char * l);
void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist);
//void insertRouter(List * l, Router * r);
//Terminal * insertTerminal(List * l, Terminal * t);
void printRouterAndTerminal(Router * r, Terminal * t);

#endif
