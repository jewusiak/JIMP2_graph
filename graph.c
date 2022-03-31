#include <stdio.h>
#include <string.h>
#include "graph.h"


wierzcholek_t new_wierzcholek_t(int id) {
    return (wierzcholek_t) {.id=id, .n=0, .adj=malloc(sizeof(int)), .adj_weights=malloc(sizeof(double))};
}

void add_adj(wierzcholek_t *w, int id, double weight) {
    (w->n)++;
    w->adj = realloc(w->adj, w->n * sizeof *w->adj);
    w->adj_weights = realloc(w->adj_weights, w->n * sizeof *w->adj_weights);
    w->adj[w->n - 1] = id;
    w->adj_weights[w->n - 1] = weight;

}

wierzcholek_tab new_wierzcholek_tab() {
    wierzcholek_tab t = malloc(sizeof *t);
    t->n = 0;
    t->tab = malloc(sizeof *t->tab);
    return t;
}

//tworzy instancje wierzchołków w tablicy
wierzcholek_tab new_wierzcholek_tab_s(int size) {
    wierzcholek_tab t = malloc(sizeof *t);
    t->n = size;
    t->tab = malloc(t->n * sizeof *t->tab);
    int i = 0;
    for (; i < size; i++)
        t->tab[i] = new_wierzcholek_t(i);
    return t;
}

void add_w_to_tab(wierzcholek_t w, wierzcholek_tab tab) {
    tab->tab = realloc(tab->tab, ++(tab->n) * sizeof *tab->tab);
    tab->tab[tab->n - 1] = w;
}

wierzcholek_tab gen_graph(int rows, int cols, double w_min, double w_max){
    return new_wierzcholek_tab();
}
