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
Terminal * registerTerminal(Terminal * t, char * n, char * l, FILE * lf, int veriFile);

/*
--removeTerminal--
Precondition: Terminal is inicialized.
Input: Terminal list and terminal name.
Output: The list.
Postcondition: Terminal is removed from the network.
*/
Terminal * removeTerminal(Terminal * tlist, char * tname, FILE * l, int veriFile);

/*
--unlinkTerminal--
Precondition: Terminal is linked to a router.
Input: Terminal list and name.
Output: None.
Postcondition: Terminal doesn't have any links.
*/
void unlinkTerminal(Terminal * tlist, char * tname, FILE * l, int veriFile);

/*
--terminalFrequency--
Precondition: Terminal list is inicialized.
Input: Terminal list and name of the place.
Output: None.
Postcondition: The number of terminals in said place printed.
*/
void terminalFrequency(Terminal * tlist, char * place, FILE * o);

/*
--disconnectRouter--
Precondition: Terminal is linked to a router.
Input: Terminal list and name.
Output: None.
Postcondition: Terminal doesn't have any links.
*/
Terminal * disconnectRouter(Terminal * tlist, char * rn);

void linkRouterToTerminal(Router * rlist, char * rname, Terminal * tlist, char * tname, FILE * l, int veriFile);

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

int sendDataPackage(Terminal * t, Router * r, char * ton, char * tdn, FILE * file, int veriFile, FILE * log, int veriLog);

#endif
