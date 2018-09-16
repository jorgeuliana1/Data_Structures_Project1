#ifndef TERMINAL
#define TERMINAL

typedef struct terminal Terminal;
/*
---Register Router---
void registerTerminal(Terminal * terminal, char * terminalName, char * localization)
Precondition: Terminal is not inicialized.
Input: Not inicialized terminal, Terminal name, Terminal localization.
Output: None.
Postcondition: Terminal is inicialized.
*/
void registerTerminal(Terminal * t, char * n, char * l);
void inicializeRoutList(RouterList * l);
#endif
