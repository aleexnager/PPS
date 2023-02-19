#include <stdio.h>

int main(int argc, char * argv[])
{   
    FILE * fp = fopen(argv[1], "r");
    float max = 0.00;
    float min = 0.00;
    float aux;
    int x = 0;
    char c;
    (void)argc;

    /*comprobamos que hay archivo para leer*/
    if (argv[1] == NULL) return -1;

    /*probamos a abrir el archivo*/
    if (fp == NULL) return -1;

    /*miramos si está vacio archivo vacio*/
    c = fgetc(fp);
    if (c == EOF)
    {   
        printf("%10.2f%10.2f\n", max, min);
        return 0;
    }

    rewind(fp);
    /*leer de un fichero y coger el numero maximo y minimo*/
    while (fscanf(fp, "%f", &aux) != EOF)
    {   
        if (x == 0) /*inicializamos ambas variables al primer real del fich*/
        {
            max = aux;
            min = aux;
            ++x;
        }
        if (max < aux) max = aux;
        if (aux < min) min = aux;
    }

    printf("%10.2f%10.2f\n", max, min);
    fclose(fp);

    return 0;
}