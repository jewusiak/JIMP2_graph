
#ifndef JIMP2_GRAPH_PATH_SEARCH_H
#define JIMP2_GRAPH_PATH_SEARCH_H

#include "graph.h"

typedef struct {
    int *seq;
    int n;
    double length;
} sciezka_t;


sciezka_t new_sciezka_t(double len);

void add_to_sciezka(sciezka_t *s, int id);

sciezka_t find(wierzcholek_tab t, int from, int to);

void reverse(sciezka_t *s);

void print_sciezka(sciezka_t s);

#endif
