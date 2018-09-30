#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"
#define FALSE 0
#define TRUE 1

//STRUCT AREA
struct terminal {
    char * name;
    char * place;
    Terminal * Next;
    Router * r;
};
//END OF STRUCT AREA

//STATIC FUNCTIONS AREA
static char * adjustString(char * name) {
    char * space = (char *)malloc(strlen(name)*sizeof(char)+1);
    strcpy(space, name);
    return space;
}

static void freeTerminal(Terminal * t){
    free(t->name);
    free(t->place);
    free(t);
}

static int wasntFound(void * a){
    if(a == NULL)
        return 1;
    else
        return 0;
}

static Terminal * findPreviousTerminal(Terminal * t, Terminal * tw) {
    while(t != NULL && t->Next != tw) {
        t = t->Next;
    }
    return t;
}
//END OF STATIC FUNCTIONS AREA

Terminal * inicializeTerminals() {
    return NULL;
}

Terminal * findTerminal(Terminal * tlist, char * name) {
    while(tlist != NULL && strcmp(tlist->name, name)) {
        tlist = tlist->Next;
    }
    return tlist;
}

Terminal * findTerminalbyRouter(Terminal * t, char * rn) {
    while(t != NULL) {
      if(t->r != NULL) {
        if(strcmp(routerName(t->r),rn)) {
          t = t->Next;
        } else return t;
      } else t = t->Next;
    }
    return t;
}

Terminal * registerTerminal(Terminal * t, char * n, char * l, FILE * lf, int veriFile) {
    Terminal * aux = findTerminal(t, n);
    if(aux != NULL) {
        if(veriFile) fprintf(lf, "ERROR: %s can't be registered, there's a terminal with the same name.\n\n", n);
        return t;
    }
    Terminal * newTerminal = (Terminal*)malloc(sizeof(Terminal));
    newTerminal->name = adjustString(n);
    newTerminal->place = adjustString(l);
    newTerminal->r = NULL;

    if(!t) { //If terminal list is empty
        newTerminal->Next = NULL;
    } else { //If terminal list has elements
        newTerminal->Next = t;
    }
    return newTerminal;
}

Terminal * removeTerminal(Terminal * tlist, char * tname, FILE * l, int veriFile) {
    Terminal * wanted = findTerminal(tlist, tname);
    Terminal * before = findPreviousTerminal(tlist, wanted);
    if(wasntFound(wanted)) { //End of list
        if(veriFile) fprintf(l, "ERROR: %s can't be removed, there isn't a terminal with this name.\n\n", tname);
        return NULL;
    }else if (before == NULL) { //First item
        tlist = wanted->Next;
    }else if(wanted->Next == NULL){ //Last item
        before->Next == NULL;
    }else { //Middle item
        before->Next = wanted->Next;
    }
    freeTerminal(wanted);
    return tlist;
}

void terminalFrequency(Terminal * tlist, char * place, FILE * o) {
    int i = 0;
    while(tlist != NULL) {
        if(!strcmp(tlist->place,place))
            i++;
        tlist = tlist->Next;
    }
    fprintf(o, "TERMINALFREQUENCY %s: %d\n\n", place, i);
}

void unlinkTerminal(Terminal * tlist, char * tname, FILE * l, int veriFile) {
    Terminal * t = findTerminal(tlist, tname);
    if(wasntFound(t)) {
        if(veriFile) fprintf(l, "ERROR: %s can't be unlinked, there isn't a terminal with this name.\n\n", tname);
    }
    else
        t->r = NULL;
}

Terminal * disconnectRouter(Terminal * tlist, char * rn) {
    Terminal * t = tlist;
    while(t != NULL) {
        t = findTerminalbyRouter(tlist, rn);
        if(t != NULL && !strcmp(routerName(t->r), rn)) unlinkTerminal(tlist, t->name, NULL, FALSE);
    }
    return t;
}

void linkRouterToTerminal(Router * rlist, char * rname, Terminal * tlist, char * tname, FILE * l, int veriFile) {
    Terminal * t = findTerminal(tlist, tname);
    if(t == NULL) {
      if(veriFile) fprintf(l, "ERROR: %s can't be linked, there isn't a terminal with this name.\n\n", tname);
    }
    Router * r = findRouter(rlist, rname);
    if(r == NULL) {
      if(veriFile) fprintf(l, "ERROR: %s can't be linked, there isn't a router with this name.\n\n", rname);
    }
    if(r != NULL && t != NULL) t->r = r;
}

Terminal * decimateTerminals(Terminal * t) {
    Terminal * temp;
    while(t != NULL) {
        temp = t->Next;
        removeTerminal(t, t->name, NULL, FALSE);
        t = temp;
    }
    return NULL;
}

char * terminalName(Terminal * t) {
    return t->name;
}

char * connectedRouterName(Terminal * t) {
    return routerName(t->r);
}

int thereIsTRConnection(Terminal * t) {
    if(t->r == NULL) return 0;
    else return 1;
}

Terminal * nextTerminal(Terminal * t) {
    return t->Next;
}

int sendDataPackage(Terminal * t, Router * r, char * ton, char * tdn, FILE * file, int veriFile) {
    //t:    Terminal list.
    //r:    Router list.
    //ton:  Origin terminal name.
    //tnd:  Destination terminal name.
    Terminal * auxt1 = findTerminal(t, ton);
    Terminal * auxt2 = findTerminal(t, tdn);
    if(auxt1 == NULL) {
        if(veriFile) fprintf(file, "ERROR: Origin terminal %s doesn't exist.\n", ton);
        return -1;
    }
    if(auxt2 == NULL) {
        if(veriFile) fprintf(file, "ERROR: Destination terminal %s doesn't exist.\n", tdn);
        return -1;
    }
    if(t->r != NULL) {
        if(searchRoutersGraph(r, t, tdn, routerName(t->r)) ==  TRUE) {
            fprintf(file, "ENVIARPACOTESDADOS %s %s: SIM\n", ton, tdn);
            unflagAllRouters(r);
            return TRUE;
        }
        else {
            fprintf(file, "ENVIARPACOTESDADOS %s %s: NAO\n", ton, tdn);
            unflagAllRouters(r);
            return FALSE;
        }
    }
    fprintf(file, "ENVIARPACOTESDADOS %s %s: NAO\n", ton, tdn);
    return FALSE;
}
