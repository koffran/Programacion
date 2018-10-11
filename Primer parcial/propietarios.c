#include "propietarios.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int initePropietarios (ePropietario* clientes, int tam)
{
    int i,retorno = -1;

    if (clientes !=NULL)
    {
        for (i=0; i<tam; i++)
        {
            clientes[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int obtenerEspacioLibre(ePropietario lista[],int tam)
{
    int indice = -1,i;
    for (i=0; i<tam; i++)
    {
        if (lista[i].isEmpty ==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int findePropietarioByid_propietario(ePropietario* lista, int id_propietario,int tam)
{
    int i,indice = -1;
    for (i=0; i<tam; i++)
    {
        if (id_propietario == lista[i].id_propietario && lista[i].isEmpty == 1)
        {
            indice = i;
        }
    }
    return indice;
}

void altaPropietario (ePropietario* lista, int i)
{
    char name [51],lastName[51],direccion[51];
    long long int tarjeta;
    int id_propietario;

    printf("ingrese el nombre: \n");
    fflush(stdin);
    gets(name);

    printf("ingrese el apellido: \n");
    fflush(stdin);
    gets(lastName);

    printf("ingrese el direccion: \n");
    fflush(stdin);
    gets(direccion);

    printf("Ingrese el numero de tarjeta de 16 digitos:\n");
    scanf("%lld",&tarjeta);
    while(tarjeta < 1000000000000000 || tarjeta >9999999999999999)
    {
        printf("\nERROR! Ingrese el numero de tarjeta de 16 digitos:\n");
        scanf("%lld",&tarjeta);
    }

    id_propietario = i+1;

   if (addePropietarios(lista,i,id_propietario,name,lastName,tarjeta,direccion)==0)
   {
       printf("Empleado cargado\n");
   }

}

int addePropietarios(ePropietario* list, int indice, int id_propietario, char name[],char lastName[],long long int tarjeta,char direccion[])
{
     int returnAux = -1;

    if(list != NULL)
    {
        list[indice].id_propietario = id_propietario;
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        strcpy(list[indice].direccion,direccion);
        list[indice].numeroTarjeta = tarjeta;
        list[indice].isEmpty = 1;
        returnAux = 0;
    }
    return returnAux;
}

void removeePropietario (ePropietario* lista, int len,int id_propietario)
{
    char rta;
    int indice;

    indice = findePropietarioByid_propietario(lista,id_propietario,len);

    if (indice == -1)
    {
         printf("No se encontro el id_propietario ingresado\n");
    }
    else
    {
        if (lista[indice].isEmpty == 1)
            {
                printf("Nombre\tid_propietario\n %s\t \t %d\n",lista[indice].name,lista[indice].id_propietario);
                printf("Desea eliminarlo? <S/N>\n");
                fflush(stdin);
                rta = getche();
                rta = tolower(rta);

                if ( rta == 's')
                {
                    lista[indice].isEmpty = 0;
                    printf("\Cliente eliminado\n\n");
                }
            }
    }
}

void printePropietario(ePropietario* list, int i)
{
  if (list[i].isEmpty == 1)
  {
    printf("%s\t\t%5s\t\t%d\t\t%lld\n",list[i].lastName,list[i].name,list[i].id_propietario,list[i].numeroTarjeta);
  }
}

void printePropietarios(ePropietario* list, int length)
{
    int i;
    printf("Apellido\tNombre\tid_propietario\tNumero de tarjeta\n\n");
    for (i=0; i<length; i++)
    {
        printePropietario(list,i);
    }
}


int sortePropietarios (ePropietario* lista, int tam, int order)
{
    int i,j,retorno =-1;
    ePropietario aux;

    for (i=0; i<tam-1; i++)
    {
        if(lista[i].isEmpty ==1)
        {
            for (j=i+1; j<tam; j++)
            {
                if(lista[j].isEmpty ==1 && order == 1)
                {
                    if(strcmp(lista[i].lastName, lista[j].lastName)>0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    }
                }
                else
                {
                    if(lista[j].isEmpty ==1 && order == 0)
                {
                    if(strcmp(lista[i].lastName, lista[j].lastName)<0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0)
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

void modificar (ePropietario* lista, int tam, int id_propietario)
{
    int rta;
    int indice;
    char seguir = 's';
    long long int aux;
    char comprobar;

    indice = findePropietarioByid_propietario(lista,id_propietario,tam);

    if (indice == -1)
    {
         printf("No se encontro el id_propietario ingresado\n");
    }
    else
    {
        if (lista[indice].isEmpty == 1)
            {
                while (seguir == 's')
                {
                    system("cls");
                    printf("Apellido\tNombre\tid_propietario\tNumero de tarjeta\n");
                    printePropietario(lista,indice);

                    printf("\n1- Cambiar numero de tarjeta\n2- Salir\n");
                    scanf("%d",&rta);
                    switch (rta)
                    {
                    case 1:
                        printf("Ingrese el nuevo numero de tarjeta\n");
                        //scanf("%lld",&lista[indice].numeroTarjeta);
                        scanf("%lld",&aux);
                        while(aux< 1000000000000000 || aux >9999999999999999)
                        {
                            printf("\nERROR! Ingrese el numero de tarjeta de 16 digitos:\n");
                            scanf("%lld",&aux);
                           // scanf("%lld",&lista[indice].numeroTarjeta);
                        }
                            printf("El nuevo numero es: %lld\n es correcto? <s/n>",aux);
                            fflush(stdin);
                            scanf("%c",&comprobar);
                            if (comprobar == 's')
                            {
                                lista[indice].numeroTarjeta = aux;
                            }
                            else
                            {
                                printf("Cambio no realizado");
                            }
                        system("pause");
                        break;
                    case 2:
                        seguir = 'n';
                        break;
                    default:
                        printf("Ingrese una opcion valid_propietarioa <1-2>");
                        system("pause");
                    }
                }
            }
    }
}



void hardcodeo (ePropietario personas[])
{
   strcpy(personas[0].name,"Juan");
   strcpy(personas[0].lastName,"Sanchez");
   strcpy(personas[0].direccion,"Direccion 1");
   personas[0].numeroTarjeta = 1000100010001000;
   personas[0].id_propietario =  1;
   personas[0].isEmpty = 1;


    strcpy(personas[1].direccion,"Direccion 7");
   personas[1].numeroTarjeta = 1007100710071007;
   strcpy(personas[1].name,"Paula");
   strcpy(personas[1].lastName,"Perez");
   personas[1].isEmpty = 1;
   personas[1].id_propietario = 2;

    strcpy(personas[2].direccion,"Direccion 2");
   personas[2].numeroTarjeta = 1002100210021002;
   strcpy(personas[2].name,"Pablo");
   strcpy(personas[2].lastName,"Gomez");
   personas[2].isEmpty = 1;
   personas[2].id_propietario = 3;

strcpy(personas[3].direccion,"Direccion 3");
   personas[3].numeroTarjeta = 1003100310031003;
   strcpy(personas[3].name,"Micaela");
   strcpy(personas[3].lastName,"Gimenez");
   personas[3].isEmpty = 1;
   personas[3].id_propietario =4;

    strcpy(personas[4].direccion,"Direccion 4");
   personas[4].numeroTarjeta = 1004100410041004;
   strcpy(personas[4].name,"German");
   strcpy(personas[4].lastName,"Robled");
   personas[4].isEmpty = 1;
   personas[4].id_propietario = 5;

   strcpy(personas[5].direccion,"Direccion 5");
   personas[5].numeroTarjeta = 1005100510051005;
   strcpy(personas[5].name,"Esteban");
   strcpy(personas[5].lastName,"Carl");
   personas[5].isEmpty = 1;
   personas[5].id_propietario = 6;

   strcpy(personas[6].direccion,"Direccion 6");
   personas[6].numeroTarjeta = 1006100610061006;
   strcpy(personas[6].name,"Cecilia");
   strcpy(personas[6].lastName,"Marco");
   personas[6].isEmpty = 1;
   personas[6].id_propietario = 7;
}

int menu()
{
    int opcion;
    printf("1- Alta de cliente\n2- Modificar cliente\n3- Baja de cliente\n4- MOSTRAR CLIENTES\n5- Alta auto  \n6-Retirar auto  \n7-  \n8-  \n9-  \n10-Mostrar estacionados \n11- Hardcodeo\n12- Salir\n");
    scanf("%d",&opcion);
    return opcion;
}
