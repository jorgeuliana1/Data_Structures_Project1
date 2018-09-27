#ifndef OUTPUT_H
#define OUTPUT_H

FILE * startLogFile();

FILE * startOutputFile();

FILE * closeFile(FILE * a);

void runScript(FILE * f, FILE * logFile, FILE * output);
#endif
