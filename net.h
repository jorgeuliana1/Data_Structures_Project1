#ifndef NET_H
#define NET_H

typedef struct router Router;
typedef struct terminal Terminal;


/*
--registerRouter--
Precondition: Router * r is not inicialized.
Input: Not inicialized router, router name and router carrier name.
Output: Updated router list.
Postcondition: Router is inicialized and on the list.
*/
Router * registerRouter(Router * r, char * n, char * o);
/*
--registerTerminal--
Precondition: Terminal * t is not inicialized.
Input: Not inicialized terminal, terminal name and terminal location name.
Output: Updated terminal list.
Postcondition: Terminsl is inicialized and on the list.
*/
Terminal * registerTerminal(Terminal * t, char * n, char * l);
/*
--linkRouterToTerminal--
Precondition: Router and terminal are not linked.
Input: Router name, router list, terminal name, terminal list.
Output: None.
Postcondition: Terminal and router are linked.
*/
void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist);
/*
--printRouterAndTerminal--
Precondition: Router and terminal are inicilized.
Input: Router and terminal lists.
Output: None.
Postcondition: All routers and terminals are printed.
*/
void printRouterAndTerminal(Router * r, Terminal * t);

#endif
