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
################################################################################
#Inicio de ejecucion de Consultas en KDTree:
#Test_01
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#01: Todas las formaciones que tienen falla $idFalla. #(0,*,10,0,0)
../kdtree -q "--formacion --falla=$idFalla"
continuar_siguienteTest

#Test_02
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#02: Todas las formaciones que tienen accidente $idAccidente.
../kdtree -q "--formacion --accidente=$idAccidente"
continuar_siguienteTest

#Test_03
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#03: Todas las fallas que tienen formacion $idFormacion.
../kdtree -q "--falla --formacion=$idFormacion" 
continuar_siguienteTest

#Test_04
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#04: Todos los accidentes que tienen formacion $idFormacion.
../kdtree -q "--accidente --formacion=$idFormacion"
continuar_siguienteTest

#Test_05
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#05: Todas las fallas
../kdtree -q "--falla"
continuar_siguienteTest

#Test_06
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#06: Todas las formaciones.
../kdtree -q "--formacion"
continuar_siguienteTest

#Test_07
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#07: Todas las lineas.
../kdtree -q "--linea"
continuar_siguienteTest

#Test_08
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#08: Todas los accidentes.
../kdtree -q "--accidente"
#
eliminar_arbolKDTree
#final script


