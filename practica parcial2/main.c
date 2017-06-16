#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "movie.h"
#include "lib.h"

//#define MENU

void prueba();

int main()
{
    #ifdef MENU
    char seguir = 's';
    ArrayList* arrayPeliculas = al_newArrayList();

    do
    {
        system("cls");
        switch(mostrarMenu("1-Alta\n2-Modificar\n3-Baja\n4-Listar\n5-Salir"))
        {
        case 1:
            EMovie_agregarPelicula(arrayPeliculas);
            break;
        case 2:
            if(!iniciarFuncion(arrayPeliculas))
                EMovie_modificarPelicula(arrayPeliculas);
            break;
        case 3:
            if(!iniciarFuncion(arrayPeliculas))
                EMovie_borrarPelicula(arrayPeliculas);
            break;
        case 4:
            if(!iniciarFuncion(arrayPeliculas))
            {
                EMovie_listarPeliculas(arrayPeliculas);
                printf("\n\n");
                system("pause");
            }
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            fflush(stdin);
            printf("Debe ingresarse u numero entre 1 y 5.\n\n");
            system("pause");
        }

    }while(seguir == 's');
    #else
        prueba();
    #endif

    return 0;
}

void prueba()
{
    printf("Creo las peliculas y el ArrayList");
    ArrayList* movieList = al_newArrayList();
    EMovie* m1 = EMovie_newWithParam("titulo1","genero1",5,120);
    EMovie* m2 = EMovie_newWithParam("titulo2","genero2",6,121);
    EMovie* m3 = EMovie_newWithParam("titulo3","genero3",7,122);
    EMovie* m4 = EMovie_newWithParam("titulo4","genero4",8,123);

    printf("\n\nLas agrego al ArrayList");
    movieList->add(movieList,m1);
    movieList->add(movieList,m2);
    movieList->add(movieList,m3);
    movieList->add(movieList,m4);

    EMovie_mostrarPeliculaEnt2(m1);
    EMovie_mostrarPeliculaEnt2(m2);
    EMovie_mostrarPeliculaEnt2(m3);
    EMovie_mostrarPeliculaEnt2(m4);

    printf("\n\n\nOrdenadas por titulo decendente");
    int i;
    movieList->sort(movieList,compararPorTitulo,0);
    for(i=0; i<movieList->size; i++)
    {
        EMovie_mostrarPeliculaEnt2(movieList->get(movieList,i));
    }

    printf("\n\n\nOrdenadas por titulo acendente");
    movieList->sort(movieList,compararPorTitulo,1);
    for(i=0; i<movieList->size; i++)
    {
        EMovie_mostrarPeliculaEnt2(movieList->get(movieList,i));
    }

    printf("\n\n\nRemuevo el elemento de indice 2");
    movieList->remove(movieList,2);
    for(i=0; i<movieList->size; i++)
    {
        EMovie_mostrarPeliculaEnt2(movieList->get(movieList,i));
    }

    printf("\n\n\nHago set del elemento 3 en el indice 1");
    movieList->set(movieList,1,m3);
    for(i=0; i<movieList->size; i++)
    {
        EMovie_mostrarPeliculaEnt2(movieList->get(movieList,i));
    }

    printf("\n\n\nHago un push del elemento 2 en el indice 1");
    movieList->push(movieList,1,m2);
    for(i=0; i<movieList->size; i++)
    {
        EMovie_mostrarPeliculaEnt2(movieList->get(movieList,i));
    }

    printf("\n\n\nClono la lista.");
    ArrayList* movieList2 = movieList->clone(movieList);

    printf("\n\nLista original:\n");
    for(i=0; i<movieList->size; i++)
    {
        EMovie_mostrarPeliculaEnt2(movieList->get(movieList,i));
    }

    printf("\n\nLista clonada:\n");
    for(i=0; i<movieList->size; i++)
    {
        EMovie_mostrarPeliculaEnt2(movieList2->get(movieList2,i));
    }

    printf("\n\n\nLista original contiene a la lista clonada? ");
    if(movieList->containsAll(movieList,movieList2))
    {
        printf("Si.");
    }
    else
    {
        printf("No.");
    }

    printf("\n\n\nLibero memoria y termino.\n\n\n");
    free(m1);
    free(m2);
    free(m3);
    free(m4);
    movieList->deleteArrayList(movieList);

    system("pause");

}
