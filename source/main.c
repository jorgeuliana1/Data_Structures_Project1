#include <stdio.h>
#include <stdlib.h>
#include "libs/router.h"
#include "libs/terminal.h"
#include "libs/readFile.h"
#include "libs/output.h"
#include "libs/dot.h"

void script3(int argv, char * argc[]) {
    FILE * f = openReadingFile(argv, argc);
    executeScript(f);
    closeReadingFile(f);
}

void script2(int argv, char * argc[]) {
    /*
    printf("\n");
    FILE * f = openReadingFile(argv, argc);
    Command * c = readCommand(f);
    c = destroyCommand(c);
    c = readCommand(f);
    char * str2 = getArgument(c, 0);
    char * str3 = getArgument(c, 1);
    char * str = getHeader(c);
    printf("%s %s %s\n", str, str2, str3);
    destroyCommand(c);
    closeReadingFile(f);
    return;
    */
}

int main(int argv, char* argc[]) {
    //script1();
    //script2(argv, argc);
    script3(argv, argc);
    return 0;
}
