#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "lib.h"
#include "ArrayList.h"


/**
 *  Premite modificar una pelicula del archivo binario
 *  @param movieList el array de estructuras EMovie en el que se buscara y modificara la pelicula
 *  @param lenMovies es la cantidad maxima posible de peliculas en el sistema
 *  @return void
 */
int EMovie_modificarPelicula(ArrayList* movieList)
{
    char aux[401];
    EMovie* auxMovie = NULL;
    int indice;
    int retorno=-1;

    fflush(stdin);

    printf("\n");
    if(EMovie_pedirTitulo(auxMovie,aux)==0 && (indice = EMovie_buscarPelicula(movieList,aux))!= -1)
    {
        modificar(movieList->get(movieList,indice),&retorno);
    }
    else if(indice == -1)
    {
        printf("\n\nLa pelicula no se encuentra en el sistema.\n\n");
        system("pause");
    }
    return retorno;
}


/**
 *  Premite modificar una pelicula del archivo binario
 *  @param movie la estructura a ser modificada al archivo
 *  @param aux es la variable en la que se realizan las distintas validaciones
 *  @return void
 */
void modificar(EMovie* movie,int* retorno)
{
    char seguir = 's';
    char aux[410];
    int opcion;
    do
    {
        system("cls");
        fflush(stdin);
        EMovie_mostrarPeliculaEnt(movie);
        opcion=mostrarMenu("\n\n1-Titulo\n2-Genero\n3-Duracion\n4-Puntaje\n5-Salir");
        switch(opcion)
        {
        case 1:
            *retorno = EMovie_pedirTitulo(movie,aux);
            break;
        case 2:
            *retorno = EMovie_pedirGenero(movie,aux);
            break;
        case 3:
            *retorno = EMovie_pedirDuracion(movie);
            break;
        case 4:
            *retorno = EMovie_pedirPuntaje(movie);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("\n\nError.Debe ser un numero entre 1 y 3.\n\n");
            system("pause");
            fflush(stdin);
        }
    }while(seguir=='s');
}


/**
 *  Busca una pelicula por nombre y retorna su indice
 *  @param movieList el array de estructuras EMovie en el que se raliza la busqueda
 *  @param lenMovies es la canidad maxima posible de peliculas en el sistema
 *  @param titulo es el titulo por el que se buscara la pelicula
 *  @return retorna -1 si la pelicula no se encuentra en el sistema y el indice de la pelicula si la encuentra
 */
int EMovie_buscarPelicula(ArrayList* movieList, char* titulo)
{
    int retorno = -1;
    int i;

    for(i=0; i<movieList->size; i++)
    {
        if(strcmp(stringToGenericCase(titulo),stringToGenericCase(EMovie_getTitulo(movieList->get(movieList,i))))==0)
        {
            retorno = i;
            break;
        }
        else if(i == movieList->size)
        {
            printf("\nLa pelicula no se encuentra en el sistema.\n\n");
            system("pause");
        }
    }
    return retorno;
}


/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int EMovie_borrarPelicula(ArrayList* movieList)
{
    char opcion;
    int retorno=-1;
    int indice;
    char aux[256];
    EMovie* movieAux = NULL;

    printf("\n");
    EMovie_pedirTitulo(movieAux,aux);

    indice = EMovie_buscarPelicula(movieList,aux);
    if(indice==-1)
    {
        printf("\n\nLa pelicula no esta en el sistema.\n\n");
        system("pause");
    }
    else
    {
        printf("\n");
        EMovie_mostrarPelicula(movieList->get(movieList,indice));
        printf("\n\nEste es la pelicula que desea dar de baja?: ");
        fflush(stdin);
        scanf("%c",&opcion);
        if(opcion=='s')
        {
            movieList->remove(movieList,indice);
            printf("\n\nBaja realizada con exito.\n\n");
            system("pause");
            retorno=0;
        }
        else
        {
            printf("\n\nBaja cancelada por el usuario.\n\n");
            system("pause");
        }
    }

    return retorno;

}


/**
 *  Muestra una pelicula que le llega por parametro
 *  @param this es la pelicula a mostrar
 *  @return void
 */
void EMovie_mostrarPelicula(EMovie* this)
{
    printf("Titulo: %s Genereo: %s Duracion: %d Puntaje: %d",EMovie_getTitulo(this),EMovie_getGenero(this),EMovie_getDuracion(this),EMovie_getPuntaje(this));
}


/**
 *  Muestra una pelicula y todos sus campos que le llega por parametro
 *  @param this es la pelicula a mostrar
 *  @return void
 */
void EMovie_mostrarPeliculaEnt(EMovie* this)
{
    printf("Titulo: %s \nGenereo: %s \nDuracion: %d \nPuntaje: %d",EMovie_getTitulo(this),EMovie_getGenero(this),EMovie_getDuracion(this),EMovie_getPuntaje(this));
}

/**
 *  Muestra una pelicula y todos sus campos que le llega por parametro
 *  @param this es la pelicula a mostrar
 *  @return void
 */
void EMovie_mostrarPeliculaEnt2(EMovie* this)
{
    printf("\nTitulo: %s   Genereo: %s   Duracion: %d   Puntaje: %d",EMovie_getTitulo(this),EMovie_getGenero(this),EMovie_getDuracion(this),EMovie_getPuntaje(this));
}


/** \brief pone el titulo indicado en el campo titulo de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara el titulo de ser valido
 * \param  titulo es el titulo a copiar
 * \return retorna -1 si this es null o 0 si se pudo realizar con exito
 *
 */
int EMovie_setTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(this->titulo,titulo);
    }
    return retorno;
}


/** \brief retorna el titulo de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna null si this es null o el titulo si se pudo realizar con exito
 *
 */
char* EMovie_getTitulo(EMovie* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->titulo;
    }
    return retorno;
}


/** \brief pone el genero indicado en el campo genero de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara el genero de ser valido
 * \param  genero es el genero a copiar
 * \return retorna -1 si this es null o 0 si se pudo realizar con exito
 *
 */
int EMovie_setGenero(EMovie* this, char* genero)
{
    int retorno=-1;

    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(this->genero,genero);
    }
    return retorno;
}


/** \brief retorna el genero de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna null si this es null o el genero si se pudo realizar con exito
 *
 */
char* EMovie_getGenero(EMovie* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->genero;
    }
    return retorno;
}


/** \brief pone la duracion indicado en el campo duracion de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara la duracion de ser valido
 * \param  duracion es la duracion a copiar
 * \return retorna -1 si this es null o e si se pudo realizar con exito
 *
 */
int EMovie_setDuracion(EMovie* this, char* duracion)
{
    int retorno=-1;

    if(this != NULL && duracion != NULL)
    {
        retorno = 0;
        this->duracion = atoi(duracion);
    }
    return retorno;
}


/** \brief retorna la duracion de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna -1 si this es null o la duracion si se pudo realizar con exito
 *
 */
int EMovie_getDuracion(EMovie* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->duracion;
    }
    return retorno;
}


/** \brief pone el puntaje indicado en el campo puntaje de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara el puntaje de ser valido
 * \param  puntaje es el puntaje a copiar
 * \return retorna -1 si this es null o 0 si se pudo realizar con exito
 *
 */
int EMovie_setPuntaje(EMovie* this, char* puntaje)
{
    int retorno=-1;

    if(this != NULL && puntaje != NULL)
    {
        retorno = 0;
        this->puntaje = atoi(puntaje);
    }
    return retorno;
}


/** \brief retorna el puntaje de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna -1 si this es null o el si puntaje se pudo realizar con exito
 *
 */
int EMovie_getPuntaje(EMovie* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->puntaje;
    }
    return retorno;
}


/** \brief pide un titulo al usuario, valida su tamaño, que solo sean letras y numeros, lo formatea y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara el titulo de ser valido
 * \param  buffer es una variable auxiliar con la que se realizan las validaciones
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirTitulo(EMovie* this,char* buffer)
{
    int retorno = -1;

    fflush(stdin);

    if(getStringAlfaNumerico("Ingrese el titulo de la pelicula: ",buffer))
    {
        fflush(stdin);
        printf("\n\nSolo pueden ingresarse letras y numeros.\n\n");
        system("pause");
    }
    else if(validarTamArray(buffer,3,20))
    {
        printf("\nEl genero debe tener entre 3 y 20 caracteres.\n\n");
        system("pause");
    }
    else
    {
        formatSentence(buffer);
        EMovie_setTitulo(this,buffer);
        retorno = 0;
    }

    return retorno;
}


/** \brief pide un genero al usuario, valida su tamaño, que solo sean letras, lo formatea y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara el genero de ser valido
 * \param  buffer es una variable auxiliar con la que se realizan las validaciones
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirGenero(EMovie* this,char* buffer)
{
    int retorno = -1;

    fflush(stdin);

    if(!getStringLetras("\nIngrese el genero de la pelicula: ",buffer))
    {
        fflush(stdin);
        printf("\n\nDeben ingresarse letras solamente.\n\n");
        system("pause");
    }
    else if(validarTamArray(buffer,3,20))
    {
        printf("\nEl genero debe tener entre 3 y 20 caracteres.\n\n");
        system("pause");
    }
    else
    {
        formatSentence(buffer);
        EMovie_setGenero(this,buffer);
        retorno=0;
    }

    return retorno;
}


/** \brief pide una duracion al usuario, valida que este dentro del rango y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara la duracion de ser valido
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirDuracion(EMovie* this)
{
    int retorno = -1;
    char aux[256];

    if(validarIntYRango("\nIngrese la duracion (en minutos) de la pelicula: ",aux,30,180) == 0)
    {
        this->duracion = atoi(aux);
        retorno=0;
    }

    return retorno;
}


/** \brief pide un puntaje al usuario, valida que este dentro del rango y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara el puntaje de ser valido
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirPuntaje(EMovie* this)
{
    int retorno = -1;
    char aux[256];

    if(validarIntYRango("\nIngrese el puntaje de la pelicula: ",aux,1,10) == 0)
    {
        this->puntaje = atoi(aux);
        retorno=0;
    }

    return retorno;
}


/** \brief reserva espacion en memoria para una estructura del tipo EMovie
 *
 * \return retorna el puntero a la estructura o NULL si no pudo encontrar espacio para esta
 *
 */
EMovie* EMovie_new()
{
    EMovie* retorno = NULL;
    EMovie* aux = malloc(sizeof(EMovie));
    if(aux != NULL)
    {
        retorno = aux;
    }

    return retorno;
}

/** \brief reserva espacion en memoria para una estructura del tipo EMovie
 *
 * \return retorna el puntero a la estructura o NULL si no pudo encontrar espacio para esta
 *
 */
EMovie* EMovie_newWithParam(char* titulo, char* genero, int duracion, int puntaje)
{
    EMovie* retorno = NULL;
    EMovie* aux = malloc(sizeof(EMovie));
    if(aux != NULL)
    {
        strcpy(aux->titulo,titulo);
        strcpy(aux->genero,genero);
        aux->duracion = duracion;
        aux->puntaje = puntaje;
        retorno = aux;
    }

    return retorno;
}


int compararPorTitulo(EMovie* movie1, EMovie* movie2)
{
    return strcmp(EMovie_getTitulo(movie1),EMovie_getTitulo(movie2));
}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @param lenMovies es la cantidad maxima posible de pelculas en el sistema
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int EMovie_agregarPelicula(ArrayList* movieList)
{
    char bufferTitulo[256];
    char buffer[401];
    int retorno = -1;
    EMovie* auxMovie = EMovie_new();

    printf("\n\n--- Alta pelicula ---\n\n");
    if(auxMovie != NULL && (EMovie_pedirTitulo(auxMovie,bufferTitulo)==0) && (EMovie_pedirGenero(auxMovie,buffer)==0)
        && (EMovie_pedirDuracion(auxMovie)==0) && (EMovie_pedirPuntaje(auxMovie)==0))
    {
        movieList->add(movieList,auxMovie);
        retorno=0;
        printf("\n\n-Alta realizada con exito-\n\n");
        system("pause");
    }

    return retorno;
}


/** \brief lista las peliculas
 *
 * \param this es el puntero a movie del que se obtendrar las peliculas a mostrar
 * \return void
 *
 */
void EMovie_listarPeliculas(ArrayList* movieList)
{
    int i;

    for(i=0; i<movieList->size; i++)
    {
        printf("%s %s",EMovie_getTitulo(al_get(movieList,i)),EMovie_getGenero(al_get(movieList,i)));
    }

}

