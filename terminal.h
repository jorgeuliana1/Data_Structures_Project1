#ifndef TERMINAL_H
#define TERMINAL_H
typedef struct termlist TermList;

/*
--inicializeTerminals--
Precondition: Terminal list in not inicialized.
Input: None.
Output: inicialized terminal list.
Postcondition: The terminal list is ready to be used.
*/
TermList * inicializeTerminals();

/*
--findTerminal--
Precondition: Terminal list is inicialized and with at least a element inside.
Input: Terminal list and the searched teminal's name.
Output: Terminal with said name.
Postcondition: None.
*/
Terminal * findTerminal(TermList * tlist, char * name);

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
Precondition: TermList is inicialized.
Input: Terminal list, terminal name and terminal location name.
Output: None.
Postcondition: Terminal is inicialized and on the list.
*/
void registerTerminal(TermList * t, char * n, char * l);

/*
--removeTerminal--
Precondition: Terminal is inicialized.
Input: Terminal list and terminal name.
Output: None.
Postcondition: Terminal is removed from the network.
*/
void removeTerminal(TermList * tlist, char * tname);

/*
--unlinkTerminal--
Precondition: Terminal is linked to a router.
Input: Terminal list and name.
Output: None.
Postcondition: Terminal doesn't have any links.
*/
void unlinkTerminal(TermList * tlist, char * tname);

/*
--terminalFrequency--
Precondition: Terminal list is inicialized.
Input: Terminal list and name of the place.
Output: None.
Postcondition: The number of terminals in said place printed.
*/
void terminalFrequency(TermList * tlist, char * place);

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

/*
--plugRouter--
W A R N I N G: This function is "low level" and doesn't do any verification.
USE CAREFULLY.
Precondition: Terminal is inicialized and doesn't have any link.
Input: Terminal and router to be linked.
Output: None.
Postcondition: Terminal is linked to router.
*/
void plugRouter(Terminal * t, void * a);

/*
--decimateTerminals--
Precondition: Terminal list is inicialized.
Input: Inicialized terminal list.
Output: None.
Postcondition: All the terminals are destroyed.
*/
void decimateTerminals(TermList * t);
#endif
