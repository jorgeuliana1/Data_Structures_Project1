#ifndef DOT_H
#define DOT_H
/*
--ABOUT THIS LIBRARY--
It is responsible for the GraphViz functions.
*/

/*
--Open GraphViz file--
Precondition: None.
Input: None.
Output: Inicialized GraphViz file.
Postcondition: GraphViz file is inicilized and ready to be used.
*/
FILE * openGVFile();

/*
--Create .dot file--
Precondition: Terminal and Router lists are inicialized and .dot file
is inicialized.
Input: Terminals list, Routers list and pointer to the .dot file.
Output: None.
Postcondition: .dot file is filled and ready to be used.
*/
void createDot(Terminal * t, Router * r, FILE * f);

#endif
