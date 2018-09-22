#ifndef LIB_H
#define LIB_H
/*
--printRouterAndTerminal--
Precondition: Router and terminal are inicilized.
Input: Router and terminal lists.
Output: None.
Postcondition: All routers and terminals are printed.
*/
void printRouterAndTerminal(Router * r, Terminal * t);

/*
--linkRouterToTerminal--
Precondition: Router and terminal are not linked.
Input: Router name, router list, terminal name, terminal list.
Output: None.
Postcondition: Terminal and router are linked.
*/
void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist);

/*
--destroyRouter--
Precondition: Router and Terminal are linked.
Input: Router list, router name, terminal list, terminal name.
Output: None.
Postcondition: Terminal and router are no more linked.
*/
Router * destroyRouter(Router * r, Terminal * t, char * rn);
#endif
