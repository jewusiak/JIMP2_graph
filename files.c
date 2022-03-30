#include <stdio.h>
#include <string.h>
#include "files.h"


wierzcholek_tab read_w(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "graph: Blad przy otwieraniu pliku zrodlowego: %s!\n", filename);
        exit(5);
    }

    int rows = -1, cols = -1;
    int scres = fscanf(f, "%d %d", &rows, &cols);

    if (scres != 2 || rows <= 0 || cols <= 0) {
        fprintf(stderr, "graph: Nieprawidlowy format pliku - brak liczby kolumn i wierszy grafu.\n");
        exit(4);
    }

    fgetc(f);

    char line[1024];
    int line_no = 0;

    wierzcholek_tab graf_w = new_wierzcholek_tab_s(rows * cols);


    while ((fscanf(f, "%[^\n]", line)) != EOF) {
        fgetc(f);

        int id;
        double weight;
        int reslt;
        graf_w->tab[line_no] = new_wierzcholek_t(line_no);
        while ((reslt = fscanf(f, " %d : %lf ", &id, &weight)) != EOF) {
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

        line_no++;
    }



    fclose(f);
    return graf_w;

}