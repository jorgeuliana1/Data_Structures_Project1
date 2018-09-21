#ifndef TERMINAL_H
#define TERMINAL_H
typedef struct terminal Terminal;

/*
--inicializeList--
Precondition: Terminal list in not inicialized.
Input: None.
Output: inicialized terminal list.
Postcondition: The terminal list is ready to be used.
*/
Terminal * inicializeList();

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
Input: Not inicialized terminal, terminal name and terminal location name.
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
--linkRouterToTerminal--
Precondition: Router and terminal are not linked.
Input: Router name, router list, terminal name, terminal list.
Output: None.
Postcondition: Terminal and router are linked.
*/
void linkRouterToTerminal(char * rname, Router * rlist, char * tname, Terminal * tlist);

/*
--unlinkTerminal--
Precondition: Terminal is linked to a router.
Input: Terminal name and list.
Output: None.
Postcondition: Terminal doesn't have any links.
*/
void unlinkTerminal(char * tname, Terminal * tlist);

/*
--terminalFrequency--
Precondition: Terminal list is inicialized.
Input: Terminal list and name of the place.
Output: None.
Postcondition: The number of terminals in said place printed.
*/
void terminalFrequency(Terminal * tlist, char * place);

//void printTerminals(Terminal * t);
#endif
