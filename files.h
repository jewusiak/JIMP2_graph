#ifndef JIMP2_GRAPH_FILES_H
#define JIMP2_GRAPH_FILES_H

#include "graph.h"
#include "path_search.h"


wierzcholek_tab read_w(const char *filename);

void write_w(wierzcholek_tab tablica, int, int, const char *filename);


#endif
