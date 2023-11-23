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

    char formato; //formato data

    printf("Il programma calcolerà quanti giorni sono presenti tra due date, \ncon la possibiltà di scelta del formato.\n\n");
    
    while(menu()) {
        printf("\n");
        //chiedo il formato della data
        formato = dateFormat();
        //chiedo l'input della prima data e eseguo il ciclo finchè la data è valida
        do{
            dateGetValidateFormat(dataInput1, data1, DIMENSIONE_INPUT, formato);
        }while (dateValidation(data1, mesi));
    }
    return 0;
}