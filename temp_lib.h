#ifndef TEMPLIB_H
#define TEMPLIB_H

typedef struct list List;
typedef struct cell Cell;
typedef struct router Router;
typedef struct terminal Terminal;

void registerRouter(Router * r, char * n, char * o);
void inicializeList(List * l);
void registerTerminal(Terminal * t, char * n, char * l);
void linkRouterToTerminal(Router * r, Terminal * t);
void insertRouter(List * l, Router * r);
void insertTerminal(List * l, Terminal * t);
void printRouter(Router * r);

#endif
