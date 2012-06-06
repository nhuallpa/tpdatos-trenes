#!/bin/bash
function eliminar_arbolKDTree
{
    rm datos.tree -f
    rm datos.tree.fs -f
}
################################################################################
eliminar_arbolKDTree
#Variables para probar las consultas:
idLinea=1
idFormacion=3
idFalla=10
idAccidente=15
franjaHoraria="2012030112001300" #(12:00-13:00-01/03/2012)
fechaDesde="2012030113001300" #(13:00-13:00-01/03/2012)
fechaHasta="2012090121002100" #(21:00-21:00-01/09/2012)
################################################################################
echo "Estructura de entrada_reporte: (idLinea,idFormacion,idFalla,idAccidente,franjaHoraria)"    
echo Test#01: Todas las formaciones que tienen falla $idFalla.
../kdtree -q "--formacion --falla=$idFalla"

#
eliminar_arbolKDTree
#final script


