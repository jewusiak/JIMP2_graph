//
// Created by Grzegorz Jewusiak on 29/03/2022.
//

#include "graph.h"
wierzcholek_t new_wierzcholek_t(int id) {
    return (wierzcholek_t) {.id=id, .n=0, .adj=malloc(sizeof(int))};
}

void add_adj(wierzcholek_t *w, int id) {
    w->adj = realloc(w->adj, (++(w->n)) * sizeof *w->adj);
    w->adj[w->n-1]=id;
}

wierzcholek_tab new_wierzcholek_tab(){
    wierzcholek_tab t= malloc(sizeof *t);
    t->n=0;
    t->tab= malloc(sizeof *t->tab);
    return t;
}

void add_w_to_tab(wierzcholek_t w, wierzcholek_tab tab){
    tab->tab= realloc(tab->tab, ++(tab->n) * sizeof *tab->tab);
    tab->tab[tab->n-1]=w;
}