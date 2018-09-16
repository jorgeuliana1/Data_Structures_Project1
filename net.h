#ifndef NET
#define NET

typedef struct routerlist RouterList;
typedef struct terminallist TerminalList;
typedef struct routercell RouterCell;
typedef struct terminalcell TerminalCell;

void inicializeTermList(TerminalList * l);
void insertTerm(TerminalList * l, Terminal * t);

#endif
