#ifndef JIMP2_GRAPH_GRAPH_H
#define JIMP2_GRAPH_GRAPH_H

#include <stdlib.h>

typedef struct {
    int id;
    int *adj; //sąsiedzi
    double *adj_weights; //wagi między this a sąsiadem
    int n;
} wierzcholek_t;

typedef struct {
    wierzcholek_t *tab;
    int n;
} *wierzcholek_tab;

// obsługa struktur
wierzcholek_t new_wierzcholek_t(int id);

void add_adj(wierzcholek_t *w, int id, double weight) ;

wierzcholek_tab new_wierzcholek_tab_s(int size);
wierzcholek_tab new_wierzcholek_tab();

void add_w_to_tab(wierzcholek_t w, wierzcholek_tab tab);



//obsługa grafu
wierzcholek_tab gen_graph(int rows, int cols, double w_min, double w_max);

wierzcholek_tab text_to_graph(char *text);

#endif //JIMP2_GRAPH_GRAPH_H
