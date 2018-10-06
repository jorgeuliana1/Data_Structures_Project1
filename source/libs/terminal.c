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
static char * adjustString(char * str) {
    //This function allocates exactly the necessary size.
    char * newStr = (char *)malloc(strlen(str)*sizeof(char)+1);
    //Then it copies the content to the allocated string.
    strcpy(newStr, str);
    //And returns it.
    return newStr;
}

static Terminal * freeTerminal(Terminal * t) {
    //This function frees the terminal and returns NULL.
    free(t->name);
    free(t->place);
    free(t);
    return NULL;
}

static int wasntFound(void * a) {
    //If something wasn't found it will result in NULL, this function verifies this.
    if(a == NULL)
        return 1;
    else
        return 0;
}

static Terminal * findPreviousTerminal(Terminal * t, Terminal * tw) {
    /*
    This function searches for the previous terminal in relation to the
    informed terminal.
    */
    while(t != NULL && t->Next != tw) {
        t = t->Next;
    }
    /*
    If it doesn't find any terminal it will return NULL.
    It only happens when the list is empty or you are looking for the first
    element in the list.
    */
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
    //Declaring variables
    char * rname1;
    char * rname2;
    Terminal * aux1 = tlist;
    //Seaching for the routers that are connected to the informed terminal.
    while(aux1 != NULL) {
        if(!strcmp(aux1->name, tname1)) {
            if(aux1->r != NULL)
                rname1 = routerName(aux1->r);
            break;
        }
        aux1 = aux1->Next;
    }
    Terminal * aux2 = tlist;
    //Seaching for the routers that are connected to the informed terminal.
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
    //If there isn't any problem, it will return the result of the graph search.
    return routersGraphSearch(rlist, findRouter(rlist, rname1), rname2);
}
//END OF STATIC FUNCTIONS AREA
Terminal * inicializeTerminals() {
    //That function avoids errors.
    return NULL;
}

Terminal * findTerminal(Terminal * tlist, char * name) {
    /*
    That function returns the terminal which has the name informed at
    input string. If it can't find the terminal it will return NULL.
    */
    while(tlist != NULL && strcmp(tlist->name, name)) {
        tlist = tlist->Next;
        //It will go to the next terminal until it finds the wanted router.
    }
    return tlist;
}

Terminal * findTerminalbyRouter(Terminal * t, char * rn) {
    /*
    It will look for a terminal that is connected to a router that has a
    specific name (char * rn).
    */
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
    //Verification started.
    /*
    First it will look for a terminal that has the name that the user wants
    to register.
    */
    Terminal * aux = findTerminal(t, n);
    //If the said router exists, it won't create a new one.
    if(aux != NULL) {
        if(veriFile) fprintf(lf, "Erro: %s nao pode ser registrado, existe um terminal com o mesmo nome.\n", n);
        return t;
    }
    //Verification done.

    //If there isn't any terminal with the same name:
    Terminal * newTerminal = (Terminal*)malloc(sizeof(Terminal));
    newTerminal->name = adjustString(n);
    newTerminal->place = adjustString(l);
    newTerminal->r = NULL;
    //Now it is going to check the list status.
    if(!t)
        //If terminal list is empty:
        newTerminal->Next = NULL;
    else
        //If terminal list has elements:
        newTerminal->Next = t;
    return newTerminal;
    //It returns the updated list.
}

Terminal * removeTerminal(Terminal * tlist, char * tname, FILE * l, int veriFile) {
    Terminal * wanted = findTerminal(tlist, tname);
    //First it looks for the terminal that is going to be deleted.
    Terminal * before = findPreviousTerminal(tlist, wanted);
    //Then, the one before it.

    //This will change the list "flux":
    if(wasntFound(wanted)) {
        if(veriFile) fprintf(l, "Erro: %s nao pode ser removido, nao existe um terminal com esse nome.\n", tname);
        return NULL;
    } else if (before == NULL) {
        //First item
        tlist = wanted->Next;
    } else if(wanted->Next == NULL){
        //Last item
        before->Next == NULL;
    } else {
        //Middle item
        before->Next = wanted->Next;
    }

    wanted = freeTerminal(wanted);
    return tlist;
}

void terminalFrequency(Terminal * tlist, char * place, FILE * o) {
    /*
    Variable "i" countains the current count of the frequency that the place
    appears.
    */
    int i = 0;
    while(tlist != NULL) {
        if(!strcmp(tlist->place, place))
            i++;
        //It will increment everytime the place appears.
        tlist = tlist->Next;
    }
    fprintf(o, "FREQUENCIATERMINAL %s: %d\n", place, i);
}

void unlinkTerminal(Terminal * tlist, char * tname, FILE * l, int veriFile) {
    Terminal * t = findTerminal(tlist, tname);
    if(wasntFound(t)) {
        if(veriFile) fprintf(l, "Erro: %s nao pode ser desconectado, nao existe terminal com esse nome.\n", tname);
    }
    else
        t->r = NULL;
    //That function is simple, it just sets t->r to NULL.
}

Terminal * disconnectRouter(Terminal * tlist, char * rn) {
    Terminal * t = tlist;
    while(t != NULL) {
        //While there is connections to a certain router,
        t = findTerminalbyRouter(tlist, rn);
        if(t != NULL && !strcmp(routerName(t->r), rn)) unlinkTerminal(tlist, t->name, NULL, FALSE);
        /*
        it will remove the connection.
        Then it will repeat without the need of any increment.
        The function itself already changes what is needed for the loop to work.
        */
    }
    return t;
}

void linkRouterToTerminal(Router * rlist, char * rname, Terminal * tlist, char * tname, FILE * l, int veriFile) {
    Terminal * t = findTerminal(tlist, tname);
    if(t == NULL) {
      if(veriFile) fprintf(l, "Erro: %s nao pode ser conectado, nao existe terminal com esse nome.\n\n", tname);
    }
    Router * r = findRouter(rlist, rname);
    if(r == NULL) {
      if(veriFile) fprintf(l, "Erro: %s nao pode ser conectado, nao existe roteador com esse nome.\n\n", rname);
    }
    if(r != NULL && t != NULL) t->r = r;
    //That function is simple, it just sets t->r to r.
}

Terminal * decimateTerminals(Terminal * t) {
    Terminal * temp;
    //While the function hasn't reached the end of the list:
    while(t != NULL) {
        //It saves the next position at temp.
        temp = t->Next;
        //Then deletes the current one
        removeTerminal(t, t->name, NULL, FALSE);
        //And make it possible to do it all again, until it ends.
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
    //When there's no connection t->r is equal to NULL.
    if(t->r == NULL) return FALSE;
    else return TRUE;
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

    //Verifications:
    if(auxt1 == NULL) {
        if(veriLog) fprintf(log, "Erro: Terminal %s nao existe.\n", ton);
        //-1 is an error code.
        return -1;
    }
    if(auxt2 == NULL) {
        if(veriLog) fprintf(log, "Erro: Terminal %s nao existe.\n", tdn);
        return -1;
    }

    if(auxt1->r != NULL) {
        //If there's a router connected:
        //It will run a verification that returns TRUE or FALSE
        if(verifyTerminalsAccess(r, t, ton, tdn)) {
            fprintf(file, "ENVIARPACOTESDADOS %s %s: SIM\n", ton, tdn);
            unflagAllRouters(r);
            /*
            It is necessary to unflag the routers to proper working in the
            future.
            */
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
