rm datos.tree -f
rm datos.tree.fs -f
echo PRUEBA1: Dado el siguiente arbol, se van a ir eliminando registros
echo
../kdtree -c eliminacion1
../kdtree -v 
echo 
echo Presione enter para eliminar '(3,4,2,8,2012030113001500)'
read
../kdtree -r '(3,4,2,8,2012030113001500)'
../kdtree -v 
echo 
echo Presione enter para eliminar '(4,4,2,8,2012030416001800)'
read
../kdtree -r '(4,4,2,8,2012030416001800)'
../kdtree -v 
echo 
echo Presione enter para eliminar '(2,1,4,6,2012030113001500)'
read
../kdtree -r '(2,1,4,6,2012030113001500)'
../kdtree -v 
echo 
echo Presione enter para eliminar '(6,2,3,2,2012030416001800)'
read
../kdtree -r '(6,2,3,2,2012030416001800)'
../kdtree -v 
echo 
echo Presione enter para eliminar '(2,7,7,2,2012030113001500)'
read
../kdtree -r '(2,7,7,2,2012030113001500)'
../kdtree -v 
echo
echo Presione enter para finalizar ....
read
rm datos.tree -f
rm datos.tree.fs -f

