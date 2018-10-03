#ifndef READFILE_H
#define READFILE_H
/*
--ABOUT THIS LIBRARY--
It is responsible for the Command type functions.
Every function has an ID.
ID LIST:
1  - CADASTRAROTEADOR.
2  - CADASTRATERMINAL.
3  - REMOVEROTEADOR.
4  - CONECTATERMINAL.
5  - DESCONECTATERMINAL.
6  - REMOVETERMINAL.
7  - CONECTAROTEADORES.
8  - DESCONECTAROTEADORES.
9  - FREQUENCIATERMINAL.
10 - FREQUENCIAOPERADORA.
11 - ENVIARPACOTESDADOS.
12 - IMPRIMENETMAP.
13 - FIM.
*/
typedef struct command Command;

/*
--Open Reading File--
Precondition: FILE is not inicialized.
Input: Number of strings of the input and the strings given in the input.
Output: Inicialized FILE.
Postcondition: FILE is inicilized.
*/
FILE * openReadingFile(int argv, char * argc[], FILE * l);

/*
--Read Command--
Precondition: FILE is inicialized and Command is not inicialized.
Input: Inicialized FILE to be read.
Output: Command is inicilized and filled with a whole command line from the input file.
Postcondition: Command is ready to use.
*/
Command * readCommand(FILE * f);

/*
--Destroy Command--
Precondition: Command is inicialized and filled.
Input: Command.
Output: Not inicialized Command.
Postcondition: Command is not inicialized.
*/
Command * destroyCommand(Command * c);

/*
--Close Reading File--
Precondition: FILE is inicialized.
Input: FILE.
Output: None.
Postcondition: FILE is not inicialized.
*/
void closeReadingFile(FILE * f);

/*
--Get Argument--
Precondition: Command is inicialized and filled.
Input: Command and argument position (starts with 0).
Output: String with argument.
Postcondition: Same as precondition.
*/
char * getArgument(Command * c, int n);

/*
--Get Header--
Precondition: Command is inicialized and filled.
Input: Command.
Output: String with command header.
Postcondition: Same as precondition.
*/
char * getHeader(Command * c);

/*
--Get Function ID--
Precondition: Command is inicialized and filled.
Input: Command.
Output: Function ID.
Postcondition: Same as precondition.
*/
int getFID(Command * c);

#endif
