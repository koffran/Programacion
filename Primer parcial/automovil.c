#include "automovil.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int initeAutomovils (eAutomovil* autos, int tam)
{
    int i,retorno = -1;

    if (autos !=NULL)
    {
        for (i=0; i<tam; i++)
        {
            autos[i].estado = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int obtenerEspacioLibreAuto(eAutomovil lista[],int tam)
{
    int indice = -1,i;
    for (i=0; i<tam; i++)
    {
        if (lista[i].estado ==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int findeAutomovilById(eAutomovil* lista, int id,int tam)
{
    int i,indice = -1;
    for (i=0; i<tam; i++)
    {
        if (id == lista[i].id)
        {
            indice = i;
        }
    }
    return indice;
}

void altaAutos (eAutomovil* lista, int i)
{
    char patente[7];
    int id, propietario,marca;

    printf("ingrese el ID del cliente: \n");
    scanf("%d",&propietario);

    printf("Ingrese la marca :\n1- ALPHA ROMEO \n2- FERRARI \n3- AUDI \n4 - OTRO");
    scanf("%d",&marca);

    printf("ingrese la patente: \n");
    fflush(stdin);
    gets(patente);

    id = i+1;

   if (addeAutomovils(lista,i,id,patente,marca,propietario)==0)
   {
       printf("Publicacion cargada\n");
   }

}

int addeAutomovils(eAutomovil* list, int indice, int id,char patente[],int marca,int propietario)
{
     int returnAux = -1;

    if(list != NULL)
    {
        list[indice].id = id;
        strcpy(list[indice].patente,patente);
        list[indice].estado = ESTACIONADO;
        list[indice].propietario = propietario;
        list[indice].marca = marca;
        returnAux = 0;
    }
    return returnAux;
}

int estacionarAutomovil(eAutomovil* autos,int indice)
{
    char rta;
    int retorno =0;

    printf("Estacionar este automovil? <S/N>\n");
    rta = getch();
    rta = tolower(rta);
    fflush(stdin);
    if (rta == 's')
    {
        autos[indice].estado = ESTACIONADO;
        retorno = 1;
    }
    return retorno;
}

float retirarAutos(eAutomovil* autos,int indice)
{
    char rta;
    float retorno =0;
    int horas,aux;

    printf("Desea retirar este auto? <S/N>\n");
    rta = getch();
    rta = tolower(rta);
    fflush(stdin);
    if (rta == 's')
    {
        autos[indice].estado = NO_ESTACIONADO;
        retorno = 1;
    }

    aux = autos[indice].marca;
    horas = devolverHorasEstadia();

    switch(aux)
    {
    case 1:
        retorno = horas * 150.0;
        break;
    case 2:
        retorno = horas * 175;
        break;
    case 3:
        retorno = horas * 200;
        break;
    case 4:
        retorno = horas * 250;
        break;
    }
    printf("Estuvo estacionado %d horas\n",horas);
    return retorno;
}

void printeAutomovil(eAutomovil* list, int i)
{
    if (list[i].estado == ESTACIONADO)
    {
        printf("ID de auto: %d\nID de cliente: %d\n",list[i].id,list[i].propietario);
        printf ("patente: \n%s\n\n",list[i].patente);
    }
}

void printeAutomovils(eAutomovil* list, int length)
{
    int i;
    for (i=0; i<length; i++)
    {
        printeAutomovil(list,i);
    }
}

void printeAutomovilsRetirados(eAutomovil* list, int length)
{
    int i;
    for (i=0; i<length; i++)
    {
        printeAutomovilRetirado(list,i);
    }
}
void printeAutomovilRetirado(eAutomovil* list, int i)
{
    if (list[i].estado == NO_ESTACIONADO)
    {
        printf("ID de publicacion: %d\nID de cliente: %d\n",list[i].id,list[i].propietario);
        printf ("Publicacion: \n%s\n\n",list[i].patente);
    }
}

int sorteAutomovils (eAutomovil* lista, int tam, int order)
{
    int i,j,retorno =-1;
    eAutomovil aux;

    for (i=0; i<tam-1; i++)
    {
        if(lista[i].estado ==1)
        {
            for (j=i+1; j<tam; j++)
            {
                if(lista[j].estado ==1 && order == 1)
                {
                    if(strcmp(lista[i].patente, lista[j].patente)>0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].patente, lista[j].patente)==0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    }
                }
                else
                {
                    if(lista[j].estado ==1 && order == 0)
                {
                    if(strcmp(lista[i].patente, lista[j].patente)<0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].patente, lista[j].patente)==0 )
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    }
                }
                }

            }
            retorno =0;
        }
    }
    return retorno;
}

void modificarAuto (eAutomovil* lista, int tam, int id)
{
    int rta;
    int indice;
    char seguir = 's';

    indice = findeAutomovilById(lista,id,tam);

    if (indice == -1)
    {
         printf("No se encontro el ID ingresado\n");
    }
    else
    {
        if (lista[indice].estado == 1)
            {
                while (seguir == 's')
                {
                    system("cls");
                    printf("Apellido\t\tNombre\t\t\tid\t\tmarca\n");
                    printeAutomovil(lista,indice);
                    printf("Que dato desea modificar? \n1- Apellido\n2- Nombre\n3- marca\n4- Salir\n");
                    scanf("%d",&rta);
                    switch (rta)
                    {
                    case 1:
                        system("cls");
                        printf("Que apellido desea asignarle?\n");
                        fflush(stdin);
                        gets(lista[indice].patente);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        printf("Que nombre desea asignarle?\n");
                        fflush(stdin);


                        system("pause");
                        break;
                    case 3:
                         system("cls");
                        printf("Ingrese la marca:\n");

                        system("pause");
                        break;
                    case 4:
                        seguir = 'n';
                        break;
                    default:
                        printf("Ingrese una opcion valida <1-5>");
                        system("pause");
                    }
                }
            }
    }
}



void hardcodeoAutos (eAutomovil personas[])
{
   strcpy(personas[0].patente,"Sanchez");
   personas[0].estado = 1;
   personas[0].id =  1;


   strcpy(personas[1].patente,"Perez");
   personas[1].estado = 1;
   personas[1].id = 2;

   strcpy(personas[2].patente,"Gomez");
   personas[2].estado = 1;
   personas[2].id = 3;


   strcpy(personas[3].patente,"Gimenez");
   personas[3].estado = 1;
   personas[3].id =4;

   strcpy(personas[4].patente,"Robled");
   personas[4].estado = 1;
   personas[4].id = 5;

   strcpy(personas[5].patente,"Rodriguez");
   personas[5].estado = 1;
   personas[5].id = 6;

   strcpy(personas[6].patente,"Gonzalez");
   personas[6].estado = 1;
   personas[6].id = 7;
}


int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}
