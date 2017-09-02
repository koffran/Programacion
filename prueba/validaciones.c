#include "validaciones.h"

float validaDivision (float numero)
{
   while (numero == 0)
    {
    printf("ERROR!!! Ingrese un numero diferente a cero");
    scanf("%f",&numero);
    }
    return numero;
}


int validaFactorial (float numero)
{
    int i = numero;
    float resta = numero - i;

    while (resta != 0)
    {
        int i = numero;
        printf("Error!!! Ingrese un numero entero");
        scanf("%f", &numero);
    }

    return i;
}
