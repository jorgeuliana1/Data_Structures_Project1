#ifndef TERMINAL_H
#define TERMINAL_H
#include "router.h"
typedef struct terminal Terminal;

/*
--inicializeTerminals--
Precondition: Terminal list in not inicialized.
Input: None.
Output: inicialized terminal list.
Postcondition: The terminal list is ready to be used.
*/
Terminal * inicializeTerminals();

/*
--findTerminal--
Precondition: Terminal list is inicialized and with at least a element inside.
Input: Terminal list and the searched teminal's name.
Output: Terminal with said name.
Postcondition: None.
*/
Terminal * findTerminal(Terminal * tlist, char * name);

/*
--findTerminalbyRouter--
Precondition: ?????
Input: ?????
Output: ?????
Postcondition: ?????
*/
Terminal * findTerminalbyRouter(Terminal * t, char * rn);

/*
--registerTerminal--
Precondition: Terminal * t is not inicialized.
Input: Inicialized terminal, terminal name and terminal location name.
Output: Updated terminal list.
Postcondition: Terminsl is inicialized and on the list.
*/
Terminal * registerTerminal(Terminal * t, char * n, char * l);

/*
--removeTerminal--
Precondition: Terminal is inicialized.
Input: Terminal list and terminal name.
Output: The list.
Postcondition: Terminal is removed from the network.
*/
Terminal * removeTerminal(Terminal * tlist, char * tname);

/*
--unlinkTerminal--
Precondition: Terminal is linked to a router.
Input: Terminal list and name.
Output: None.
Postcondition: Terminal doesn't have any links.
*/
void unlinkTerminal(Terminal * tlist, char * tname);

/*
--terminalFrequency--
Precondition: Terminal list is inicialized.
Input: Terminal list and name of the place.
Output: None.
Postcondition: The number of terminals in said place printed.
*/
void terminalFrequency(Terminal * tlist, char * place);

/*
--printTerminals--
Precondition: Terminal is inicilized.
Input: Terminal list.
Output: None.
Postcondition: Terminal list info is printed.
*/
void printTerminals(Terminal * t);

/*
--disconnectRouter--
Precondition: Terminal is linked to a router.
Input: Terminal list and name.
Output: None.
Postcondition: Terminal doesn't have any links.
*/
Terminal * disconnectRouter(Terminal * tlist, char * rn);

void linkRouterToTerminal(Router * rlist, char * rname, Terminal * tlist, char * tname);

/*
--decimateTerminals--
Precondition: Terminal list is inicialized.
Input: Inicialized terminal list.
Output: Empty terminal list.
Postcondition: All the terminals are destroyed.
*/
Terminal * decimateTerminals(Terminal * t);

char * terminalName(Terminal * t);

char * connectedRouterName(Terminal * t);

int thereIsTRConnection(Terminal * t);

Terminal * nextTerminal(Terminal * t);
#endif
