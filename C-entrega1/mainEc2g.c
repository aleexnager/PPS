#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ec2g.h"

int main(int argc, char *argv[])
{
    /*Declaracion de variables y comprobacion de que el fichero se abre correctamente*/
    int cont = 1;
    double a, b, c, px1, px2;
    (void)argc;

    /*Comprobacion de la llamada*/
    if (argv[2] == NULL)
    {
        printf("No se pudo abrir el fichero\n");
        printf("Formato esperado: ./mainEc2g.c < fich.txt\n");;
        exit(1);
    }

    while (!feof(stdin))
    {
        while (cont != 0)
        {
            scanf("%lf", &a);
            scanf("%lf", &b);
            scanf("%lf", &c);
            cont--;
        }
        cont = 1;
        resolver (a, b, c, &px1, &px2);
        printf("%lf, %lf\n", px1, px2);

    }
    return 0;
}
