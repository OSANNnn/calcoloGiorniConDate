#ifndef PROTO_H
#define PROTO_H


//richiesta di tipo di formato della data e output del valore del formato (1-3)
int dateFormat();
//input utente della data e controllo della validità di quest'ultima
void dateGetValidate(char input[], int dimensione[], int formato);
//conversione da char a int
void dateConversion(char dataIn[], int dataOut[]);
//elaborazione dei dati e output dei risultati
void daysPassed(int data1[], int data2[]);
//menù
int menu();

#endif