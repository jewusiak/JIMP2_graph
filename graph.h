#ifndef JIMP2_GRAPH_GRAPH_H
#define JIMP2_GRAPH_GRAPH_H

#include <stdlib.h>

typedef struct {
    int id;
    int *adj;
    double *adj_weights;
    int n;
} wierzcholek_t;

typedef struct {
    wierzcholek_t *tab;
    int n;
} *wierzcholek_tab;

wierzcholek_t new_wierzcholek_t(int id);

void add_adj(wierzcholek_t *w, int id, double weight);

wierzcholek_tab new_wierzcholek_tab_s(int size);

wierzcholek_tab new_wierzcholek_tab();

void add_w_to_tab(wierzcholek_t w, wierzcholek_tab tab);


wierzcholek_tab gen_graph(int rows, int cols, double w_min, double w_max, int coherent);

double gen_num(double l_num, double h_num);


#endif
