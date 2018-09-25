#ifndef ROUTER_H
#define ROUTER_H
#include "connection.h"

typedef struct router Router;

/*
--inicializeRouter--
Precondition: Router is not inicilized.
Input: Not inicialized router.
Output: Inicialized router.
Postcondition: Router inicilized.
*/
Router * inicializeRouters();

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
Router * removeRouter(Router * rlist, char * rn);

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

/*
--printRouters--
Precondition: Router list is inicialized.
Input: Inicialized Router.
Output: None.
Postcondition: Routers info is printed.
*/
void printRouters(Router * r);

/*
--decimateRouters--
Precondition: Router list is inicialized.
Input: Inicialized router list.
Output: Empty router list.
Postcondition: All the routers are destroyed.
*/
Router * decimateRouters(Router * r);

Router * webConnectRouters(Router * rlist, char * rn1, char * rn2);

Router * webDisconnectRouters(Router * rlist, char * rn1, char * rn2);

void PrintRouterConnections(Router * r);

int thereIsRRConnection(Router * r);

Connect * getCNT(Router * r);

Router * nextRouter(Router * r);

void flagConnection(Router * r, char * r1n, char * r2n);

void unflagAll(Router * r);

#endif
