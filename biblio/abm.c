#include <stdio.h>
#include <string.h>
#include "abm.h"

int obtenerEspacio (eEstructura lista[],int tam)
{
    int i, aux;

    for (i=0;i<tam;i++)
    {
        if (lista[i].estado==0)
            {
                aux=i;
            }
    }
    return aux;
}

int buscar(eEstructura lista[],int dato,int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        if(lista[i].estado==1 && lista[i].dato == dato)
            {
                printf("//MOSTRAR LO QUE SEA NECESARIO");
            }
    }
    return dato;
}

void borrar (eEstructura lista[],int tam, int dato)
{
    char rta;
    int i;
    for (i=0;i<tam;i++)
    {
        if (lista[i].estado==1 && lista[i].dato == dato)
        {
            printf("Desea elminilarlo? <s/n>\n");
            rta = getch();
            if (rta == 's')
            {
                lista[i].estado = 0;
            }
        }
    }
}

void alta (eEstructura lista[], int tam)
{
    int i;

    i=obtenerEspacio(lista,tam);
    lista[i].estado = 1;
    printf("//PEDIR E INGRESAR LOS DATOS NECESARIOS");
}

void mostrar (eEstructura lista[],int tam)
{
    int i;

    for (i=0;i<tam;i++)
    {
        if (lista[i].estado == 1)
        {
            printf("//MOSTRAR  LO QUE SEA NECESARIO");
        }
    }
}

void modificar (eEstructura lista [], int tam)
{
    int i;
    int dato;
    int opcion;

    printf("//PEDIR DATO A BUSCAR");
    dato = buscar(lista,dato,tam);

    for (i=0;i<tam;i++)
    {
        if (lista[i].estado == 1 && lista[i].dato == dato)
        {
            printf("//MOSTRAR LOS DATOS Y PREGUNTAR CUAL SE QUIERE ELIMINAR DANDO OPCIONES");
            scanf("%d",&opcion);
            switch (opcion)
            {
            case 1:
                printf("//PEDIR NUEVO DATO");
            break;
            }
        }
    }
}

void ordenar(eEstructura lista[], int tam)
{
    int i,j;
    eEstructura aux[50];

    for (i=0; i<tam-1; i++)
    {
        for (j=i +1; j<tam; j++)
        {
            if(strcmp(lista[i].vec,lista[j].vec)>0)
            {
                strcpy (aux,lista[i].vec);
                strcpy (lista[i].vec,lista[j].vec);
                strcpy (lista[j].vec,aux);
            }
        }
    }
}
