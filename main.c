#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


int main(int argc, char **argv){
    wierzcholek_tab wierzcholekTab=new_wierzcholek_tab();
    wierzcholek_t nw= new_wierzcholek_t(10);
    add_adj(&nw, 1);
    add_adj(&nw, 3);
    add_w_to_tab(nw, wierzcholekTab);
    printf("");
}