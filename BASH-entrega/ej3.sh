#!/bin/bash

dir1=$1
dir2=$2
aux=0

# Comprobar si los argumentos son válidos
if [ ! -d "$dir1" ] || [ ! -d "$dir2" ]; then
    echo "Error: argumentos no son directorios válidos" >&2
    exit 255
fi

# Recorrer los archivos en cada directorio
for file1 in "$dir1"/*; do
    if [ -f "$file1" ] && [ ! -h "$file1" ]; then
        file2="$dir2/$(basename "$file1")"
        if [ -f "$file2" ] && [ ! -h "$file2" ]; then
            # Comparar los archivos si existen en ambos directorios
            diff "$file1" "$file2" >/dev/null
            if [ $? -ne 0 ]; then
                echo "Los ficheros \"$(basename "$file1")\" de \"$dir1\" y \"$dir2\" no son iguales" >&2
                aux=255
            fi
        else
            echo "El fichero \"$(basename "$file1")\" de \"$dir1\" no es un \"regular file\" de \"$dir2\"" >&2
            aux=255
        fi
    fi
done

# Recorrer los archivos en el segundo directorio
for file2 in "$dir2"/*; do
    if [ -f "$file2" ] && [ ! -h "$file2" ]; then
        file1="$dir1/$(basename "$file2")"
        if [ ! -f "$file1" ] && [ ! -h "$file1" ]; then
            echo "El fichero \"$(basename "$file2")\" de \"$dir2\" no es un \"regular file\" de \"$dir1\"" >&2
            aux=255
        fi
    fi
done

exit $aux
