/* Programma di calcolo dei giorni intercorsi tra due date (data1 e data2)
** con scelta di formato
** - mm/gg/aaaa (us-uk)
** - gg/mm/aaaa (eu)
** - aaaa/mm/gg ()
*/

#include "proto.h"
#include <stdio.h>

int main(){
    const int DIMENSIONE_INPUT        = 11; // mm + gg + aaaa + 2*/ basato sul tipo di input + /0
    const int DIMENSIONE_ELABORAZIONE = 3;  //0 = anno, 1 = mese, 2 = giorno
    const int DIMENSIONE_MESI         = 13; // 0 = 365, 1 = Gennaio = 31, 2 = febbraio = 28, ... , 12 = dicembre = 31
    const int mesi[] = {365, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    char dataInput1[DIMENSIONE_INPUT], dataInput2[DIMENSIONE_INPUT];
    int data1[DIMENSIONE_ELABORAZIONE], data2[DIMENSIONE_ELABORAZIONE];

    char formato; //formato data 1-3
    char ripeti;  //ripeti programma (bool)


    while(menu()) {
        //chiedo il formato della data
        formato = dateFormat();
        //chiedo l'input della prima data e eseguo il ciclo finchè la data è valida
        do{
            dateGetValidate(dataInput1, data1, DIMENSIONE_INPUT, formato);
        }while (dateValidation(data1, mesi));
    }
    return 0;
}