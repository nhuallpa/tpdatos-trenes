#!/bin/bash

rm datos.tree -f
rm datos.tree.fs -f

#cargo un nuevo arbol para hacerle las consultas, y luego ver los resultados esperables

../kdtree -c insercion2
../kdtree -v
#esta consulta pide totas las formaciones de la linea 4
#devuelve el Nodo 1
../kdtree -q "(4,*,0,0,0)"  #"(4,*,0,0,20120101-20120601)" #"(4,*,0,0,0)" #2012030113001500