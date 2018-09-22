#ifndef CONNECTION_H
#define CONNECTION_H
typedef struct connections Connect;

/*
--inicializeConnection--
Precondition: Connection is not inicilized.
Input: Not inicialized connection.
Output: Inicialized connection.
Postcondition: Connection is ready to be used.
*/
Connect * inicializeConnection(Connect * connect);

/*
--webConnectRoutersLL--
Precondition: Two routers are not connected.
Input: Connections list, routers list, routers names.
Output: Updated connection.
Postcondition: Routers are connected to each other.
*/
Connect * webConnectRouterLL(Connect * w, void * r, char * rn);

/*
--webConnectRoutersLL--
Precondition: Connection is not inicilized.
Input: Not inicialized connection.
Output: Inicialized connection.
Postcondition: Connection is ready to be used.
*/
Connect * destroyConnection(Connect * w, char * rn);

char * routerConnected(Connect * w);

void printConnections(Connect * w);
#endif
