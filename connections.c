
//STRUCT AREA
struct connections {
    Router * rs;
    Connect * Next;
};
//END OF STRUCT AREA
void printRouterAndTerminal(Router * r, Terminal * t) {
    printRouters(r);
    printTerminals(t);
}
