#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "graph.h"
#include "files.h"
#include "BFS.h"
#include "utils.h"

int main(int argc, char **argv) {

    int c, i, spojnosc = 0, dijks = 0, gen = 0, id_pocz = -1, id_konc = -1, rows = -1, cols = -1;
    char *err = "";
    int filename_argv_index = -1;
    const char *def_filename = "mygraph";

    puts(err);

    if(argc>1)
        if(strcmp(argv[1], "-h")==0||strcmp(argv[1], "--help")==0) {
            //TODO: implementacja helpa

            printf("Zaimplementować helpa\n");
            return 0;
        }

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--spoj") == 0)
            spojnosc = 1;

        else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--path") == 0) {
            //szukamy id_pocz, id_konc
            if (i + 2 >= argc) {
                err = "Nieprawidlowo zdefiniowane wartosci id_pocz i id_konc jako kolejne parametry po -p lub --path";
                break;
            }

            if (is_number(argv[i + 1]) && is_number(argv[i + 2])) {
                dijks = 1;
                id_pocz = atoi(argv[++i]);
                id_konc = atoi(argv[++i]);

            } else {
                err = "Nieprawidlowo zdefiniowane wartosci id_pocz i id_konc jako kolejne parametry po -p lub --path";
                break;
            }
        } else if (strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "--gen") == 0) {
            if (i + 2 >= argc) {
                err = "Nieprawidlowo zdefiniowane wartosci rows i cols jako kolejne parametry po -g lub --gen";
                break;
            }

            if (is_number(argv[i + 1]) && is_number(argv[i + 2])) {
                gen = 1;
                rows = atoi(argv[++i]);
                cols = atoi(argv[++i]);

            } else {
                err = "Nieprawidlowo zdefiniowane wartosci rows i cols jako kolejne parametry po -g lub --gen";
                break;
            }
        } else if (strcmp(argv[i], "--src") == 0) {
            if (i + 1 >= argc) {
                err = "Nieprawidlowo zdefiniowana sciezka jako kolejny parametry po --src";
                break;
            }
            filename_argv_index = ++i;

        } else {
            err="Nieznany argument.";
            break;
        }
    }

    if (strcmp(err, "") != 0) {
        fprintf(stderr, "graph: %s\n", err);
        return 8; //TODO: exit-code do sprawozdania
    }




    printf("czy gen: %d (%d, %d)\nczy spoj: %d\nczy dijkstr: %d (%d -> %d)\nsrc: %s", gen, rows, cols, spojnosc, dijks,
           id_pocz, id_konc, filename_argv_index == -1 ? def_filename : argv[filename_argv_index]);

    wierzcholek_tab graf = read_w("mygraph");

    kolejka_t k = new_kolejka_t();
    q_push(&k, 2);
    q_push(&k, 3);
    q_push(&k, 4);
    q_push(&k, 6);

    while (!q_empty(&k))
        printf("%d\n", q_pop(&k));

    int isc = BFS(graf);

    printf("Czy spojny: %d\n", isc);

    puts("");
}