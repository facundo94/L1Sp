#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"
#include "movie.h"


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras y numeros
 */
int getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    int retorno = -1;

    printf("%s",mensaje);
    scanf ("%s", aux);
    if(esAlfaNumerico(aux))
    {
        retorno = 0;
        strcpy(input,aux);
    }

    return retorno;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ', letras y numeros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/** \brief  formatea un array de char dejando todas las letras sean minusculas y eliminando los espacios vacios si los hay
 *
 * \param input es el array a formatear
 * \return retorna el array formateado con todas las letras en minuscula y sin espacios vacios
 *
 */
char* stringToGenericCase(char* input)
{
    int i,j;

    strlwr(input);

    char *output=input;
    for (i = 0, j = 0; i<strlen(input); i++,j++)
    {
        if (input[i]!=' ')
            output[j]=input[i];
        else
            j--;
    }
    output[j]=0;
    return output;
}


/** \brief formatea un array de char para que cada palabera comience con mayuscula
 *
 * \param arrayString es el array a formatear
 * \return void
 *
 */
void formatSentence(char* arrayString)
{
    int i;
    strlwr(arrayString);
    arrayString[0] = toupper(arrayString[0]);
    for(i=0; i<strlen(arrayString); i++)
    {
        if(arrayString[i] == ' ')
        {
            arrayString[i] = toupper(arrayString[i]);
        }
    }
}

/** \brief recibe un contador y verifica que sea mayor a cero para saber si se ingreso al menos una pelicula el sistema
 *
 * \param cantAbonados es el contador a verificar
 * \return retorna 0 si es mayor a cero y -1 si es menor o igual a cero
 *
 */
int iniciarFuncion(ArrayList* movieList)
{
    int retorno = 0;

    if(movieList->size < 1)
    {
        printf("\n\nNo hay ninguna pelicula dada de alta.\n\n");
        system("pause");
        retorno = -1;
    }

    return retorno;
}

/** \brief Muestra un menu de opciones y devuelve la opcion elegida
 *
 * \param opciones son las opciones a mostrar por pantalla
 * \return retorna la opcion que elige el usuario
 *
 */
int mostrarMenu(char opciones[])
{
    int opcion;

    printf("%s",opciones);
    printf("\n\nIndique opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getStringWithSpace(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
            return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve (soporta espacios)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getStringWithSpace(char mensaje[],char input[])
{
    printf("%s",mensaje);
    gets(input);
}

/** \brief valida el tamaño de un array para que este no desborde la variable destino
 *
 * \param aux es el array de char que se usa para validar el tamaño de la cadena ingresada
 * \param tam es el tamaño maximo que la cadena pude tener para ser valida
 * \return retorna 1 si es mayor al tamaño esperado y 0 si es menor a este
 *
 */
int validarTamArray(char aux[],int desde,int hasta)
{
    int valido=0;

    if(strlen(aux)<desde || strlen(aux)>hasta)
    {
        valido=1;
    }

    return valido;
}

/** \brief valida que la cadena recibida sea numerica y entera, y que este dentro del rango recibido
 *
 * \param pedirNumero es el mensaje que especifica que numero se desea pedir al usuario
 * \param auxNumero es la cadena de tipo char en la que se cargara el numero a validar
 * \param desde es el numero minimo posible dentro del rango
 * \param hasta es el numero maximo posible dentro del rango
 * \return retorna 0 si es un numero y esta dentro del rango y -1 si no cumple con alguna de las condiciones
 *
 */
int validarIntYRango(char pedirNumero[],char auxNumero[],int desde,int hasta)
{
    int retorno=0;

    if(!getStringNumeros(pedirNumero,auxNumero))
    {
        fflush(stdin);
        printf("\n\nSolo pueden ingresarse numeros.\n\n");
        system("pause");
        retorno=-1;
    }
    else if(atoi(auxNumero)<desde || atoi(auxNumero)>hasta)
    {
        printf("\nDebe ser un numero entre %d y %d.\n\n",desde,hasta);
        system("pause");
        retorno=-1;
    }

    return retorno;
}

