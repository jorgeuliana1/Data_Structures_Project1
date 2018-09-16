#include <stdlib.h>
#include "net.h"
#include "router.h"
#include "terminal.h"

struct routerlist {
  RouterCell * first;
};

struct routercell {
  Router * item;
  RouterCell * next;
};

struct terminallist {
  TerminalCell * first;
};

struct terminalcell {
  Terminal * item;
  TerminalCell * next;
};

void inicializeTermList(TerminalList * l) {
  l = (TerminalList*)malloc(sizeof(TerminalList));
  l->first = NULL;
  return;
}

void inicializeRoutList(RouterList * l) {
  l = (RouterList*)malloc(sizeof(RouterList));
  l->first = NULL;
  return;
}
