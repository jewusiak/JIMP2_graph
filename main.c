#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"
#include "BFS.h"
#include "utils.h"
#include "graph.h"
#include "path_search.h"

#define FILE_N src_argv_index==-1?"mygraph":argv[src_argv_index]

int main(int argc, char **argv) {

    int c, i, spojnosc = 0, dijks = 0, gen = 0, id_pocz = -1, id_konc = -1, rows = -1, cols = -1;
    char *err = "";
    double min_w = 0, max_w = 10;
    int src_argv_index = -1;

    puts(err);

    if (argc > 1)
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
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
                //wymuszenie spójności
                spojnosc = 1;


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
                if (rows <= 0 || cols <= 0) {
                    err = "Nieprawidlowo zdefiniowane wartosci rows i cols - niedodatnie.";
                    break;
                }
            } else {
                err = "Nieprawidlowo zdefiniowane wartosci rows i cols jako kolejne parametry po -g lub --gen";
                break;
            }
        } else if (strcmp(argv[i], "-w") == 0) {
            if (i + 2 >= argc) {
                err = "Nieprawidlowo zdefiniowane wartosci min i max jako kolejne parametry po -w";
                break;
            }

            if (is_dec(argv[i + 1]) && is_dec(argv[i + 2])) {
                gen = 1;
                min_w = atof(argv[++i]);
                max_w = atof(argv[++i]);
                if (rows <= 0 || cols <= 0) {
                    err = "Nieprawidlowo zdefiniowane wartosci wartosci min i max - niedodatnie.";
                    break;
                }
            } else {
                err = "Nieprawidlowo zdefiniowane wartosci min i max jako kolejne parametry po -w";
                break;
            }
        } else if (strcmp(argv[i], "--src") == 0) {
            if (i + 1 >= argc) {
                err = "Nieprawidlowo zdefiniowana sciezka jako kolejny parametry po --src";
                break;
            }
            src_argv_index = ++i;

        } else {
            err = "Nieznany argument.";
            break;
        }
    }

    if (strcmp(err, "") != 0) {
        fprintf(stderr, "graph: %s\n", err);
        return 8; //TODO: exit-code do sprawozdania
    }

    wierzcholek_tab graf;



    if ((spojnosc || dijks) && !gen ) {
        //praca na grafie wczytanym (wczytujemy src)
        graf = read_w(FILE_N);
    } else if (gen ) {
        //praca na grafie (generujemy graf, zapisujemy do src, pracujemy na nim)
        graf = gen_graph(rows, cols, min_w, max_w);
        write_w(graf, FILE_N);

    } else {
        fprintf(stderr, "graph: Nieprawidlowo zdefiniowany tryb pracy. Za malo argumentow.");
        return 8;
    }

    int czy_spojny = BFS(graf);

    if (spojnosc)
        printf("Test spojnosci: %s\n", czy_spojny ? "TAK" : "NIE");

    if (dijks && !czy_spojny) {
        fprintf(stderr, "graph: Do poprawnego dzialania algorytmu Dijkstry wymagana jest spojnosc grafu.\n");
        exit(1);
    }

    if (dijks)
        print_sciezka(find(graf, id_pocz, id_konc));




}