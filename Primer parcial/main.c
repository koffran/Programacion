#include <stdio.h>
#include <stdlib.h>
#include "propietarios.h"
#include "automovil.h"
#define CANT_PROP 20

int main()
{
    int opcion,flag=0,aux,indice,i,aux2;
    char seguir = 's';
    float auxFloat;

    ePropietario propietarios[CANT_PROP];
    initePropietarios(propietarios,CANT_PROP);

    eAutomovil autos[CANT_PROP];
    initeAutomovils(autos,CANT_PROP);

    while (seguir == 's')
    {
        system("cls");
        opcion = menu();

        switch (opcion)
        {
        case 1:
            system("cls");
            aux = obtenerEspacioLibre(propietarios,CANT_PROP);
            if (aux == -1)
            {
                printf("No hay espacio disponible");
            }
            else
            {
                altaPropietario(propietarios,aux);
                printf("El id_propietario es: %d\n\n",propietarios[aux].id_propietario);
            }
            flag = 1;
            system("pause");
            break;
        case 2:
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados\n\n");
            }
            else
            {
                printePropietarios(propietarios,CANT_PROP);

                printf("\nIngrese el id_propietario: ");
                scanf("%d",&aux);
                modificar(propietarios,CANT_PROP,aux);
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados\n\n");
            }
            else
            {
                printePropietarios(propietarios,CANT_PROP);

                printf("\nIngrese el id_propietario: ");
                scanf("%d",&aux);
                removeePropietario(propietarios,CANT_PROP,aux);
            }
            system("pause");
            break;
        case 4:
            system("cls");

            if (flag ==0)
            {
                printf("No hay clientes cargados\n\n");
            }
            else
            {
                sortePropietarios(propietarios,CANT_PROP,1);
                printePropietarios(propietarios,CANT_PROP);
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if (flag ==0)
            {
                printf("No hay clientes cargados");
            }
            else
            {
                aux = obtenerEspacioLibreAuto(autos,CANT_PROP);
                if (aux == -1)
                {
                    printf("No hay espacio disponible");
                }
                else
                {
                    printePropietarios(propietarios,CANT_PROP);
                    altaAutos(autos,aux);
                    printf("El ID es: %d\n\n",autos[aux].id);
                }
            }

            system("pause");
            break;
        case 6:
            system("cls");
            printeAutomovils(autos,CANT_PROP);

            printf("Introduzca el ID del auto a retirar: \n");
            scanf("%d",&aux);
            indice = findeAutomovilById(autos,aux,CANT_PROP);

            auxFloat = retirarAutos(autos,indice);
            aux2 = autos[indice].marca;

            for (i=0; i<CANT_PROP; i++)
            {
                if(autos[indice].propietario == propietarios[i].id_propietario)
                {
                    printf("El auto del propietario: %s %s\nLa patente: %s\n La marca es: ",propietarios[i].lastName,propietarios[i].name,autos[indice].patente);

                    switch(aux2)
                    {
                    case 1:
                        printf("ALPHA ROMEO");
                        break;
                    case 2:
                        printf("FERRARI");
                        break;
                    case 3:
                        printf("AUDI");
                        break;
                    case 4:
                        printf("OTRO");
                        break;
                    }
                    printf("\nEl valor de la estadia es: %.2f",auxFloat);
                }
            }
            system("pause");
            break;
        case 7:
            system("cls");

            break;
        case 8:
            system("cls");

            system("pause");
            break;
        case 9:
            system("cls");

            system("pause");
            break;
        case 10:
            system("cls");
            printeAutomovils(autos,CANT_PROP);

            system("pause");
            break;
        case 11:
            hardcodeo(propietarios);

            flag =1;
            break;
        case 12:
            system("cls");
            seguir = 'n';
            system("pause");
            break;
        default:
            printf("\nIngrese una opcion valid_propietarioa <1-12>\n");
            system("pause");
        }
    }


    return 0;
}
