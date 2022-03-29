#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "files.h"

int main(int argc, char **argv){
    char *read_text=read("mygraph");
    wierzcholek_tab graf= text_to_graph(read_text);
    puts("");
}