#include <float.h>
#include <stdio.h>
#include "path_search.h"


sciezka_t new_sciezka_t(double len) {
    return (sciezka_t) {.length=len, .n=0, .seq=malloc(sizeof(int))};
}

void add_to_sciezka(sciezka_t *s, int id) {
    s->seq = realloc(s->seq, (++(s->n)) * sizeof *s->seq);
    s->seq[s->n - 1] = id;
}


int get_min_double_index(double *d, int n, int *sq) {
    int i;
    int ind = -1;
    for (i = 0; i < n; i++) {
        if (ind == -1 && sq[i] == 0)
            ind = i;
        else if (d[i] < d[ind] && sq[i] == 0)
            ind = i;
    }
    return ind;
}

void reverse(sciezka_t *s) {
    int i, temp;
    for (i = 0; i < s->n / 2; i++) {
        temp = s->seq[i];
        s->seq[i] = s->seq[s->n - i - 1];
        s->seq[s->n - i - 1] = temp;
    }
}

void print_sciezka(sciezka_t s) {
    int i;
    printf("Dlugosc: %g\n", s.length);
    for (i = 0; i < s.n - 1; i++)
        printf("%d >> ", s.seq[i]);
    printf("%d", s.seq[i]);
}

sciezka_t find(wierzcholek_tab t, int from, int to) {
    if(from<0 || to>=t->n){
        fprintf(stderr, "graph: Nieprawidlowo zdefiniowane parametry po -p lub --path.\n0 >= x < l. wierzcholkow\n");
        exit(3);
    }
    int *sq = calloc(t->n, sizeof *sq);
    int nq = t->n;
    // 0 - NIE należy do S, NALEŻY do Q
    // 1 - NALEŻY do S, NIE należy do Q
    int *p = malloc(t->n * sizeof *p);
    double *d = malloc(t->n * sizeof *d);
    int i;
    for (i = 0; i < t->n; i++) {
        p[i] = -1;
        d[i] = DBL_MAX;
    }
    d[from] = 0;
    while (nq != 0) {
        nq--;
        int u = get_min_double_index(d, t->n, sq);
        sq[u] = 1;
        for (i = 0; i < t->tab[u].n; i++) {
            int w = t->tab[u].adj[i];
            if (sq[w] == 1)
                continue;
            double w_w = t->tab[u].adj_weights[i];
            if (d[w] > d[u] + w_w) {
                d[w] = d[u] + w_w;
                p[w] = u;
            }


        }


    }

    sciezka_t out = new_sciezka_t(d[to]);
    int last = to;
    while (last != -1) {
        add_to_sciezka(&out, last);
        last = p[last];
    }

    reverse(&out);

    return out;

}

