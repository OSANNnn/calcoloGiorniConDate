#include "proto.h"
#include <stdio.h>
#include <string.h> //init stringe formato
#include <stdlib.h> //funzione abs
#include <math.h>   //funzione pow

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

void dateGetValidate(char input[], int output[], int dimensione, int formato){
    char appoggio[dimensione]; //array di appoggio per la standardizzazione della data (lo standard per l'utilizzo nelle altre funzioni) aaaammgg
    char stringaFormato[4][11];
    int  contaChar;
    int  valida;

    strcpy(stringaFormato[1], "gg/mm/aaaa");
    strcpy(stringaFormato[2], "mm/gg/aaaa");
    strcpy(stringaFormato[3], "aaaa/mm/gg");

    do{
        printf("Inserisci la data %s: ", stringaFormato[formato]);
        scanf("%s", input);
        while(getchar() != '\n');
        valida    = 1;
        contaChar = 0; //conta i caratteri diversi da '/'              
        
        //Standardizzo la data in un formato specifico aaaammgg           |a|b|/|c|d|/|e|f|g|h|
        if (formato == 1){ //gg/mm/aaaa                                   |0|1|2|3|4|5|6|7|8|9|        
            for (int i = 0; i < dimensione-1 && valida; i++){//           |e|f|g|h|c|d|a|b|-|-| schema di come devono arrivare i valori sull'array di appoggio
                if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && contaChar < 2 && i < 2){
                    appoggio[i + 6] = input[i];
                    contaChar++;
                }        
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 2 && contaChar < 4) && i > 2){
                    appoggio[i + 1] = input[i];
                    contaChar++;
                }               
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 4 && contaChar < 8)  && i > 5){
                    appoggio[i - 6] = input[i];
                    contaChar++;
                }
                else if (input[i] != '/') {
                    printf("Formato non valido.\n");
                    valida = 0;
                }
            }
            appoggio[8] = '\0';
        }
        else if (formato == 2){ //mm/gg/aaaa
            for (int i = 0; i < dimensione-1 && valida; i++){
                if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && contaChar < 2 && i < 2){
                    appoggio[i + 4] = input[i];
                    contaChar++;
                }        
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 2 && contaChar < 4) && i > 2){
                    appoggio[i + 3] = input[i];
                    contaChar++;
                }               
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 4 && contaChar <=7)  && i > 5){
                    appoggio[i - 6] = input[i];
                    contaChar++;
                }
                else if (input[i] != '/') {
                    printf("Formato non valido.\n");
                    valida = 0;
                }
            }
            appoggio[8] = '\0';
        }
        else if (formato == 3){ //aaaa/mm/gg
            for (int i = 0; i < dimensione-1 && valida; i++){
                if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && contaChar < 4 && i < 4){
                    appoggio[i] = input[i];
                    contaChar++;
                }        
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 4 && contaChar < 6) && i > 4){
                    appoggio[i - 1] = input[i];
                    contaChar++;
                }               
                else if ((input[i] != '/' && (input[i] >= '0' && input[i] <= '9')) && (contaChar >= 6 && contaChar <=7)  && i > 7){
                    appoggio[i - 2] = input[i];
                    contaChar++;
                }
                else if (input[i] != '/') {
                    printf("Formato non valido.\n");
                    valida = 0;
                }
            }
            appoggio[8] = '\0';
        }
    }while (!valida);
    printf("%s \n", input); //debug
    printf("%s \n", appoggio); //debug
    dateConversion(appoggio, output);
}

void dateConversion(char dataIn[], int dataOut[]){
    int esponente; //variabile contentente l'esponente da applicare a 10
    //init
    for(int i = 0; i < 4; i++){
        dataOut[i] = 0;
    }
    //dataout[] 0 = anno, 1 = mese, 2 = giorno
    for (int j = 0; j < 8; j++){
        if (j < 4){
            esponente =  abs(j - 3);
            dataOut[0] += (dataIn[j] - '0') * pow(10, esponente); //es. 1234 = 1*10^3 + 2*10^2 + 3*10^1 4*10^0
        }
        else if (j > 3 && j < 6){
            esponente = abs(j - 5);
            dataOut[1] += (dataIn[j] - '0') * pow(10, esponente);
        }
        else if (j > 5 && j < 8){
            esponente = abs(j - 7);
            dataOut[2] += (dataIn[j] - '0') * pow(10, esponente);
        }
        printf("%d %d %d\n",dataOut[0], dataOut[1], dataOut[2]); //debug
    }   
}

int dateValidation(int input[], int arrayMesi[]){
    //controllo il valore dell'anno/mese e giorno (controllo febbraio se è bisestile)
    if (input[0] < 0){
        printf ("Anno non valido\n\n");
        return 0;
    }
    else if (input[1] < 1 || input[1] > 12){
        printf("Mese non valido.\n\n");
        return 0;
    }
    else if (input[2]){
        if ((input[0] % 400 == 0) || (input[0] % 100 != 0 && input[0] % 4 == 0)){
            if (input[2] < 1 || input[2] > 29){
                printf("Giorno non valido. \n\n");
                return 0;
            }
            else if (input[2] < 1 || input[2] > 28){
                printf("Giorno non valido.\n\n");
                return 0;
            }
            else if (input[2] == 29){
                printf("Anno non valido, l'anno indicato non è bisestile.\n\n");
                return 0;
            }
        }
    }
    else if (input[2] < 0 || input[2] > arrayMesi[input[1]]){
        printf("Giorno non valido.\n\n");
        return 0;
    }
    return 1;
}
