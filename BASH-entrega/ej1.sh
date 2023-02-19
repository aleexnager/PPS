#!/bin/bash

#comprobar si los argumentos de la entrada estandar son < 1.
if test $# -lt 1; then
    echo "Se le debe llamar con al menos un argumento" 1>&2 
    exit 255;
fi;

#comprobar que el dir DESTINO existe.
if test ! -d "$DESTINO"; then
    echo "\"${DESTINO}\" no es un directorio accesible" 1>&2
    exit 255;
fi;

#comprobar que todos los ficheros se pueden leer
for file in $@; do
    if test ! -r $file; then
        echo "No se pudo copiar el fichero \"${file}\"" 1>&2
    exit 255;
    else
        cp $file $DESTINO
    fi;
done

exit 0
