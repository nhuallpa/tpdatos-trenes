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

int main(int argc, char** argv){
	cout<<"INTERFAZ DE USUARIO::"<<endl;
    //interfaz de usuario para operar elementos de manera unitaria
	KDTreeController kdTreeController;
	Menu* menu_principal     = new MenuPrincipal(kdTreeController);
	// TODO este metodo deberia devolver una "operacion" a trabajar.
	menu_principal->iniciar();

	return 0;
}
