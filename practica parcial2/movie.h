#ifndef MOVIE_H
#define MOVIE_H
#include "ArrayList.h"

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    int puntaje;
}EMovie;

EMovie* EMovie_new();
int EMovie_agregarPelicula(ArrayList* this);
int EMovie_borrarPelicula(ArrayList*);
void generarPagina(EMovie [],int );
int EMovie_pedirTitulo(EMovie* ,char* buffer);
int EMovie_setTitulo(EMovie* , char* titulo);
char* EMovie_getTitulo(EMovie* );
int EMovie_setGenero(EMovie* , char* genero);
char* EMovie_getGenero(EMovie* );
int EMovie_setDuracion(EMovie* , char* duracion);
int EMovie_getDuracion(EMovie* );
int EMovie_setPuntaje(EMovie* , char* puntaje);
int EMovie_getPuntaje(EMovie* );
void EMovie_listarPeliculas(ArrayList* );
int EMovie_pedirDuracion(EMovie* );
int EMovie_buscarPelicula(ArrayList*, char* );
int EMovie_pedirPuntaje(EMovie* );
void EMovie_mostrarPelicula(EMovie*);
void EMovie_mostrarPeliculaEnt(EMovie* );
int EMovie_modificarPelicula(ArrayList*);
void modificar(EMovie*,int* );
int EMovie_pedirGenero(EMovie* ,char* );
int EMovie_pedirDescripcion(EMovie* ,char* );
int compararPorTitulo(EMovie* movie1, EMovie* movie2);
EMovie* EMovie_newWithParam(char* titulo, char* genero, int duracion, int puntaje);
void EMovie_mostrarPeliculaEnt2(EMovie* this);

#endif // MOVIE_H
