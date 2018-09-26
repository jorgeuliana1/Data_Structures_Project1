#ifndef CABLE_H
#define CABLE_H
/*
--printRouterAndTerminal--
Precondition: Router and terminal are inicilized.
Input: Router and terminal lists.
Output: None.
Postcondition: All routers and terminals are printed.
*/
void printRouterAndTerminal(Router * r, Terminal * t);

/*
--destroyRouter--
Precondition: Router and Terminal are linked.
Input: Router list, router name, terminal list, terminal name.
Output: None.
Postcondition: Terminal and router are no more linked.
*/
Router * destroyRouter(Router * r, Terminal * t, char * rn);

int sendDataPackage(Terminal * t, char * ori, char * des);

void executeScript(FILE * f);
#endif
