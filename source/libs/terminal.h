#ifndef TERMINAL_H
#define TERMINAL_H
#include "router.h"
/*
--ABOUT THIS LIBRARY--
It is responsible for the Terminal type functions.
*/

typedef struct terminal Terminal;

/*
--Inicialize terminal list--
Precondition: Terminal list in not inicialized.
Input: None.
Output: inicialized terminal list.
Postcondition: The terminal list is ready to be used.
*/
Terminal * inicializeTerminals();

/*
--Find terminal by name--
Precondition: Terminal list is inicialized and with at least one element
inside it.
Input: Terminals list and the target terminal name.
Output: Target terminal.
Postcondition: None.
*/
Terminal * findTerminal(Terminal * tlist, char * name);

/*
--Find terminal by router name--
Precondition: Terminal list is inicialized and with at least one element
inside it.
Input: Terminals list and the name of the router connected
to the target terminal.
Output: Target terminal.
Postcondition: None.
*/
Terminal * findTerminalbyRouter(Terminal * t, char * rn);

/*
--Register Terminal--
Precondition: Terminal * t is inicialized.
Input: Inicialized terminals list, terminal name, terminal location, log file
and confirmation if the user wants to print the messages on the file.
Output: Updated terminal list.
Postcondition: Terminal is inicialized and included at the list.
*/
Terminal * registerTerminal(Terminal * t, char * n, char * l, FILE * lf, int veriFile);

/*
--Remove Terminal--
Precondition: Terminal exists.
Input: Terminal list and terminal name, log file and confirmation if the user
wants to print the messages on the file.
Output: Update terminal list.
Postcondition: Terminal is removed from the network.
*/
Terminal * removeTerminal(Terminal * tlist, char * tname, FILE * l, int veriFile);

/*
--Unlink Terminal--
Precondition: Terminal is linked to a router.
Input: Terminal list, terminal name, log file and confirmation if the user wants
to print the messages on the file.
Output: None.
Postcondition: Terminal doesn't have any links.
*/
void unlinkTerminal(Terminal * tlist, char * tname, FILE * l, int veriFile);

/*
--Terminal frequency--
Precondition: Terminal list is inicialized.
Input: Terminal list and name of the place.
Output: None.
Postcondition: The number of terminals in said place printed.
*/
void terminalFrequency(Terminal * tlist, char * place, FILE * o);

/*
--Disconnect router--
Precondition: Terminal is linked to a router.
Input: Terminal list and terminal name.
Output: None.
Postcondition: Terminal doesn't have any links.
*/
Terminal * disconnectRouter(Terminal * tlist, char * rn);

/*
--Link router to terminal--
Precondition: Terminal and router are inicialized.
Input: Router list, router name, terminal list, terminal name, log file and
confirmation if the user wants to print the messages on the file.
Output: None.
Postcondition: Router is linked to terminal.
*/
void linkRouterToTerminal(Router * rlist, char * rname, Terminal * tlist, char * tname, FILE * l, int veriFile);

/*
--Decimate terminals--
Precondition: Terminal list is inicialized.
Input: Inicialized terminal list.
Output: Empty terminal list.
Postcondition: All the terminals are destroyed.
*/
Terminal * decimateTerminals(Terminal * t);

/*
--Terminal name--
Precondition: Terminal exists.
Input: Terminal.
Output: String with the terminal name.
Postcondition: None.
*/
char * terminalName(Terminal * t);

/*
--Connected router name--
Precondition: Terminal exists and there is a router connected to it.
Input: Terminal.
Output: String with the name of the router connected to the terminal.
Postcondition: None.
*/
char * connectedRouterName(Terminal * t);

/*
--There is terminal-router connection--
Precondition: Terminal exists.
Input: Terminal.
Output: 1 if the terminal is connected to a router and 0 if it is not.
Postcondition: None.
*/
int thereIsTRConnection(Terminal * t);

/*
--Next terminal--
Precondition: Terminal exists.
Input: Terminal.
Output: Next terminal of the list.
Postcondition: None.
*/
Terminal * nextTerminal(Terminal * t);

/*
--Send data package--
Precondition: Terminal list is inicialized, router list is inicialized.
Input: Terminal list, router list, origin terminal name, target terminal name,
output file, verification of input file, log file, verification of log file.
Output: 1 if the the data package can be sent and 0 if it can't.
Postcondition: None.
*/
int sendDataPackage(Terminal * t, Router * r, char * ton, char * tdn, FILE * file, int veriFile, FILE * log, int veriLog);

#endif
