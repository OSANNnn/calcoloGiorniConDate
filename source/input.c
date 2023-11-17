#include "proto.h"
#include <stdio.h>
#include <string.h>

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

void dateGetValidate(char input[], int dimensione, int formato){
    char appoggio[dimensione];
    char stringaFormato[4][11];
    int posizione;
    int contaChar;
    int valida;

    strcpy(stringaFormato[1], "gg/mm/aaaa");
    strcpy(stringaFormato[2], "mm/gg/aaaa");
    strcpy(stringaFormato[3], "aaaa/mm/gg");

    do{
        printf("Inserisci la data %s: ", stringaFormato[formato]);
        scanf("%s", &appoggio);
        while(getchar() != '\n');
        valida    = 1;
        contaChar = 0;

        if (formato == 1){ //gg/mm/aaaa
            for (int i = 0; i < 10 && valida; i++){

                if ((appoggio[i] != '/' && (appoggio[i] >= '0' && appoggio[i] <= '9')) && contaChar <= 1 && i < 2){
                    input[i + 6] = appoggio[i];
                    contaChar++;
                }        
                else if ((appoggio[i] != '/' && (appoggio[i] >= '0' && appoggio[i] <= '9')) && (contaChar >= 1 && contaChar <= 3) && i > 2){
                    input[i + 1] = appoggio[i];
                    contaChar++;
                }               
                else if ((appoggio[i] != '/' && (appoggio[i] >= '0' && appoggio[i] <= '9')) && (contaChar >= 3 && contaChar <=7)  && i > 5){
                    input[i - 6] = appoggio[i];
                    contaChar++;
                }
                else if (appoggio[i] != '/') {
                    printf("Formato non valido.\n");
                    valida = 0;
                }
            }
            input[8] = '\0';
            printf("%s \n",input);
        }/*
        else if (formato == 2){
            posizione = 0;

            for (int i = 0; i < 10 && valida; i++){

                if ((appoggio[i] != '/' && (appoggio[i] >= '0' && appoggio[i] <= '9')) && contaChar <= 1 && i < 2){
                    input[posizione + 6] = appoggio[i];
                    posizione++;
                    contaChar++;
                }        
                else if ((appoggio[i] != '/' && (appoggio[i] >= '0' && appoggio[i] <= '9')) && (contaChar >= 1 && contaChar <= 3) && i > 2){
                    input[posizione + 2] = appoggio[i];
                    posizione++;
                    contaChar++;
                }               
                else if ((appoggio[i] != '/' && (appoggio[i] >= '0' && appoggio[i] <= '9')) && (contaChar >= 3 && contaChar <=7)  && i > 5){
                    input[posizione - 4] = appoggio[i];
                    posizione++;
                    contaChar++;
                }
                else if (appoggio[i] != '/') {
                    printf("Formato non valido.\n");
                    valida = 0;
                }
            }
            input[8] = '\0';
            printf("%s \n",input);
        }*/
    }while (!valida);
}
