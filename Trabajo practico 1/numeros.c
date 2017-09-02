#include <stdio.h>
#include "numeros.h"

float sumar(float num1, float num2)
{
    float resultado;
    resultado = num1 + num2;

    return resultado;
}

float restar(float num1, float num2)
{
    float resultado;
    resultado = num1 - num2;

    return resultado;
}

float dividir(float num1, float num2)
{
    float resultado;
    while (num2 == 0)
    {
        printf("ERROR!!! Ingrese un numero diferente a cero");
        scanf("%f",&num2);
    }

    resultado = num1 / num2;

    return resultado;
}

float multiplicar(float num1, float num2)
{
    float resultado;

    resultado = num1 * num2;

    return resultado;
}

long long int  factorial (float num)
{
    long long int acumulador = 1;
    float i = num;

    for (i=num;i>0;i--)
    {
        acumulador  = acumulador * i;
    }

    return acumulador;
}
