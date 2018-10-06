#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "router.h"
#include "connection.h"
#define FALSE 0
#define TRUE 1

//STRUCT AREA
struct router {
    char * name;
    //String with the router name.
    char * carrier;
    //String with carrier name.
    Connect * cnt;
    //Pointer that contains the connected router.
    Router * Next;
    //Pointer that contains the next router of the list.
    int flag;
    //Flag for specific uses.
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

static Router * findPreviousRouter(Router * r, Router * rw) {
    /*
    This function searches for the previous router in relation to the
    informed router.
    */
    while(r != NULL && r->Next != rw) {
        r = r->Next;
    }
    /*
    If it doesn't find any router it will return NULL.
    It only happens when the list is empty or you are looking for the first
    element in the list.
    */
    return r;
}

static int isFirst(Router * r, Router * rw) {
    //This function verifies if the router is the first of the list.
    Router * temp = findPreviousRouter(r, rw);
    if(temp == NULL && rw->Next != NULL) return 1;
    else return 0;
}

static int isMiddle(Router * r, Router * rw) {
    //This function verifies if the router is at the middle of the list.
    Router * temp = findPreviousRouter(r, rw);
    if(temp != NULL && rw->Next != NULL) return 1;
    else return 0;
}

static int isLast(Router * r, Router * rw) {
    //This function verifies if the router is the last of the list.
    Router * temp = findPreviousRouter(r, rw);
    if(temp != NULL && rw->Next == NULL) return 1;
    else return 0;
}
//END OF STATIC FUNCTIONS AREA

Router * inicializeRouters() {
    //That function avoids errors.
    return NULL;
}

Router * findRouter(Router * rlist, char * name) {
    /*
    That function returns the router which has the name informed at
    input string. If it can't find the router it will return NULL.
    */
    while(rlist != NULL && strcmp(rlist->name, name)){
        rlist = rlist->Next;
        //It will go to the next router until it finds the wanted one.
    }
    return rlist;
}

Router * registerRouter(Router * r, char * n, char * o, FILE * l) {
    //Verification:
    Router * aux = findRouter(r, n);
    if(aux != NULL) {
        fprintf(l, "Erro: %s nao pode ser registrado, ha um roteador com o mesmo nome.\n", n);
        return r;
    }
    //Verification finished.

    //If everything is alright:
    Router * newRouter = (Router *)malloc(sizeof(Router));
    newRouter->name = adjustString(n);
    newRouter->carrier = adjustString(o);
    newRouter->cnt = NULL;
    newRouter->flag = FALSE;

    if(r == NULL) {
        //If router list is empty
        newRouter->Next = NULL;
    } else {
        //If router list has elements
        newRouter->Next = r;
    }

    return newRouter;
    //It returns the updated routers list;
}

Router * removeRouter(Router * rlist, char * rn, FILE * l, int veriFile) {
    //Verification:
    Router * temp = findRouter(rlist, rn);
    Router * temp2;
    if(temp == NULL) {
        if(veriFile) fprintf(l, "Erro: Roteador %s inexistente no NetMap.\n", rn);
        return rlist;
    }

    while(thereIsRRConnection(temp)) {
        //Deletes all the connections of the router.
        rlist = webDisconnectRouters(rlist, rn, cntRouterName(temp->cnt), NULL, FALSE);
    }

    //Redirects the lists "flux".
    if(isLast(rlist, temp)) {
        temp2 = findPreviousRouter(rlist, temp);
        if(temp2 != NULL) temp2->Next = NULL;
    }
    else if(isMiddle(rlist, temp)) {
        temp2 = findPreviousRouter(rlist, temp);
        if(temp2 != NULL) temp2->Next = temp->Next;
    }
    else if(isFirst(rlist, temp)) {
        rlist = temp->Next;
    }

    //Frees everyting inside the router.
    free(temp->name);
    free(temp->carrier);
    free(temp);

    //Return the updated list.
    return rlist;
}

void carrierFrequency(Router * rlist, char * carrier, FILE * o) {
    /*
    Variable "i" contains the current count of the frequency that the carrier
    appears.
    */
    int i = 0;
    while(rlist != NULL){
        if(!strcmp(rlist->carrier,carrier))
            i++;
            //Everytime the carriers appears it will increment.
        rlist = rlist->Next;
    }
    fprintf(o, "FREQUENCIAOPERADORA %s: %d\n", carrier, i);
}

char * routerName(Router * r) {
    if(r != NULL) return r->name;
    else return NULL;
}

Router * decimateRouters(Router * r) {
    Router * temp;

    //It will go to the next router until it finds the wanted one.
    while(r != NULL) {
        //It saves the next position at temp.
        temp = r->Next;
        //Then deletes the current one.
        removeRouter(r, r->name, NULL, FALSE);
        //And make it possible to do it all again, until it ends.
        r = temp;
    }

    return NULL;
}

Router * webConnectRouters(Router * rlist, char * rn1, char * rn2, FILE * l, int veriFile) {
    //Verifications:
    Router * r1 = findRouter(rlist, rn1);
    Router * r2 = findRouter(rlist, rn2);
    if(r1 == NULL || r2 == NULL) {
        if(veriFile) {
            if(r1 == NULL) {
                fprintf(l, "Erro: %s nao pode ser conectado, nao ha um roteador com esse nome.\n", rn1);
            }
            if(r2 == NULL) {
                fprintf(l, "Erro: %s nao pode ser conectado, nao ha um roteador com esse nome.\n", rn2);
            }
        }
        return rlist;
    }

    //Connects both routers to each other.
    r1->cnt = addConnection(r1->cnt, rlist, rn2);
    r2->cnt = addConnection(r2->cnt, rlist, rn1);

    return rlist;
    //Returns updated list.
}

Router * webDisconnectRouters(Router * rlist, char * rn1, char * rn2, FILE * l, int veriFile) {
    //Verifications:
    Router * temp1 = findRouter(rlist, rn1);
    Router * temp2 = findRouter(rlist, rn2);
    if(temp1 == NULL || temp2 == NULL) {
        if(temp1 == NULL) {
            if(veriFile) fprintf(l, "Erro: %s nao pode ser desconectado, nao ha roteador com esse nome.\n", rn1);
        }
        if(temp2 == NULL) {
            if(veriFile) fprintf(l, "Erro: %s nao pode ser desconectado, nao ha roteador com esse nome.\n", rn2);
        }
        return rlist;
    }

    //Disconnects both routers.
    temp1->cnt = removeConnection(temp1->cnt, rn2);
    temp2->cnt = removeConnection(temp2->cnt, rn1);

    return rlist;
    //Returns updated list.
}

int thereIsRRConnection(Router * r) {
    if(r->cnt != NULL) return TRUE;
    else return FALSE;
}

Connect * getCNT(Router * r) {
    return r->cnt;
}

Router * nextRouter(Router * r) {
    return r->Next;
}

int routersGraphSearch(Router * rlist, Router * ro, char * rname2) {
    /*
    --STEPS--
    1-VERIFY ROUTER CONNECTIONS.
    2-ENTER ALL CONNECTIONS.
    3-CHECK IF THE OTHER ROUTER IS CONNECTED.
    4-DO IT AGAIN UNTIL IT WORKS! (Recursive)
    --VARIABLES--
    rlist:  List of routers.
    rname1: Router 1 name.
    rname2: Router 2 name.
    */
    //Verification:
    int verification;
    //"ro" stands for "router of origin".
    if(ro == NULL) return FALSE;

    //Flag router to avoid problems.
    flagRouter(rlist, routerName(ro));
    Connect * cnt = ro->cnt;
    while(cnt != NULL) {
        if(!strcmp(cntRouterName(cnt), rname2)) {
            //If it finds the connection it will return TRUE.
            return TRUE;
        }
        //Else, it will keep searching
        Router * ro2 = findRouter(rlist, cntRouterName(cnt));
        if(!isFlagged(rlist, routerName(ro2)))
            //It only verifies unflagged routers.
            verification = routersGraphSearch(rlist, ro2, rname2);
        if(verification) return TRUE;
        //If the verification returns FALSE it will search in the next router.
        else cnt = nextCNT(cnt);
    }

    return FALSE;
    /*
    If it reached the end of the list and hasn't found anything it will return
    NULL.
    */
}

void unflagRouter(Router * r, char * rn) {
    //Very simple function.
    Router * r1 = findRouter(r, rn);
    if(r1 != NULL) {
        r1->flag = 0;
    }
    return;
}

void flagRouter(Router * r, char * rn) {
    //Very simple function.
    Router * r1 = findRouter(r, rn);
    if(r1 != NULL) {
        r1->flag = TRUE;
    }
    return;
}

void unflagAllRouters(Router * r) {
    //Very simple function.
    Router * r1 = r;
    while(r1 != NULL) {
        r1->flag = FALSE;
        r1 = r1->Next;
    }
    return;
}

int isFlagged(Router * r, char * rn) {
    //Very simple function.
    Router * r1 = findRouter(r, rn);
    if(r1 == NULL) return -1;
    else return r1->flag;
}
