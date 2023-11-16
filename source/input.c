#include "proto.h"
#include <stdio.h>

int dateFormat(){
    char scelta;

    do{
        printf("Che tipo di formato vuoi utlizzare?\n");
        printf("[1] gg/mm/aaaa \n[2] mm/gg/aaaa \n[3] aaaa/mm/gg \n");
        scanf(" %c", &scelta);
        while (getchar() != '\n');

        if (scelta > '0' && scelta < '4'){
            return scelta - '0';
        }
        else {
            printf("Comando non valido.");
            printf("\n\n");
        }
    }while (scelta > '3' || scelta < '1');
}