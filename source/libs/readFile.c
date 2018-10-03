#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readFile.h"
#define FALSE 0
#define TRUE 1

//STRUCT AREA
struct command {
  int fCode;    //Function code.
  char * h;     //Saves the function header.
  char ** args; //Saves the arguments.
};
//END OF STRUCT AREA
//STATIC FUNCTIONS AREA
static int functionCode(char * f) {
    //It will return an ID to each function.
    if(!strcmp("CADASTRAROTEADOR", f)) return 1;
    else if(!strcmp("CADASTRATERMINAL", f)) return 2;
    else if(!strcmp("REMOVEROTEADOR", f)) return 3;
    else if(!strcmp("CONECTATERMINAL", f)) return 4;
    else if(!strcmp("DESCONECTATERMINAL", f)) return 5;
    else if(!strcmp("REMOVETERMINAL", f)) return 6;
    else if(!strcmp("CONECTAROTEADORES", f)) return 7;
    else if(!strcmp("DESCONECTAROTEADORES", f)) return 8;
    else if(!strcmp("FREQUENCIATERMINAL", f)) return 9;
    else if(!strcmp("FREQUENCIAOPERADORA", f)) return 10;
    else if(!strcmp("ENVIARPACOTESDADOS", f)) return 11;
    else if(!strcmp("IMPRIMENETMAP", f)) return 12;
    else if(!strcmp("FIM", f)) return 13;
    else return 0;
}

static int numArgs(int n) {
    //It will return the number of arguments of a specific funtion.
    if(n == 12 || n == 13) return 0;
    else if(n == 1 || n ==  2 || n == 4 || n == 7 || n == 8 || n == 11) return 2;
    else if(n == 0) return -1;
    else return 1;
}
//END OF STATIC FUNCTIONS AREA
//FUNCTIONS AREA
FILE * openReadingFile(int argv, char * argc[], FILE * l) {
    FILE * f;
    if(argv > 1)
        f = fopen(argc[1], "r");
    else {
        fprintf(l, "I/O ERROR: File not informed.\n\n");
        exit(0);
    }
    if(f == NULL) {
        fprintf(l, "I/O ERROR: Invalid file. Will result in SegFault.\n\n");
    }
    return f;
}

Command * readCommand(FILE * f) {
    Command * c;
    c = (Command *)malloc(sizeof(Command));
    char temp[100];
    //GET THE FUNCTION HEADER
    fscanf(f, "%s", temp);
    c->h = (char *)malloc(sizeof(char)*(strlen(temp)+1));
    strcpy(c->h, temp);
    //TRANSFORM THE HEADER IN ID
    c->fCode = functionCode(c->h);
    int n = numArgs(c->fCode);
    //GET ALL THE ARGUMENTS
    c->args = (char **)malloc(sizeof(char*)*n);
    int i;
    for(i = 0; i < n; i++) {
        fscanf(f, "%s", temp);
        c->args[i] = (char *)malloc(sizeof(char)*(strlen(temp)+1));
        strcpy(c->args[i], temp);
    }
    fgetc(f);
    return c;
}

Command * destroyCommand(Command * c) {
    int n = numArgs(c->fCode);
    int i;
    for(i = n - 1; i >= 0; i--) {
        free(c->args[i]);
    }
    free(c->args);
    free(c->h);
    free(c);
    return NULL;
}

char * getArgument(Command * c, int n) {
    if(n > numArgs(c->fCode) - 1) {
        return "(error)";
    }
    else {
        return c->args[n];
    }
}

char * getHeader(Command * c) {
    return c->h;
}

int getFID(Command * c) {
    return c->fCode;
}
//END OF FUNCTIONS AREA
