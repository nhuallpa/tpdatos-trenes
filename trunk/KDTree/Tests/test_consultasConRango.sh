#!/bin/bash

################################################################################
function continuar_siguienteTest
{
	echo Presione enter para continuar con el Test
	read
	clear
}

function mostrar_estructuraReporte
{
    echo "Estructura de entrada_reporte: (idLinea,idFormacion,idFalla,idAccidente,franjaHoraria)"    
}

function eliminar_arbolKDTree
{
    rm datos.tree -f
    rm datos.tree.fs -f
}
################################################################################
eliminar_arbolKDTree
#Variables para probar las consultas:
mostrarEstructuraReporte="si" #si o no
idLinea=1
idFormacion=3
idFalla=10
idAccidente=15
fechaDesde="20120301" #(01/03/2012)
fechaHasta="20120901" #(01/09/2012)
################################################################################
#Inicio de ejecucion de Consultas en KDTree:
#Test_09
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#09: Todas las formaciones que tienen falla $idFalla que ocurrieron desde $fechaDesde hasta $fechaHasta.
#(0,*,10,0,2012030113001300-2012090121002100)
../kdtree -q "--formacion --falla=$idFalla --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"
continuar_siguienteTest

#Test_10
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#10: Todas las formaciones que tienen accidente $idAccidente que ocurrieron desde $fechaDesde hasta $fechaHasta.
../kdtree -q "--formacion --accidente=$idAccidente --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"
continuar_siguienteTest

#Test_11
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#11: Todas las fallas que tienen formacion $idFormacion que ocurrieron desde $fechaDesde hasta $fechaHasta.
../kdtree -q "--falla --formacion=$idFormacion --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"
continuar_siguienteTest

#Test_12
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#12: Todos los accidentes que tienen formacion $idFormacion que ocurrieron desde $fechaDesde hasta $fechaHasta.
../kdtree -q "--accidente --formacion=$idFormacion --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"

eliminar_arbolKDTree


