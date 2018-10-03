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

static Terminal * freeTerminal(Terminal * t){
    free(t->name);
    free(t->place);
    free(t);
    return NULL;
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

static int verifyTerminalsAccess(Router * rlist, Terminal * tlist, char * tname1, char * tname2) {
    /*
    --STEPS--
    1-DEFINING VARIABLES.
    2-CALLING GRAPH TRAVERSING FUNCTION.
    3-RETURNING TRUE OR FALSE.
    --VARIABLES NAMES--
    rlist:  Routers list.
    tlist:  Terminals list.
    tname1: Origin terminal name.
    tname2: Destiny terminal name.
    rname1: Router connected to terminal with tname1.
    rname2: Router connecter to terminal with tname2.
    --FUNCTION RETURNS--
    TRUE  - If it is possible to access t2 by t1.
    FALSE - If it is not possible to access t2 by t1.
    -1    - If t1 doesn't have any connection or doesn't exist.
    -2    - If t2 doesn't have any connection or doesn't exist.
    -3    - If t1 and t2 doesn't have any connection or doesn't exist.
    */
    //PART 1 - DEFINING VARIABLES (rname1 and rname2)
    char * rname1;
    char * rname2;
    Terminal * aux1 = tlist;
    while(aux1 != NULL) {
        if(!strcmp(aux1->name, tname1)) {
            if(aux1->r != NULL)
                rname1 = routerName(aux1->r);
            break;
        }
        aux1 = aux1->Next;
    }
    Terminal * aux2 = tlist;
    while(aux2 != NULL) {
        if(!strcmp(aux2->name, tname2)) {
            if(aux2->r != NULL)
                rname2 = routerName(aux2->r);
            break;
        }
        aux2 = aux2->Next;
    }
    //Verifications
    if(aux1 == NULL && aux2 == NULL) return -3;
    else if(aux1 == NULL) return -1;
    else if(aux2 == NULL) return -2;
    else if(rname1 == NULL && rname2 == NULL) return -3;
    else if(rname1 == NULL) return -1;
    else if(rname2 == NULL) return -2;
    //PART 2 AND 3
    return routersGraphSearch(rlist, findRouter(rlist, rname1), rname2);
}
//END OF STATIC FUNCTIONS AREA
int checkTRConnection(Terminal * tlist, char * rname, char * tname) {
    //NEED TO FIX THIS!!!!!
    /*provisory --- will affect functions*/ return FALSE;
    Terminal * aux = tlist;
    while(aux != NULL) {
        if(aux->r != NULL && !strcmp(routerName(aux->r), rname) && !strcmp(terminalName(aux), tname)) return TRUE;
        aux = aux->Next;
    }

    return FALSE;
}
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
    if(wasntFound(wanted)) {
        if(veriFile) fprintf(l, "ERROR: %s can't be removed, there isn't a terminal with this name.\n\n", tname);
        return NULL;
    } else if (before == NULL) { //First item
        tlist = wanted->Next;
    } else if(wanted->Next == NULL){ //Last item
        before->Next == NULL;
    } else { //Middle item
        before->Next = wanted->Next;
    }
    wanted = freeTerminal(wanted);
    return tlist;
}

void terminalFrequency(Terminal * tlist, char * place, FILE * o) {
    int i = 0;
    while(tlist != NULL) {
        if(!strcmp(tlist->place,place))
            i++;
        tlist = tlist->Next;
    }
    fprintf(o, "FREQUENCIATERMINAL %s: %d\n", place, i);
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

int sendDataPackage(Terminal * t, Router * r, char * ton, char * tdn, FILE * file, int veriFile, FILE * log, int veriLog) {
    //t:    Terminal list.
    //r:    Router list.
    //ton:  Origin terminal name.
    //tdn:  Target terminal name.
    Terminal * auxt1 = findTerminal(t, ton);
    Terminal * auxt2 = findTerminal(t, tdn);
    if(auxt1 == NULL) {
        if(veriLog) fprintf(log, "ERROR: Origin terminal %s doesn't exist.\n", ton);
        return -1;
    }
    if(auxt2 == NULL) {
        if(veriLog) fprintf(log, "ERROR: Destination terminal %s doesn't exist.\n", tdn);
        return -1;
    }
    if(auxt1->r != NULL) {
        if(verifyTerminalsAccess(r, t, ton, tdn) == TRUE) {
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
