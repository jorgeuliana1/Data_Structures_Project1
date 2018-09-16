#include <stdio.h>
#include <stdlib.h>
#include "net.h"
#include "list.h"
#include "router.h"
#include "terminal.h"

int main() {
  //Add main functions here
  //START TEST BLOCK
  Router * r;
  Terminal * t;
  registerRouter(r, "router1", "gvt");
  registerTerminal(t, "terminal1", "VV");
  List * rl;
  List * tl;
  inicializeList(rl);
  insertRouter(rl, r);
  inicializeList(tl);
  insertTerminal(tl, t);
  linkRouterToTerminal(r, t);
  printRouter(tl->first->r);
  //END TEST BLOCK
  return 0;
}
