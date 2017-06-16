#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "ArrayList.h"

int iniciarFuncion(ArrayList*);
void getStringWithSpace(char mensaje[],char input[]);
int mostrarMenu(char opciones[]);
int getStringLetras(char mensaje[],char input[]);
int esSoloLetras(char str[]);
int getStringNumeros(char mensaje[],char input[]);
int esNumerico(char str[]);
void getString(char mensaje[],char input[]);
int validarTamArray(char aux[],int desde,int hasta);
int validarIntYRango(char pedirNumero[],char auxNumero[],int desde,int hasta);
void formatSentence(char* arrayString);
char* stringToGenericCase(char* input);
int getStringAlfaNumerico(char [],char []);
int esAlfaNumerico(char []);

#endif // FUNCIONES_H

