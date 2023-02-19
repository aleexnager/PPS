#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int parser(FILE *file)
{
    int i, nCampos = 0;
    char linea[MaxLinea];
    char linea2[MaxLinea];
    char *campos[MaxCampos];
    char *palabras[MaxCampos];
    char *tok;
    char c = '\n';

    /*comprobamos fichero*/
    if (file == NULL)
    {
        fprintf(stderr, "Error al abrir fichero\n");
        return -1;
    }

    /*contamos numero campos*/
    fgets(linea, MaxLinea, file);
    linea[strcspn(linea, "\n")] = 0; /*eliminamos el salto de linea*/
    tok = strtok(linea, ",");
    i = 0;
    while (tok != NULL)
    {
        campos[i] = tok;
        nCampos++;
        i++;
        tok = strtok(NULL, ",");
    }

    /*comprobamos que nCampos sea correcto*/
    if (nCampos > MaxCampos)
    {
        fprintf(stderr, "Error en el formato\n");
        return -1;
    }

    /*imprimimos el resto de lineas*/
    while (fgets(linea2, MaxLinea, file))
    {
        linea2[strcspn(linea2, "\n")] = 0;
        if (linea2[0] != c) /*solo entramos si hay contenido en la linea*/
        {
            tok = strtok(linea2, ",");
            i = 0;
            while (tok != NULL)
            {
                palabras[i] = tok;
                if (i < nCampos - 1)
                    printf("%s: %s; ", campos[i], palabras[i]); /*formato elems*/
                else
                    printf("%s: %s\n", campos[i], palabras[i]); /*formato para ultimo elem*/
                i++;
                tok = strtok(NULL, ",");
            }
        }
    }
    
    return 0;
}

/*
opcion de compilar descomentando este main: 
1.    gcc -Wall -Werror -Wextra -ansi -pedantic -o parser paser.c
2.    ./parser.exe csv.txt
*/
/*int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    (void)argc;
    if (fp == NULL)
    {
        printf("Error al abrir fichero\n");
        return 1;
    }
    parser(fp);
    fclose(fp);
    return 0;
}*/
