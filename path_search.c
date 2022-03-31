#include "path_search.h"


sciezka_t new_sciezka_t(int id) {
    return (sciezka_t) { .n=0, .ids=malloc(sizeof (int))};
}

void add_to_sciezka(sciezka_t *s, int id) {
    s->ids = realloc(s->ids, (++(s->n)) * sizeof *s->ids);
    s->ids[s->n - 1]=id;
}

sciezka_tab new_sciezka_tab(){
    sciezka_tab t= malloc(sizeof *t);
    t->n=0;
    t->sciezki= malloc(sizeof *t->sciezki);
    return t;
}

void add_s_to_tab(sciezka_t w, sciezka_tab tab){
    tab->sciezki= realloc(tab->sciezki, ++(tab->n) * sizeof *tab->sciezki);
    tab->sciezki[tab->n-1]=w;
}

sciezka_tab find(wierzcholek_tab tablica){
    return new_sciezka_tab();
}
