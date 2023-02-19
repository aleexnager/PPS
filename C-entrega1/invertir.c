#include <stdio.h>
#include <stdlib.h>
#define M 1000

int main(int argc, char *argv[])
{
    /*Declaracion de variables y comprobacion de que el fichero se abre correctamente*/
    int i, length, a[M];
    char c;
    (void)argc;

    if (argv[2] == NULL)
    {
        printf("No se pudo abrir el fichero\n");
        printf("Formato esperado: ./invertir.c < fich.txt\n");
        exit(1);
    }

    /*Obtención de los numeros, formato e inversion de las cadenas*/
    length = 1;
    while ((c = getc(stdin)) != EOF)
    {
        /*Comprobamos que inicia en numero*/
        if (c >= '0' && c <= '9')
        {
            a[0] = c - '0';
        }
        else
        {
            length = 0;
        }
        /*Obtenemos numeros (siendo como max M)*/
        for (i = 0; i < M; ++i)
        {
            if (scanf("%d", &a[length]) == 1)
            {
                length++;
            }
        }
        /*Inversion*/
        for (i = length - 1; i >= 0; --i)
        {
            if (i == 0){
                printf("%d\n", a[i]);
            } 
            else
            {
                printf("%d ", a[i]);
            }
        }
        length = 0;
    }
    return 0;
}
