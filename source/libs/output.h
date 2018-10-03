#ifndef OUTPUT_H
#define OUTPUT_H
/*
--ABOUT THIS LIBRARY--
It is responsible for the execution of the script contained in input.txt.
*/

/*
--Start log file--
Precondition: Log file is not inicilized.
Input: None.
Output: Inicialized log file.
Postcondition: Log file is inicialized.
*/
FILE * startLogFile();

/*
--Start output file--
Precondition: Output file is not inicilized.
Input: None.
Output: Inicialized output file.
Postcondition: Output file is inicialized.
*/
FILE * startOutputFile();

/*
--Close file--
Precondition: File is inicilized.
Input: File to be closed.
Output: Closed file.
Postcondition: File is closed.
*/
FILE * closeFile(FILE * a);

/*
--Run script--
Precondition: All the files are inicialized.
Input: input.txt, log.txt, saida.txt.
Output: Inicialized output file.
Postcondition: Output file is inicialized.
*/
void runScript(FILE * f, FILE * logFile, FILE * output);
#endif
