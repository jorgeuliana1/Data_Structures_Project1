#ifndef ROUTER_H
#define ROUTER_H
typedef struct router Router;

Router * findRouter(Router * rlist, char * name);
/*
--registerRouter--
Precondition: Router * r is not inicialized.
Input: Not inicialized router, router name and router carrier name.
Output: Updated router list.
Postcondition: Router is inicialized and on the list.
*/
Router * registerRouter(Router * r, char * n, char * o);

/*
--removeRouter--
Precondition: Router and terminal are inicilized.
Input: Router and terminal lists and router name.
Output: List with removed router.
Postcondition: Router is removed from the network.
*/
Router * removeRouter(Router * r, char * rn);
void printRouters(Router * r);
char * routerName(Router * r);
#endif
