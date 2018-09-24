#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "router.h"
#include "terminal.h"
#include "readFile.h"
#include "cable.h"

//STRUCT AREA
struct command {
  int fCode;   //Function code.
  char * h;     //Saves the function header.
  char ** args; //Saves the arguments.
};
//END OF STRUCT AREA
//STATIC FUNCTIONS AREA

void * translateCode(Command * c, Router * rlist, Terminal * tlist) {
    switch(c->fCode){
        case 1:
            rlist = registerRouter(rlist, getArgument(c, 0), getArgument(c, 1));
            break;
        case 2:
            tlist = registerTerminal(tlist, getArgument(c, 0), getArgument(c, 1));
            break;
        case 3:
            rlist = removeRouter(rlist, getArgument(c, 0));
            break;
        case 4:
            linkRouterToTerminal(getArgument(c, 1), rlist, getArgument(c, 0), tlist);
            break;    
        case 5:
            unlinkTerminal(tlist, getArgument(c, 0));
            break;
        case 6:
            tlist = removeTerminal(tlist, getArgument(c, 0));
            break;    
        case 7:
            rlist = webConnectRouters(rlist, getArgument(c, 0), getArgument(c, 1));
            break;
        case 8:
            rlist = webDisconnectRouters(rlist, getArgument(c, 0), getArgument(c, 1));
            break;
        case 9:
            terminalFrequency(tlist, getArgument(c, 0));
            break;
        case 10:
            carrierFrequency(rlist, getArgument(c, 0));
            break;
        case 11:
            //en viadados
            break;
        case 12:
            //imprimenet
            break;            
        case 13:
            //fim
            break;                        
    }
}


static int functionCode(char * f) {
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
    else if(!strcmp("ENVIARPACOTEDADOS", f)) return 11;
    else if(!strcmp("IMPRIMENETMAP", f)) return 12;
    else if(!strcmp("FIM", f)) return 13;
    else return 0;
}

static int numArgs(int n) {
    if(n == 12 || n == 13) return 0;
    else if(n == 1 || n == 4 || n == 7 || n == 8 || n == 11) return 2;
    else if(n == 0) return -1;
    else return 1;
}
//END OF STATIC FUNCTIONS AREA
//FUNCTIONS AREA
FILE * openReadingFile(int argv, char * argc[]) {
    FILE * f;
    if(argv > 1)
        f = fopen(argc[1], "r");
    else
        printf("ERROR: File not informed.\n");
    if(f == NULL) {
        printf("ERROR: Invalid file. Will result in SegFault.\n");
    }
    return f;
}

int endOfFile(Command * c){
    return c->fCode == 13;
}

Command * readCommand(FILE * f) {
    Command * c;
    c = (Command *)malloc(sizeof(Command));
    char temp[100];
    fscanf(f, "%s", temp);
    c->h = (char *)malloc(sizeof(char)*(strlen(temp)+1));
    strcpy(c->h, temp);
    c->fCode = functionCode(c->h);
    int n = numArgs(c->fCode);
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

void closeReadingFile(FILE * f) {
    fclose(f);
    return;
}

char * getArgument(Command * c, int n) {
    if(n > numArgs(c->fCode) - 1) {
        printf("ERROR: Argument does not exist.\n");
        return "Error";
    }
    else {
        return c->args[n];
    }
}

char * getHeader(Command * c) {
    return c->h;
}
//END OF FUNCTIONS AREA
