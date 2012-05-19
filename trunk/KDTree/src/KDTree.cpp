//============================================================================
// Name        : KDTree.cpp
// Author      : sergio
// Version     :
// Copyright   : 
// Description : Desarrollo de KDTree
//============================================================================

#include "bplustree/BPlusTree.h"
#include "index/BPlussIStructureFactory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>

#include "utils/util_main.h"

#include "iu/Menu.h"
#include "iu/MenuPrincipal.h"
#include "horario/TestFranjaHoraria.h"
#include "Operacion.h"
#include "ManejadorDeOperacion.h"

void iniciartestFranajaHoraria(){
	//para testear la clase FranjaHoraria
	TestFranjaHoraria* testFranajaHoraria = new TestFranjaHoraria();
	testFranajaHoraria->iniciar();
}

int main(int argc, char** argv){

	KDTreeController kdTreeController;
	Menu* menu_principal = new MenuPrincipal(kdTreeController);
	menu_principal->iniciar();
	Operacion* operacion = new Operacion();
	operacion =  menu_principal->getOperacionElejida();

	//TODO el la visualizacion del menuAlta tiene que ser igual al de menuConsulta
	//Ejecuto la operacion elejida por el menu principal
	ManejadorDeOperacion* manejador = new ManejadorDeOperacion(operacion);
	manejador->iniciar();

	delete menu_principal;
	delete operacion;
	delete manejador;

//		iniciartestFranajaHoraria();

	return 0;
}
