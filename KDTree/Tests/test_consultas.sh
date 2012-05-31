rm datos.tree -f
rm datos.tree.fs -f
echo PRUEBA1: Inserción de los elementos del archivo insercion1, el nodo raiz tiene espacio suficiente para almacenarlos.
echo
../kdtree -c insercion1
../kdtree -v 
echo 
echo Presione enter para continuar...
read
rm datos.tree -f
rm datos.tree.fs -f

echo -------------------------------------------------------------------------------------------------
echo -------------------------------------------------------------------------------------------------
echo PRUEBA2: Inserción de los elementos del archivo insercion2, el nodo raiz se llena y se produce un overflow

echo
../kdtree -c insercion2
../kdtree -v 
echo 
echo Presione enter para continuar...
read
rm datos.tree -f
rm datos.tree.fs -f
echo -------------------------------------------------------------------------------------------------
echo -------------------------------------------------------------------------------------------------
echo PRUEBA2: Inserción de los elementos del archivo insercion3, el nodo raiz se llena y se produce dos overflow

echo
../kdtree -c insercion3
../kdtree -v 
echo 
echo Presione enter para continuar...
read
rm datos.tree -f
rm datos.tree.fs -f

