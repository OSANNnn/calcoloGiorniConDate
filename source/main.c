/* Programma di calcolo dei giorni intercorsi tra due date (data1 e data2)
** con scelta di formato
** - mm/gg/aaaa (us-uk)
** - gg/mm/aaaa (eu)
** - aaaa/mm/gg ()
*/

#include "proto.h"
#include <stdio.h>

int main(){
    const int DIMENSIONE_INPUT        = 9; // mm + gg + aaaa + 2*/ basato sul tipo di input + /0
    const int DIMENSIONE_ELABORAZIONE = 3;  //0 = giorno, 1 = mese, 2 = anno
    const int DIMENSIONE_MESI         = 13; // 0 = 365, 1 = Gennaio = 31, 2 = febbraio = 28, ... , 12 = dicembre = 31
    
    char dataInput[DIMENSIONE_INPUT]; 
    int data1[DIMENSIONE_ELABORAZIONE], data2[DIMENSIONE_ELABORAZIONE];
    int mesi[] = {361, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    char formato; //formato data 1-3
    char scelta;  //ripeti programma

    dateGetValidate(dataInput, DIMENSIONE_INPUT, dateFormat());

    /*do{
        //menu
        

        while (scelta == '1') {
            //chiedo che formato usare
            //formato = dateFormat();
            //chiedo la prima data

            //converto la prima data da char a int

            //chiedo la seconda data

            //converto la seconda data da char a int

            //elaboro i dati e do il risultato
        }

    }while (scelta == '1');*/

    return 0;
}