#ifndef PROTO_H
#define PROTO_H


//richiesta di tipo di formato della data e output del valore del formato (1: g/m/a 2: m/a/g 3: a/m/g) 
int dateFormat();
//input utente della data e controllo della validità del formato di quest'ultima
void dateGetValidateFormat(char input[], int output[], int dimensione, int formato);
//conversione da char a int
void dateConversion(char dataIn[], int dataOut[]);
//validazione della data
int dateValidation(int input[], const int arrayMesi[]);
//elaborazione dei dati e output dei risultati
void dateElaboration(int data1[], int data2[], const int giorni);
//menù (bool)
int menu();

#endif