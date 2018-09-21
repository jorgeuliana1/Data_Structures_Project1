#ifndef ROUTER_H
#define ROUTER_H
typedef struct router Router;

/*
--inicializeList--
Precondition: Router list in not inicialized.
Input: None.
Output: inicialized Router list.
Postcondition: The Router list is ready to be used.
*/
Router * inicializeList();

/*
--findRouter--
Precondition: Router list is inicialized and with at least a element inside.
Input: Router list and the searched Router's name.
Output: Router with said name.
Postcondition: None.
*/
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
Router * removeRouter(Router * r, Terminal * ter, char * rn);

/*
--carrierFrequency--
Precondition: Router list is inicialized.
Input: Router list and name of the carrier.
Output: None.
Postcondition: The number of routers from said carrier.
*/
void carrierFrequency(Router * rlist, char * carrier);

/*
--routerName--
Precondition: 'r' is an inicialized router.
Input: The router with the requested name.
Output: The router's name.
Postcondition: None.
*/
char * routerName(Router * r);


void printRouters(Router * r);
#endif
