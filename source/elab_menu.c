#include "proto.h"
#include <stdio.h>


int menu(){
    char scelta;

    do{
        printf("Continuare?\n");
        printf("[1] Continua. \n[0] Esci\n");
        scanf(" %c", &scelta);
        while(getchar() != '\n');

        if (scelta < '0' || scelta > '1'){
            printf("Comando non valido.\n\n");
        }
        
    }while(scelta < '0' || scelta > '1');

    return scelta - 48;
}


void dateInversion(char dataChar1[], char dataChar2[], int dimensione, int dataInt1[], int dataInt2[]){
    char appoggioChar[dimensione];
    int  appoggioInt[3];
    
    for (int i = 0; i < dimensione; i++){

        appoggioChar[i] = dataChar1[i];
        dataChar1[i]    = dataChar2[i];
        dataChar2[i]    = appoggioChar[i];

        if (i < 3){
            appoggioInt[i] = dataInt1[i];
            dataInt1[i]    = dataInt2[i];
            dataInt2[i]    = appoggioInt[i]; 
        }
    }
}


void dateElaboration(int data1[], int data2[], const int arrayMesi) {

}