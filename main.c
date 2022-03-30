#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "files.h"
#include "BFS.h"

int main(int argc, char **argv){
    wierzcholek_tab graf= read("mygraph");

    kolejka_t k=new_kolejka_t();
    q_push(&k,2);
    q_push(&k,3);
    q_push(&k,4);
    q_push(&k,6);

    while(!q_empty(&k))
        printf("%d\n",q_pop(&k));

    int isc=BFS(graf);

    printf("Czy spojny: %d\n", isc);

    puts("");
}