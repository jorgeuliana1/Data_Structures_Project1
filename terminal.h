#ifndef TERMINAL_H
#define TERMINAL_H
typedef struct terminal Terminal;

void disconnectRouter(Terminal * t, char * rn);
Terminal * findTerminalbyRouter(Terminal * t, char * rn);
Terminal * findTerminal(Terminal * tlist, char * name);
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
Precondition: Router and terminal are inicilized.
Input: Router and terminal lists and terminal name.
Output: List with removed terminal.
Postcondition: Terminal is removed from the network.
*/
Terminal * removeTerminal(Terminal * ter, char * tn);

/*
--unlinkTerminal--
Precondition: Terminal is linked to a router.
Input: Terminal name and list.
Output: None.
Postcondition: Terminal hasn't any link.
*/
void unlinkTerminal(char * tname, Terminal * tlist);
void printTerminals(Terminal * t);
#endif
