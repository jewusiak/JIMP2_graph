#include <stdio.h>
#include <string.h>
#include <time.h>
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

double gen_num(double l_num, double h_num) {
    double r_num;
    r_num = ((double) rand() * (h_num - l_num) / RAND_MAX) + l_num;
    return r_num;
}

int probability() {
    int r_num;
    r_num = rand() % 100;
    return r_num;
}


wierzcholek_tab gen_graph(int rows, int cols, double w_min, double w_max, int coherent) {

    srand(time(NULL));
    int r;
    int c;
    int id_w = 0;
    wierzcholek_tab tablica = new_wierzcholek_tab_s(rows * cols);
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            wierzcholek_t temp = new_wierzcholek_t(id_w);
            int val = coherent == 1 ? 2 : probability();


            if (r == 0 && c == 0 && val > 0) {
                add_adj(&temp, id_w + 1, gen_num(w_min, w_max));
                add_adj(&temp, id_w + c, gen_num(w_min, w_max));
            }
            if (r == 0 && c == cols - 1 && val > 0) {
                add_adj(&temp, id_w - 1, gen_num(w_min, w_max));
                add_adj(&temp, id_w + c, gen_num(w_min, w_max));
            }
            if (r == rows - 1 && c == 0 && val > 0) {
                add_adj(&temp, id_w - c, gen_num(w_min, w_max));
                add_adj(&temp, id_w + 1, gen_num(w_min, w_max));
            }
            if (r == rows - 1 && c == cols - 1 && val > 0) {
                add_adj(&temp, id_w - c, gen_num(w_min, w_max));
                add_adj(&temp, id_w - 1, gen_num(w_min, w_max));
            }
            if (r == 0 && c != 0 && c != cols - 1 && val > 0) {
                add_adj(&temp, id_w + c, gen_num(w_min, w_max));
                add_adj(&temp, id_w - 1, gen_num(w_min, w_max));
                add_adj(&temp, id_w + 1, gen_num(w_min, w_max));
            }
            if (r == rows - 1 && c != 0 && c != cols - 1 && val > 0) {
                add_adj(&temp, id_w - c, gen_num(w_min, w_max));
                add_adj(&temp, id_w - 1, gen_num(w_min, w_max));
                add_adj(&temp, id_w + 1, gen_num(w_min, w_max));
            }
            if (r != 0 && r != rows - 1 && c == 0 && val > 0) {
                add_adj(&temp, id_w + c, gen_num(w_min, w_max));
                add_adj(&temp, id_w - c, gen_num(w_min, w_max));
                add_adj(&temp, id_w + 1, gen_num(w_min, w_max));
            }
            if (r != 0 && r != rows - 1 && c == cols - 1 && val > 0) {
                add_adj(&temp, id_w + c, gen_num(w_min, w_max));
                add_adj(&temp, id_w - c, gen_num(w_min, w_max));
                add_adj(&temp, id_w - 1, gen_num(w_min, w_max));
            }
            if (r != 0 && r != rows - 1 && c != 0 && c != cols - 1 && val > 0) {
                add_adj(&temp, id_w + c, gen_num(w_min, w_max));
                add_adj(&temp, id_w - c, gen_num(w_min, w_max));
                add_adj(&temp, id_w + 1, gen_num(w_min, w_max));
                add_adj(&temp, id_w - 1, gen_num(w_min, w_max));
            }
            tablica->tab[id_w] = temp;
            id_w += 1;


        }

    }
    return tablica;
}

