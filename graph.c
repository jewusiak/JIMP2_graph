//
// Created by Grzegorz Jewusiak on 29/03/2022.
//

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
    w->adj[w->n-1]=id;
    w->adj_weights[w->n-1]=weight;

}

wierzcholek_tab new_wierzcholek_tab(){
    wierzcholek_tab t= malloc(sizeof *t);
    t->n=0;
    t->tab= malloc(sizeof *t->tab);
    return t;
}

//tworzy instancje wierzchołków w tablicy
wierzcholek_tab new_wierzcholek_tab_s(int size){
    wierzcholek_tab t= malloc(sizeof *t);
    t->n=size;
    t->tab = malloc(t->n * sizeof *t->tab);
    int i=0;
    for(;i<size;i++)
        t->tab[i]= new_wierzcholek_t(i);
    return t;
}

void add_w_to_tab(wierzcholek_t w, wierzcholek_tab tab){
    tab->tab= realloc(tab->tab, ++(tab->n) * sizeof *tab->tab);
    tab->tab[tab->n-1]=w;
}


wierzcholek_tab text_to_graph(char *text) {
    FILE *f= fmemopen(text, strlen(text), "r");

    if(f==NULL){
        fprintf(stderr, "graph: Nie udalo sie otworzyc strumienia tekstowego (moze plik jest pusty?).\n");
        exit(7);
    }

    int rows = -1, cols = -1;
    int scres = fscanf(f, "%d %d", &rows, &cols);

    if (scres != 2 || rows <= 0 || cols <= 0) {
        fprintf(stderr, "graph: Nieprawidlowy format pliku - brak liczby kolumn i wierszy grafu.\n");
        exit(4);
    }

    fgetc(f);


    wierzcholek_tab graf_w = new_wierzcholek_tab_s(rows * cols);

    char line[1024];
    int line_no = 0;

    while ((fscanf(f, "%[^\n]", line)) != EOF) {
        fgetc(f);

        FILE *line_stream= fmemopen(line, strlen(line), "r");

        int id;
        double weight;
        int reslt;
        graf_w->tab[line_no] = new_wierzcholek_t(line_no);
        while ((reslt = fscanf(line_stream, " %d : %lf ", &id, &weight)) != EOF) {
            if (reslt != 2) {
                fprintf(stderr, "graph: Nieprawidlowy format pliku.\n");
                exit(4);
            }

            if (id < 0 || id >= rows * cols) {
                fprintf(stderr, "graph: Ujemne id lub poza zakresem.\n");
                exit(3);
            }

            if (weight < 0) {
                fprintf(stderr, "graph: Ujemna waga.\n");
                exit(3);
            }


            add_adj(&(graf_w->tab[line_no]), id, weight);


        }
        fclose(line_stream);

        line_no++;
    }

    fclose(f);

    return graf_w;

}
