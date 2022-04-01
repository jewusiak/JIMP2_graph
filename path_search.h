//To jest moduł algorytmu Dijkstry
#ifndef JIMP2_GRAPH_PATH_SEARCH_H
#define JIMP2_GRAPH_PATH_SEARCH_H

#include "graph.h"

typedef struct{
    int *ids;
    int n;
} sciezka_t;

typedef struct{
    sciezka_t *sciezki;
    int n;
} * sciezka_tab;

//obsługa struktur
sciezka_t new_sciezka_t(int id);

void add_to_sciezka(sciezka_t *s, int id) ;

sciezka_tab new_sciezka_tab();

void add_s_to_tab(sciezka_t w, sciezka_tab tab);

sciezka_tab find(wierzcholek_tab tablica);

#endif //JIMP2_GRAPH_PATH_SEARCH_H
