#ifndef ROUTER_H
#define ROUTER_H
#include "connection.h"
/*
--ABOUT THIS LIBRARY--
It is responsible for the Router type functions.
*/

typedef struct router Router;

/*
--Inicialize router--
Precondition: Router list is not inicilized.
Input: None.
Output: Inicialized router list.
Postcondition: Router list is inicialized.
*/
Router * inicializeRouters();

/*
--Find router by name--
Precondition: Router list is inicialized and with at least one element
inside it.
Input: Router list and the target router name.
Output: Target router.
Postcondition: None.
*/
Router * findRouter(Router * rlist, char * name);

/*
--Register router--
Precondition: Router is inicialized.
Input: Inicialized router list, router name, carrier name and log file.
Output: Updated router list.
Postcondition: Router is inicialized and included at the list.
*/
Router * registerRouter(Router * r, char * n, char * o, FILE * l);

/*
--Remove router--
Precondition: Router exists.
Input: Router list and router name, log file and confirmation if the user
wants to print the messages on the file.
Output: Updated router list.
Postcondition: Router is removed from the network.
*/
Router * removeRouter(Router * rlist, char * rn, FILE * l, int veriFile);

/*
--Carrier frequency--
Precondition: Router list is inicialized.
Input: Router list, name of the carrier and output file.
Output: None.
Postcondition: The number of routers with said carrier printed.
*/
void carrierFrequency(Router * rlist, char * carrier, FILE * o);

/*
--Router name--
Precondition: Router exists.
Input: Router.
Output: String with the router name.
Postcondition: None.
*/
char * routerName(Router * r);

/*
--Decimate routers--
Precondition: Router list is inicialized.
Input: Inicialized router list.
Output: Empty router list.
Postcondition: All the routers are destroyed.
*/
Router * decimateRouters(Router * r);

/*
--Web-connect routers--
Precondition: Router list is inicialized.
Input: Router list, name of the routers, log file and log file verification.
Output: Updated router list.
Postcondition: Routers are connected.
*/
Router * webConnectRouters(Router * rlist, char * rn1, char * rn2, FILE * l, int veriFile);

/*
--Web-disconnect routers--
Precondition: Router list is inicialized.
Input: Router list, name of the routers, log file and log file verification.
Output: Updated router list.
Postcondition: Routers are disconnected.
*/
Router * webDisconnectRouters(Router * rlist, char * rn1, char * rn2, FILE * l, int veriFile);

/*
--There is router-router connection--
Precondition: Router exists.
Input: Router.
Output: 1 if the router is connected to another router and 0 if it is not.
Postcondition: None.
*/
int thereIsRRConnection(Router * r);

/*
--Get connection--
Precondition: Router list is inicialized.
Input: Router.
Output: Router connection.
Postcondition: None.
*/
Connect * getCNT(Router * r);

/*
--Next router--
Precondition: Router exists.
Input: Router.
Output: Next router of the list.
Postcondition: None.
*/
Router * nextRouter(Router * r);

/*
--Routers graph search--
Precondition: Router list is inicialized.
Input: Inicialized router list, origin router, target router name.
Output: 1 if it is possible to access the target router from the origin router
and 0 if it is not possible to do it.
Postcondition: None.
*/
int routersGraphSearch(Router * rlist, Router * ro, char * rname2);

/*
--Unflag router--
Precondition: Router exists.
Input: Inicialized router list and target router name.
Output: None.
Postcondition: Target router is unflagged.
*/
void unflagRouter(Router * r, char * rn);

/*
--Flag router--
Precondition: Router exists.
Input: Inicialized router list and target router name.
Output: None.
Postcondition: Target router is flagged.
*/
void flagRouter(Router * r, char * rn);

/*
--Unflag all routers--
Precondition: Router list is inicilized.
Input: Inicialized router list.
Output: None.
Postcondition: All the routers of the list are unflagged.
*/
void unflagAllRouters(Router * r);

/*
--Is flagged--
Precondition: Router exists.
Input: Inicialized router list and target router name.
Output: 1 if the target router is flagged and 0 if it isn't flagged.
Postcondition: None.
*/
int isFlagged(Router * r, char * rn);

#endif
