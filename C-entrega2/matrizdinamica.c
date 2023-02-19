#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /*Variables*/
    int m, p, i, j;
    long int **matriz;
    (void)argc;

    m = atoi(argv[1]); /*num filas*/
    p = atoi(argv[2]); /*num columnas*/

    /*Memoria dinamica*/
    matriz = (long int **)calloc(m, sizeof(long int));
    if (matriz == NULL) exit(71);
    for (i = 0; i < m; ++i)
    {
        matriz[i] = (long int *)calloc(p, sizeof(long int));
        if (matriz[i] == NULL) exit(71);
    }

    /*Asignacion valores*/
    for (i = 0; i < m; ++i)
        for (j = 0; j < p; ++j)
        {
            matriz[i][j] = (i == 0 || j == 0) ? 1 : matriz[i - 1][j] + matriz[i][j - 1];
            (j == p-1) ? printf("%li\n", matriz[i][j]) : printf("%li\t", matriz[i][j]); /*para ultimo elem : para el resto de elem*/
        }

    /*Liberacion menoria dinamica*/
    for (i = 0; i < m; ++i)
        free(matriz[i]);
    free(matriz);

    exit(0);
}
