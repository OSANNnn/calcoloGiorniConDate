#include "proto.h"
#include <stdio.h>


int menu(){
    char scelta;

    do{
        printf("\n");
        printf("Continuare?\n");
        printf("[1] Continua. \n[0] Esci\n");
        scanf(" %c", &scelta);
        while (getchar() != '\n');

        if (scelta < '0' || scelta > '1'){
            printf("Comando non valido.\n\n");
        }
        
    }while (scelta < '0' || scelta > '1');

    return scelta - 48; //48 = '0'
}


void dateInversion(char dataChar1[], char dataChar2[], int dimensione, int dataInt1[], int dataInt2[]){
    char appoggioChar[dimensione];
    int  appoggioInt[3];
    //inverto i vettori
    for (int i = 0; i < dimensione; i++){

        appoggioChar[i] = dataChar1[i];
        dataChar1[i]    = dataChar2[i];
        dataChar2[i]    = appoggioChar[i];
        //il vettore è di 3 elementi e smette di scambiare a 2
        if (i < 3){
            appoggioInt[i] = dataInt1[i];
            dataInt1[i]    = dataInt2[i];
            dataInt2[i]    = appoggioInt[i]; 
        }
    }
}


void dateElaboration(int data1[], int data2[], const int arrayMesi[], char input1[], char input2[]){    
    unsigned int contaGiorni = 0;
    //inizio contando tutti i giorni negli anni per intero
    for (int i = data1[0]; i <= data2[0]; i++){

        contaGiorni += arrayMesi[0];

        if (bisestile(i)){
            contaGiorni++;
        }
    }
    //se la data è successiva al 1/1/xxxx scalo i giorni dal totale 
    if (data1[1] > 1 || data1[2] > 1){
        //scalo tutti i giorni dei mesi che non utilizzo
        for (int j = 1; j < data1[1]; j++){
            contaGiorni -= arrayMesi[j];
            //se il bisestile non è compreso lo scalo
            if (j == 2 && bisestile(data1[0])){
                contaGiorni--;
            }
        }
        //scalo i giorni non presenti nell'anno della data
        for (int k = data1[2]; k > 1; k--){
            contaGiorni--;
        }
    }
    //stessa cosa della prima data, scalo i giorni inclusi nel primo ciclo a partire dalla seconda data
    if (data2[1] < 12 || data2[1] < arrayMesi[data2[1]]){
        //scalo i giorni dei mesi
        for (int k = 12; k >= data2[1]; k--){
            contaGiorni -= arrayMesi[k];
            //escludo il bisestile se non compreso
            if (k == 2 && bisestile(data2[0]) && (data2[1] <= 2 && data2[2] < 29)){
                contaGiorni--;
            }
        }
        //scalo i giorni del mese della data tenendo conto che potrebbe essere bisestile
        for (int m = 1; m <= data2[2] ^ (data2[1] == 2 && m == 29 && data2[2] == 29); m++){
            contaGiorni++;
        }
    }

    printf("\n");
    printf("I giorni contenuti dalla data %s alla data %s sono: %d.\n", input1, input2, contaGiorni);
}