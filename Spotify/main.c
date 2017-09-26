#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TC 7
#define TI 5

int main()
{
    eCancion listaCanciones [TC];
    eInterprete listaInterpretes [TI];
    int i, opcion;
    eCancion aux[TC][50];

    for (i=0;i<TC;i++)
    {
        listaCanciones[i].estado = 0;
    }
     for (i=0;i<TI;i++)
    {
        listaInterpretes[i].estado = 0;
    }

    do
    {

        printf("1 - Inicializar canciones\n2 - Inicializar Interpretes\n3 - Listar Canciones\n4 - Listar Interpretes\n5 - Listar Canciones con interpretes\n6 - Listar canciones por interprete\n7 - Listar canciones estadounidenses\n8 - SALIR\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            inicializarCancion(listaCanciones,TC);
            break;
        case 2:
            inicializarInterprete(listaInterpretes,TI);
            break;
        case 3:
            listarCanciones (listaCanciones,TC);
            break;
        case 4:
            listarInterpretes (listaInterpretes,TI);
            break;
        case 5:
            listarCancionesConInterprete (listaCanciones, TC,listaInterpretes,TI);
            break;
        case 6:
            cancionesPorInterprete (listaCanciones,TC,listaInterpretes,TI);
            break;
        case 7:
            listarCancionesEstadounidenses (listaCanciones,TC,listaInterpretes,TI);
            break;
        case 8:
            break;
        default:
            printf("Ingrese una opcion valida\n");
            //scanf("%d", &opcion);
            break;
        }

    }while (opcion != 8);

    return 0;
}
