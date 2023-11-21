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
    int contaChar;
    int valida;

    strcpy(stringaFormato[1], "gg/mm/aaaa");
    strcpy(stringaFormato[2], "mm/gg/aaaa");
    strcpy(stringaFormato[3], "aaaa/mm/gg");

    do{
        printf("Inserisci la data %s: ", stringaFormato[formato]);
        scanf("%s", input);
        scanf("%s", input);
        while(getchar() != '\n');
        valida    = 1;
        contaChar = 0; //conta i caratteri diversi da '/'           |a|b|/|c|d|/|e|f|g|h|
                                                        //          |0|1|2|3|4|5|6|7|8|9|
        if (formato == 1){ //gg/mm/aaaa                             |e|f|g|h|c|d|a|b|-|-|
            for (int i = 0; i < dimensione-1 && valida; i++){
                if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && contaChar < 2 && i < 2){
                    appoggio[i + 6] = input[i];
                    contaChar++;
                }        
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 2 && contaChar <= 3) && i >= 2){
                    appoggio[i + 1] = input[i];
                    contaChar++;
                }               
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 3 && contaChar <=7)  && i >= 5){
                    appoggio[i - 6] = input[i];
                    contaChar++;
                }
                else if (input[i] != '/') {
                    printf("Formato non valido.\n");
                    valida = 0;
                }
            }
            appoggio[8] = '\0';
            printf("%s \n", appoggio); //debug
        }
        else if (formato == 2){ //mm/gg/aaaa
            for (int i = 0; i < dimensione-1 && valida; i++){
                if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && contaChar < 2 && i < 2){
                    appoggio[i + 4] = input[i];
                    contaChar++;
                }        
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 2 && contaChar <= 3) && i >= 2){
                    appoggio[i + 3] = input[i];
                    contaChar++;
                }               
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 3 && contaChar <=7)  && i >= 5){
                    appoggio[i - 6] = input[i];
                    contaChar++;
                }
                else if (input[i] != '/') {
                else if (input[i] != '/') {
                    printf("Formato non valido.\n");
                    valida = 0;
                }
            }
            appoggio[8] = '\0';
            printf("%s \n", appoggio); //debug
        }
        else if (formato == 3){ //aaaa/mm/gg
            for (int i = 0; i < dimensione-1 && valida; i++){
                if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && contaChar < 4 && i < 4){
                    appoggio[i] = input[i];
                    contaChar++;
                }        
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 3 && contaChar <= 5) && i > 4){
                    appoggio[i - 1] = input[i];
                    contaChar++;
                }               
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 6 && contaChar <=7)  && i > 7){
                    appoggio[i - 2] = input[i];
                    contaChar++;
                }
                else if (input[i] != '/') {
                else if (input[i] != '/') {
                    printf("Formato non valido.\n");
                    valida = 0;
                }
            }
            appoggio[8] = '\0';
            printf("%s \n", appoggio); //debug
        }
            appoggio[8] = '\0';
            printf("%s \n", appoggio); //debug
        }
    }while (!valida);
}
