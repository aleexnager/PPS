#!/bin/bash

#comprobar si los argumentos de la entrada estandar son != 1.
if test $# -ne 1; then
    echo "Se le debe llamar con 1 argumento" 1>&2
    exit 255;
fi;

#comprobar que se puede leer el fich de config
if test ! -r $1; then
    echo "El fichero de configuracion no es accesible" 1>&2  
    exit 255;
fi;

DIR=$1
case $DIR in
  /*) #echo "PATH ABSOLUTO"
    source $1;;
  *) #echo "PATH RELATIVO"
    source $(pwd)/$1;;
esac

#comprobar que todos los ficheros se pueden leer
for file in $LISTA; do
   if test ! -f $file; then
      echo "El fichero "$file" no se puede leer" 1>&2        
      exit 255;
   fi;
done

cp -u $LISTA $DESTINO

exit 0
