rm datos.tree -f
rm datos.tree.fs -f
#Test/test_consultas.sh
################################################################################
echo "Estructura de Reporte es: (idLinea,idFormacion,idFalla,idAccidente,franjaHoraria)"
################################################################################
#los pararametros de consulta posibles son:
#lineas, formacion, falla, accidente, fechaDesde, fechaHasta
################################################################################
#valores utilizados en los comandos(recursos):
idLinea=1
idFormacion=3
idFalla=10
idAccidente=15
franjaHoraria="2012030112001300" #(12:00-13:00-01/03/2012)
fechaDesde="2012030113001300" #(13:00-13:00-01/03/2012)
fechaHasta="2012090121002100" #(21:00-21:00-01/09/2012)

function continuarCon
{
	echo Presione enter para continuar con el Test
	read
	echo +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
################################################################################
echo Inicio de ejecucion de Consultas en KDTree:
	echo +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo Test#01: Todas las formaciones que tienen falla $idFalla.
../kdtree -q "--formacion --falla=$idFalla"
continuarCon

echo Test#02: Todas las formaciones que tienen accidente $idAccidente.
../kdtree -q "--formacion --accidente=$idAccidente"
continuarCon

echo Test#03: Todas las fallas que tienen formacion $idFormacion.
../kdtree -q "--falla --formacion=$idFormacion" 
continuarCon

echo Test#04: Todos los accidentes que tienen formacion $idFormacion.
../kdtree -q "--accidente --formacion=$idFormacion"
continuarCon

echo Test#05: Todas las fallas
../kdtree -q "--falla"
continuarCon

echo Test#06: Todas las formaciones.
../kdtree -q "--formacion"
continuarCon

echo Test#07: Todas las lineas.
../kdtree -q "--linea"
continuarCon

echo Test#08: Todas los accidentes.
../kdtree -q "--accidente"
continuarCon

echo Test#09: Todas las formaciones que tienen falla $idFalla que ocurrieron desde $fechaDesde hasta $fechaHasta.
../kdtree -q "--formacion --falla=$idFalla --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"
continuarCon

echo Test#10: Todas las formaciones que tienen accidente $idAccidente que ocurrieron desde $fechaDesde hasta $fechaHasta.
../kdtree -q "--formacion --accidente=$idAccidente --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"
continuarCon

echo Test#11: Todas las fallas que tienen formacion $idFormacion que ocurrieron desde $fechaDesde hasta $fechaHasta.
../kdtree -q "--falla --formacion=$idFormacion --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"
continuarCon

echo Test#12: Todos los accidentes que tienen formacion $idFormacion que ocurrieron desde $fechaDesde hasta $fechaHasta.
../kdtree -q "--accidente --formacion=$idFormacion --fechaDesde=$fechaDesde --fechaHasta=$fechaHasta"

rm datos.tree -f
rm datos.tree.fs -f


