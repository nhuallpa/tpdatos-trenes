#!/bin/bash
################################################################################
#                                                                              #
#       Organizacion de Datos 75.06                                            #
#       Nombre: test_consultas.sh                                              #
#       Descripcion: prueba las operaciones de consultas en el arbol KDTree    #
#                                                                              #
################################################################################


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
franjaHoraria="2012030112001300" #(12:00-13:00-01/03/2012)
fechaDesde="2012030113001300" #(13:00-13:00-01/03/2012)
fechaHasta="2012090121002100" #(21:00-21:00-01/09/2012)
################################################################################
#Inicio de ejecucion de Consultas en KDTree:
#Test_01
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#01: Todas las formaciones que tienen falla $idFalla.
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
continuar_siguienteTest

#Test_09
if [ $mostrarEstructuraReporte == "si" ] ; then
    mostrar_estructuraReporte
fi
echo Test#09: Todas las formaciones que tienen falla $idFalla que ocurrieron desde $fechaDesde hasta $fechaHasta.
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


