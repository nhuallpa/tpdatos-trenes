rm datos.tree -f
rm datos.tree.fs -f
echo
#Test/test_consultas.sh
#
#Objetivos:
#obtener las siguientes filtraciones
#01) Todos las formaciones que tiene cierta falla.
#02) Todos las formaciones que tiene cierto accidente.
#03) Todas las fallas de una formación determinada.
#04) Todos los accidentes de una formación determinada.
#05) Todas las fallas.
#06) Todas las formaciones.
#07) Todas las lineas.
#08) Todos los accidentes.
#09) Todos las formaciones que tiene cierta falla  que ocurrieron dentro de una franja horaria.
#10) Todos las formaciones que tiene cierto accidente que ocurrieron dentro de una franja horaria.
#11) Todas las fallas de una formación determinada que ocurrieron dentro de una franja horaria.
#12) Todos los accidentes de una formación determinada que ocurrieron dentro de una franja horaria.
#
#Representación en formato de comando unix:
#-o: outputFilter
#’X’: indica que devuelve todo lo correspondiente al campo en e cual esta ‘X’
idFalla=1
idAccidente=2
idFormacion=2

#ESCAPEO CON LA CONTRABA BARRA
fechaDesde=09\:00-04\/03\/2012 
fechaHasta=09\:00-04\/03\/2012

#01) ../kdtree -q '(,,$idFalla,,)' -o ‘formacion’
#02) ../kdtree -q '(,,,$idAccidente,)' -o ‘formacion’
#03) ../kdtree -q '(,$idFormacion,,,)' -o ‘falla’
#04) ../kdtree -q '(,$idFormacion,,,)' -o‘ accidente’
#05) ../kdtree -q '(,,X,,)'
#06) ../kdtree -q '(,,,X,)'
#07) ../kdtree -q '(,X,,,)'
#08) ../kdtree -q '(,X,,,)'
#09)  ../kdtree -q '(,,’$idFalla’,,)'  -o ‘formacion’ -f  $fechaDesde $fechaHasta
#10)  ../kdtree -q '(,,,$idAccidente,)'  -o ‘formacion’ -f  $fechaDesde $fechaHasta
#11)  ../kdtree -q '(,’$idFormacion’,,,)'  -o fallas -f  $fechaDesde $fechaHasta
#12)  ../kdtree -q '(,,’$idFalla’,,)'  -o accidentes -f  $fechaDesde $fechaHasta

echo pruebas de las consultas
echo -------------------------------------------------------------------------------------------------
echo -------------------------------------------------------------------------------------------------
rm datos.tree -f
rm datos.tree.fs -f
echo PRUEBA1: 
# comando...
echo 
echo Presione enter para continuar...
read
rm datos.tree -f
rm datos.tree.fs -f
#
#fin del script
