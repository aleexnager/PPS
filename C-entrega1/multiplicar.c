#include <stdio.h>
#include <stdlib.h>
#define LEN 64

int main(int argc, char *argv[])
{
    int i, j, k;
    int m = 1; /* int positivo representa filas 1 matriz */
    int n = 1; /* int positivo representa columnas 1 matriz (coincide con num filas 2 matriz)*/
    int p = 1; /* int positivo representa columnas 2 matriz */
    int aux = m;
    int m1[LEN][LEN], m2[LEN][LEN], mRes[LEN][LEN];
    (void)argc;

    /*Declaracion de variables y comprobacion de que el fichero se abre correctamente*/
    if (argv[2] == NULL)
    {
        printf("No se pudo abrir el fichero\n");
        printf("Formato esperado: ./multiplicar.c < fich.txt\n");
        exit(1);
    }

    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &p);

    /*guardamos la matriz 1*/
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    /*guardamos la matriz 2*/
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < p; ++j)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    /*multiplicamos las matrices*/
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < p; ++j)
        {
            mRes[i][j] = 0;
            for (k = 0; k < n; ++k)
            {
                mRes[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    /*imprimimos la matriz resultado*/
    aux = m;
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < p; ++j)
        {   
            aux--;
            if (aux == 0)
            {
                printf("%d\n", mRes[i][j]);
            }
            else
            {
                printf("%d ", mRes[i][j]);
            }
        }
        aux = m;
    }

    return 0;
}
