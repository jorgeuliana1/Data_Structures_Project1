#include <stdio.h>
#include <stdlib.h>
#include "libs/router.h"
#include "libs/terminal.h"
#include "libs/readFile.h"
#include "libs/output.h"
#include "libs/dot.h"

int main(int argv, char* argc[]) {
    FILE * o = startOutputFile();
    FILE * l = startLogFile();
    FILE * f = openReadingFile(argv, argc, l);
    if(f != NULL) runScript(f, l, o);
    f = closeFile(f);
    l = closeFile(l);
    o = closeFile(o);
    return 0;
}
