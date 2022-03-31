//
// Created by Grzegorz Jewusiak on 30/03/2022.
//

#include <string.h>
#include <ctype.h>
#include "utils.h"


/*
 * Sprawdza czy supp to liczba.
 * Zwraca  0 - nie, 1 - tak
 */
int is_number(char *supp){
    int i=0;
    for(;i<strlen(supp);i++)
        if(isdigit(supp[i])==0)
            return 0;
    return 1;
}


/*
 * Sprawdza czy supp to liczba zmiennoprzecinkowa.
 * Zwraca  0 - nie, 1 - tak
 */
int is_dec(char *supp){
    int i=0;
    for(;i<strlen(supp);i++)
        if(isdigit(supp[i])==0 || supp[i]=='.')
            return 0;
    return 1;
}