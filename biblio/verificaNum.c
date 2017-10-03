#include <stdio.h>
#include "verificaNum.h"

float validaDivision (float numero)
{
    while (numero == 0)
    {
        printf ("ERROR!!! Ingrese un numero diferente a cero");
        scanf("%f",&numero);
    }
    return numero;
}

int validaFactorial (float numero)
{
    int aux = numero;
    float resta = numero - aux;

    while (resta !=0)
    {
        int aux = numero;
        printf ("ERROR!!! Ingrese un numero entero");
        scanf ("%f",&numero);
    }
    return aux;
}
