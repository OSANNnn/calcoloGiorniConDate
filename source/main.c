/* Programma di calcolo dei giorni presenti tra due date 
** con scelta di formato
** - mm/gg/aaaa (us-uk)
** - gg/mm/aaaa (eu)
** - aaaa/mm/gg ()
*/

#include "proto.h"
#include <stdio.h>

int main(){
    //dimensione dei vettori
    const int DIMENSIONE_INPUT        = 11; // mm + gg + aaaa + 2*/ basato sul tipo di input + /0
    const int DIMENSIONE_ELABORAZIONE = 3;  //0 = anno, 1 = mese, 2 = giorno
    const int DIMENSIONE_MESI         = 13; // 0 = 365, 1 = Gennaio = 31, 2 = febbraio = 28, ... , 12 = dicembre = 31
    
    //vettore contenente i giorni contenuti in un anno e i giorni dei mesi e
    const int mesi[] = {365, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    //vettore per l'input in char e visualizzazione in stringa
    char dataInput1[DIMENSIONE_INPUT];
    char dataInput2[DIMENSIONE_INPUT];
    
    //vettori per l'elaborazione in interi
    int  data1[DIMENSIONE_ELABORAZIONE];
    int  data2[DIMENSIONE_ELABORAZIONE];

    //formato data
    char formato;
    //identifica se è la prima o la seconda data inserita
    int  identificaData;

    printf("Il programma calcolerà quanti giorni sono presenti tra due date, \ncon la possibiltà di scelta del formato.\n");
    
    while (menu()){
        printf("\n");
        //chiedo il formato della data
        formato = dateFormat();
        //chiedo l'input della prima data e eseguo il ciclo finchè la data è valida
        identificaData = 0;
        do{
            dateGetValidateFormat(dataInput1, data1, DIMENSIONE_INPUT, formato, identificaData);
        }while (dateValidation(data1, mesi));
        //chiedo l'input della seconda data
        identificaData++;
        do{
            dateGetValidateFormat(dataInput2, data2, DIMENSIONE_INPUT, formato, identificaData);
        }while (dateValidation(data1, mesi));
        //controllo che la prima data sia antecedente alla sconda, in caso contrario scambio i valori nei vettori, in modo che siano coerenti
        //  (   anno1 > anno2    )XOR(     stesso anno     e     mese1 > mese2   )XOR(     stesso anno     e     stesso mese       e   giorno1 > giorno2 )
        if ((data1[0] > data2 [0]) ^ (data1[0] == data2[0] && data1[1] > data2[1]) ^ (data1[0] == data2[0] && data1[1] == data2[1] && data1[2] > data2[2])){
            dateInversion(dataInput1, dataInput2, DIMENSIONE_INPUT, data1, data2);
        }
        //elaboro i dati e do il risultato dei giorni contenuti nelle date immesse
        dateElaboration(data1, data2, mesi, dataInput1, dataInput2);
    }

    return 0;
}