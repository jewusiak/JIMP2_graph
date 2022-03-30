#ifndef JIMP2_GRAPH_FILES_H
#define JIMP2_GRAPH_FILES_H

#include "graph.h"


wierzcholek_tab read(const char *filename);

int write(wierzcholek_tab tablica, const char *filename);

#endif //JIMP2_GRAPH_FILES_H
