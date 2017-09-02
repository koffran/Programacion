#include <stdio.h>
#include <stdlib.h>
#include "numeros.h"

int main()
{
    char seguir='s';
    int opcion=0;

    float numero1;
    float numero2;
    float resultado;
    long long int resultadoFact;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%f)\n",numero1);
        printf("2- Ingresar 2do operando (B=%f)\n",numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\tingrese un numero:");
                scanf("\t%f",&numero1);
                break;
            case 2:
                printf("\tingrese otro numero:");
                scanf("\t%f",&numero2);
                break;
            case 3:
                resultado = sumar(numero1,numero2);
                printf("El resultado de la suma es: %f\n",resultado);
                break;
            case 4:
                resultado = restar(numero1,numero2);
                printf("El resultado de la resta es: %f\n",resultado);
                break;
            case 5:
                resultado = dividir(numero1,numero2);
                printf("El resultado de la division es: %f\n",resultado);
                break;
            case 6:
                resultado = multiplicar(numero1,numero2);
                printf("El resultado de la multiplicacion es: %f\n",resultado);
                break;
            case 7:
                resultadoFact = factorial(numero1);
                printf("El resultado del factorial es: %lld \n,",resultadoFact);

                break;
            case 8:
                resultado = sumar(numero1,numero2);
                printf("El resultado de la suma es: %f\n",resultado);
                resultado = restar(numero1,numero2);
                printf("El resultado de la resta es: %f\n",resultado);
                resultado = dividir(numero1,numero2);
                printf("El resultado de la division es: %f\n",resultado);
                resultado = multiplicar(numero1,numero2);
                printf("El resultado de la multiplicacion es: %f\n",resultado);
                resultado = factorial(numero1);
                printf("El resultado del factorial es: %f\n",resultado);
                break;
            case 9:
                seguir = 'n';
                break;


        }

}
    return 0;
}
