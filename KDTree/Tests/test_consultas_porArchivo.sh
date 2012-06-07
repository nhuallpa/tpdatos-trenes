#elimino el arbol(preguntar a Sergio...)
rm datos.tree -f
rm datos.tree.fs -f
#cargo el arbol con los supuestos nodos que estan en el archivo 'insercion2'
../kdtree -c insercion2
#se inician las consultas puntuales(casos felices). todo: ver que los resultado sean los correctos
echo -------------------------------------------------------------------------------------------------
echo -------------------------------------------------------------------------------------------------
echo PRUEBA1: el nodo se encuentra en el arbol
echo
../kdtree -v 
../kdtree -q "(1,4,4,8,2012030113001500)" 
echo 
echo Presione enter para continuar...
read

echo -------------------------------------------------------------------------------------------------
echo -------------------------------------------------------------------------------------------------
echo PRUEBA2: el nodo se encuentra en el arbol
echo
../kdtree -v 
../kdtree -q "(5,3,1,2,2012030416001800)" 
echo 
echo Presione enter para continuar...
read

echo -------------------------------------------------------------------------------------------------
echo -------------------------------------------------------------------------------------------------
echo PRUEBA3: el nodo se encuentra en el arbol
echo
../kdtree -v 
../kdtree -q "(6,2,2,5,2012030416001800)" 
echo 
echo Presione enter para continuar...
read
