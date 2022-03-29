#ifndef JIMP2_GRAPH_BFS_H
#define JIMP2_GRAPH_BFS_H

#include "graph.h"

//kolejka:
typedef struct {
    int *q;
    int n;
} kolejka_t;

void q_push(kolejka_t *k, int item);
int q_pop(kolejka_t *k);
kolejka_t new_kolejka_t();
int q_empty(kolejka_t *k);

/*
 * Sprawdza spójność grafu.
 * 1 - spójny, 0 - niespójny
 */
int BFS(wierzcholek_tab tab);


#endif //JIMP2_GRAPH_BFS_H
