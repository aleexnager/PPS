#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ec2g.h"

int resolver(double a, double b, double c, double *px1, double *px2)
{
    int aux = b * b - 4 * a * c;
    if (aux != 0 && a == 0)
    {
        /*caso 4*/
        *px1 = -c / b;
        *px2 = sqrt(-1.0);
        printf("Caso 3: ");
        return 4;
    }
    else if (a == 0 && b == 0)
    {
        /*caso 3*/
        *px1 = *px2 = 0;
        printf("Caso 3: ");
        return 3;
    }
    else if (aux < 0)
    {
        /*caso 2*/
        *px1 = -b / (2 * a); /*parte real*/
        *px2 = fabs(sqrt(-aux) / (2 * a)); /*parte imaginaria*/ /*fabs es una func de stdlib.h que devuelve el valor abs de float o double*/
        printf("Caso 2: ");
        return 2;
    }
    else
    {
        /*caso 1*/
        *px1 = (-b + (sqrt(aux))) / (2 * a);
        *px2 = (-b - (sqrt(aux))) / (2 * a);
        printf("Caso 1: ");
        return 1;
    }
    exit(0);
}
