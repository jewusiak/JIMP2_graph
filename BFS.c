//
// Created by Grzegorz Jewusiak on 29/03/2022.
//

#include "BFS.h"
#include <stdio.h>

kolejka_t new_kolejka_t() {
    return (kolejka_t) {.n=0, .q=malloc(sizeof(int))};
}

void q_push(kolejka_t *k, int item) {
    k->q = realloc(k->q, ++k->n * sizeof *k->q);
    k->q[k->n - 1] = item;
}

int q_pop(kolejka_t *k) {
    int val = k->q[0];
    int i;
    for (i = 1; i < k->n; i++)
        k->q[i - 1] = k->q[i];
    k->q = realloc(k->q, --k->n * sizeof *k->q);
    return val;
}

int q_empty(kolejka_t *k) {
    return k->n > 0 ? 0 : 1;
}

int BFS(wierzcholek_tab tab) {
    kolejka_t q = new_kolejka_t();
    int *visited = calloc(tab->n, sizeof *visited);
    visited[0] = 1;
    q_push(&q,0);
    while (!q_empty(&q)) {
        int v = q_pop(&q);
        int i = 0;
        for (; i < tab->tab[v].n; i++) {
            if(visited[tab->tab[v].adj[i]]==1)
                continue;
            q_push(&q,tab->tab[v].adj[i]);
            visited[tab->tab[v].adj[i]]=1;
        }

    }

    int is_coherent=1;
    int i;
    for(i=0;i<tab->n;i++)
        if(visited[i]==0) {
            is_coherent = 0;
            printf("Nieodwiedzony: %d\n", i);
        }

    return is_coherent;

}