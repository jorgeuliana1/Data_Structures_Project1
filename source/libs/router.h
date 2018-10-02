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
Router * registerRouter(Router * r, char * n, char * o, FILE * l);

/*
--removeRouter--
Precondition: Router and terminal are inicilized.
Input: Router and terminal lists and router name.
Output: List with removed router.
Postcondition: Router is removed from the network.
*/
Router * removeRouter(Router * rlist, char * rn, FILE * l, int veriFile);

/*
--carrierFrequency--
Precondition: Router list is inicialized.
Input: Router list and name of the carrier.
Output: None.
Postcondition: The number of routers from said carrier.
*/
void carrierFrequency(Router * rlist, char * carrier, FILE * o);

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

Router * webConnectRouters(Router * rlist, char * rn1, char * rn2, FILE * l, int veriFile);

Router * webDisconnectRouters(Router * rlist, char * rn1, char * rn2, FILE * l, int veriFile);

int thereIsRRConnection(Router * r);

Connect * getCNT(Router * r);

Router * nextRouter(Router * r);

int routersGraphSearch(Router * rlist, Router * ro, char * rname2);

void unflagRouter(Router * r, char * rn);

void flagRouter(Router * r, char * rn);

void unflagAllRouters(Router * r);

int isFlagged(Router * r, char * rn);

//void printRouterAndConnections(Router * r);

#endif
