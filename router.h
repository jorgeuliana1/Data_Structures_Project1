#ifndef ROUTER_H
#define ROUTER_H

typedef struct router Router;
/*
---Register Router---
void registerRouter(Router * router, char * routerName, char * operatorName)
Precondition: Router is not inicialized.
Input: Not inicialized router, Router name, Router operator.
Output: None.
Postcondition: Router is inicialized.
*/
void registerRouter(Router * r, char * n, char * o);

#endif
