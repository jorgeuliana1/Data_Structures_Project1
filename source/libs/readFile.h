#ifndef READFILE_H
#define READFILE_H

typedef struct command Command;

/*
--openReadingFile--
Precondition: FILE is not inicialized.
Input: Number of strings of the input and the strings given in the input.
Output: Inicialized FILE.
Postcondition: FILE is inicilized.
*/
FILE * openReadingFile(int argv, char * argc[], FILE * l);

/*
--readCommand--
Precondition: FILE is inicialized and Command is not inicialized.
Input: Inicialized FILE to be read.
Output: Command is inicilized and filled with a whole command line from the input file.
Postcondition: Command is ready to use.
*/
Command * readCommand(FILE * f);

/*
--destroyCommand--
Precondition: Command is inicialized and filled.
Input: Command.
Output: Not inicialized Command.
Postcondition: Command is not inicialized.
*/
Command * destroyCommand(Command * c);

/*
--closeReadingFile--
Precondition: FILE is inicialized.
Input: FILE.
Output: None.
Postcondition: FILE is not inicialized.
*/
void closeReadingFile(FILE * f);

/*
--getArgument--
Precondition: Command is inicialized and filled.
Input: Command and argument position (starts with 0).
Output: String with argument.
Postcondition: Same as precondition.
*/
char * getArgument(Command * c, int n);

/*
--getHeader--
Precondition: Command is inicialized and filled.
Input: Command.
Output: String with command header.
Postcondition: Same as precondition.
*/
char * getHeader(Command * c);

int getFID(Command * c);

#endif
