#ifndef CONNECTION_H
#define CONNECTION_H
typedef struct connections Connect;

Connect * inicializeConnection(Connect * connect);

Connect * webConnectRoutersLL(Connect * w, void * r, char * rn1, char * rn2);

Connect * destroyConnection(Connect * w, char * rn1, char * rn2);

void printConnections(Connect * w);
#endif
