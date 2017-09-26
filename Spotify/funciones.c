#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void inicializarCancion (eCancion lista[],int tam)
{
    int i;
    int id [] = {1,2,3,4,5,6,7};
    char titulo [][30] = {"Escape","Hotel California","Bohemian Rhapsody","Cocaine","Smooth criminal","Of wolf and man","Brighton rock"};
    int interprete [] = {10,11,12,13,14,10,12};
    int duracion []= {3,4,7,4,9,5,4};

    for (i=0;i<tam;i++)
    {
        lista[i].idCancion = id[i];
        strcpy (lista[i].titulo, titulo[i]);
        lista[i].duracion = duracion [i];
        lista[i].interprete = interprete[i];
        lista[i].estado = 1;
    }

}

void inicializarInterprete (eInterprete lista[],int tam)
{
    int i;
    int id [] = {10,11,12,13,14};
    char nombre [][50] = {"Metallica","The eagles","Queen","Eric Clapton","Michael Jackson"};
    char nacionalidad [][30] = {"Estadounidense","Estadounidense","Britanica","Britanica","Estadounidense"};

    for (i=0;i<tam;i++)
    {
        lista[i].idInterprete = id[i];
        strcpy (lista[i].nombre, nombre[i]);
        strcpy (lista[i].nacionalidad, nacionalidad[i]);
        lista [i].estado = 1;
    }
}


void listarCanciones (eCancion lista[],int tam)
{
    int i;
    printf("Canciones:\n");

    for (i=0;i<tam;i++)
    {
        if (lista[i].estado == 1)
        {
            printf("%d---%s---%d minutos---%d interprete\n",lista[i].idCancion,lista[i].titulo,lista[i].duracion,lista[i].interprete);
        }
    }
}

void listarInterpretes (eInterprete lista[],int tam)
{
    int i;
    printf("Interpretes:\n");

    for (i=0;i<tam;i++)
    {
        if (lista[i].estado == 1)
        {
            printf("%d---%s---%s\n",lista[i].idInterprete,lista[i].nombre,lista[i].nacionalidad);
        }
    }
}

void listarCancionesConInterprete (eCancion listaCanciones[],int tamC, eInterprete listaInterprete[],int tamI)
{
    int i;
    int j;
    eInterprete auxInterprete;
    printf(" ID \t\tCANCION\t\tDURACION\tINTERPRETE\n ");

    for (i=0;i<tamC;i++)
    {
        for (j=0;j<tamI;j++)
        {
            if (listaCanciones[i].estado ==1 && listaInterprete[j].estado == 1)
            {
                if (listaCanciones[i].interprete == listaInterprete[j].idInterprete)
                {
                    auxInterprete = listaInterprete[j];
                    break;
                }
            }

        }
        printf("%4d\t%20s\t%4d\t%20s\n",listaCanciones[i].idCancion,listaCanciones[i].titulo,listaCanciones[i].duracion,auxInterprete.nombre);
    }
}

void listarCancionesEstadounidenses (eCancion listaCanciones[],int tamC, eInterprete listaInterprete[],int tamI)
{
    int i,j;
    eInterprete auxInterprete[tamI];
    printf("CANCIONES ESTADOUNIDENSES\n");

    for (i=0;i<tamI;i++)
    {
        if (strcmp(listaInterprete[i].nacionalidad,"Estadounidense")==0)
        {
            auxInterprete[i].idInterprete=listaInterprete[i].idInterprete;

            for (j=0;j<tamC;j++)
            {
                if (listaCanciones[j].interprete==auxInterprete[i].idInterprete)
                {
                    printf("%s\n",listaCanciones[j].titulo);
                }
            }

        }
    }
}

void cancionesPorInterprete (eCancion listaCanciones[],int tamC, eInterprete listaInterprete[],int tamI)
{
    int i;
    int j;

    for (i=0;i<tamI;i++)
    {
        printf("INTERPRETE %s\n",listaInterprete[i].nombre);
        for (j=0;j<tamC;j++)
        {
            if (listaCanciones[j].interprete==listaInterprete[i].idInterprete)
            {
                printf("\t%s\n",listaCanciones[j].titulo);
            }
        }
    }
}
