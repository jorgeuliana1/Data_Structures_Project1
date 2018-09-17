#include <stdio.h>
#include <stdlib.h>
#include "temp_lib.h"

int main(int argv, char* argc[]) {
  //Add main functions here
  //START TEST BLOCK
  Router * r;
  Terminal * t;
  createRouter(r, "router1", "gvt");
  //printRouter(r);
  //END TEST BLOCK
  return 0;
}
