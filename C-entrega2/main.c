#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int main(int argc, char *argv[])
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
}