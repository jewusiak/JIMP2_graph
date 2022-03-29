#include <stdio.h>
#include <string.h>
#include "files.h"


char *read(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "graph: Blad przy otwieraniu pliku zrodlowego: %s!\n", filename);
        exit(5);
    }
    char buffer[1024];
    char *text= malloc(sizeof *text);
    char *tmp;
    int rc;
    while ((rc=fread(buffer, 1, sizeof(buffer), f) )> 0) {
        tmp= realloc(text, strlen(text)+rc+1);
        if (tmp==NULL){
            fprintf(stderr, "graph: Blad przy czytaniu - alokowanie pamieci.\n");
            exit(7);
        }
        text=tmp;
        strncat(text, buffer, rc);
    }

    fclose(f);
    return text;

}