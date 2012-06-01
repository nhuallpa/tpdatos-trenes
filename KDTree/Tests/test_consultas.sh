rm datos.tree -f
rm datos.tree.fs -f
echo
#Test/test_consultas.sh

#Estructura de Reporte es:
#idLinea;
#idFormacion;
#idFalla;
#idAccidente;
#FranjaHoraria* franjaHoraria;

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

################################################################################
#formato de la consulta:
#Programa -q "--[parametro de consulta] --[parametro de consulta]=[valor de parametro]"
#
#los pararametros de consulta posibles son:
#lines, formacion, falla, accidente, fechaDesde, fechaHasta
#
################################################################################
#valores posibles para los parametros en cuestion:
idFalla=1
idAccidente=1
idFormacion=1
#ESCAPEO CON LA CONTRABA BARRA
fechaDesde="2012030113001300" #(13:00-13:00-01/03/2012)
fechaHasta="2012090121002100" #(21:00-21:00-01/09/2012)

#ejemplos de corrida de los comandoS
#01) ../kdtree -q "--formacion --falla=$idFalla"
#02) ../kdtree -q "--formacion --accidente=$idFormacion"
#03) ../kdtree -q "--falla --formacion=$idFormacion"
#04) ../kdtree -q "--accidente --formacion=$idFormacion"
#05) ../kdtree -q "--falla"
#06) ../kdtree -q "--formacion"
#07) ../kdtree -q "--linea"
#08) ../kdtree -q "--accidente"
#09)  ../kdtree -q "--formacion --falla=$idFalla --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"
#10)  ../kdtree -q "--formacion --accidente=$idFormacion --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"
#11)  ../kdtree -q "--falla --formacion=$idFormacion --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"
#12)  ../kdtree -q "--accidente --formacion=$idFormacion --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"

echo pruebas de las consultas contra el KDTree
echo -------------------------------------------------------------------------------------------------
echo -------------------------------------------------------------------------------------------------
rm datos.tree -f
rm datos.tree.fs -f 
echo Test#09: Todos las formaciones que tiene cierta falla  que ocurrieron dentro de una franja horaria.
../kdtree -q "--formacion --falla=$idFalla --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"

#...
echo 
echo Presione enter para continuar...
read
echo Test#10: Todos las formaciones que tiene cierto accidente que ocurrieron dentro de una franja horaria.
echo TODO: seguir poniendo los casos de pruebas...
rm datos.tree -f
rm datos.tree.fs -f
#
#fin del script
