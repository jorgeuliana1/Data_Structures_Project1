#include <stdio.h>
#include <stdlib.h>
#include "libs/router.h"
#include "libs/terminal.h"
#include "libs/readFile.h"
#include "libs/output.h"
#include "libs/dot.h"

int main(int argv, char* argc[]) {
    //argc[1] contains the location of the input file.
    //Doing inicializations.
    FILE * o = startOutputFile();
    //FILE * o: Output file "saida.txt"
    FILE * l = startLogFile();
    //FILE * l: Log file "log.txt"
    FILE * f = openReadingFile(argv, argc, l);
    //FILE * f: Input file
    /*
    If the input file was informed and exists the program will read the
    commands and execute it.
    */
    if(f != NULL) runScript(f, l, o);
    //Finishing the program.
    f = closeFile(f);
    l = closeFile(l);
    o = closeFile(o);
    return 0;
}
