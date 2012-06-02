rm datos.tree -f
rm datos.tree.fs -f
echo
#Test/testSimple_consultas.sh
################################################################################
#Estructura de Reporte es: idLinea|idFormacion|idFalla|idAccidente|franjaHoraria
################################################################################
#los pararametros de consulta posibles son:
#lineas, formacion, falla, accidente, fechaDesde, fechaHasta
################################################################################
#valores utilizados en los comandos(recursos):
idLinea=1
idFormacion=1
idFalla=1
idAccidente=1
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
echo
echo Test#01: Todas las formaciones que tienen falla $idFalla.
../kdtree -q "--formacion --falla=$idFalla"
continuarCon

rm datos.tree -f
rm datos.tree.fs -f

