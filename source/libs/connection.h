#ifndef CONNECTION_H
#define CONNECTION_H
/*
--ABOUT THIS LIBRARY--
It is responsible for the Connect type functions.
*/

typedef struct connections Connect;

/*
--Inicialize connection--
Precondition: Connection is not inicialized.
Input: Not inicialized connection.
Output: Inicialized connection.
Postcondition: Connection is ready to be used.
*/
Connect * inicializeConnection(Connect * connect);

/*
--Add connection--
Precondition: Two routers are not connected.
Input: Connections list, routers list and the name of the router
to be connected.
Output: Updated connections list.
Postcondition: Routers are connected to each other.
*/
Connect * addConnection(Connect * w, void * r, char * rn);

/*
--Remove connection--
Precondition: Connection exists.
Input: Connections list and name of the router to be disconnected.
Output: Updated connections list.
Postcondition: Routers are disconnected.
*/
Connect * removeConnection(Connect * w, char * rn);

/*
--Next connection--
Precondition: Connection list is inicialized.
Input: Connection.
Output: Next connection in the list.
Postcondition: List advanced one position.
*/
Connect * nextCNT(Connect * w);

/*
--Connected router name--
Precondition: Connection exists.
Input: Connection.
Output: String with the name of the connected router.
Postcondition: None.
*/
char * cntRouterName(Connect * w);

/*
--Find connection by router name--
Precondition: Connection list is inicialized.
Input: Connections list and name of the router to be found.
Output: Pointer to the connection.
Postcondition: None.
*/
Connect * findConnectionByRouter(Connect * w, char * rn);

#endif
