#include <stdio.h>
#include <stdlib.h>
#include "temp_lib.h"

int main(int argv, char* argc[]) {
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
  printRouter(r);
  //END TEST BLOCK
  return 0;
}
