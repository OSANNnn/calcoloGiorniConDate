#ifndef PROTO_H
#define PROTO_H


//richiesta di tipo di formato della data e output del valore del formato (1: g/m/a 2: m/a/g 3: a/m/g) 
int dateFormat();

//input utente della data e controllo della validità del formato di quest'ultima
void dateGetValidateFormat(char input[], int output[], int dimensione, int formato, int qualeData);

//conversione da char a int
void dateConversion(char dataIn[], int dataOut[]);

//controllo che l'anno sia bisestile (bool)
int bisestile(int anno);

//validazione della data
int dateValidation(int input[], const int arrayMesi[]);

//scambio le date nei vettori nel caso venga inserita per prima la data più lontana
void dateInversion(char dataChar1[], char dataChar2[], int dimensione, int dataInt1[], int dataInt2[]);

//elaborazione dei dati e output dei risultati
void dateElaboration(int data1[], int data2[], const int arrayMesi[], char input1[], char input2[]);

//menù (bool)
int menu();


#endif