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

sciezka_tab find(wierzcholek_tab tablica);

#endif //JIMP2_GRAPH_PATH_SEARCH_H
