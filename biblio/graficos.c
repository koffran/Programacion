#include "graficos.h"
#include <stdio.h>

void mostrarGrafico (eEstructura lista[],int tam)
{
    int i, cont1=0, cont2=0, cont3=0;
    int flag1=0, flag2=0;
    int mayor;

    for (i=0;i<tam;i++)
    {
        if (lista[i].estado ==1)
        {
            if (lista[i].dato < 19) //VERIFICAR DATO
            {
                cont1++;
            }
            else
            {
                if (lista[i].dato >18 && lista[i].dato <36)
                {
                    cont2++;
                }
                else
                {
                    cont3++;
                }
            }
        }

    }

    if (cont1>= cont2 && cont1>=cont3)
    {
        mayor = cont1;
    }
    else
    {
        if (cont2>=cont1 && cont2>=cont3)
        {
            mayor=cont2;
        }
        else
        {
            if (cont3>= cont1 && cont3 >=cont2)
            {
                mayor = cont3;
            }
        }
    }

    for (i=mayor;i>0;i--)
    {
        if (i<=cont1)
        {
            printf("*");
            flag1=1;
        }
        if (i<=cont2)
        {
            printf("\t*");
            flag2=1;
        }
        if (i<=cont3)
        {
            if (flag2 == 0)
            {
                printf ("\t\t*");

            }
            else
            {
                printf("\t*");
            }
        }
    }
    printf ("<18\t19-35\t>35\n");
}

