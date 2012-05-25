//============================================================================
// Name        : KDTree.cpp
// Author      : sergio
// Version     :
// Copyright   : 
// Description : Desarrollo de KDTree
//============================================================================

#include "bplustree/BPlusTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include <fstream>
#include <string>

#include "utils/util_main.h"

#include "iu/Menu.h"
#include "iu/MenuPrincipal.h"
#include "horario/TestFranjaHoraria.h"
#include "Operacion.h"
#include "ManejadorDeOperacion.h"

using std::cout;
using std::endl;
using std::ios;
using std::ifstream;
using std::string;

void iniciartestFranajaHoraria(){
	//para testear la clase FranjaHoraria
	TestFranjaHoraria* testFranajaHoraria = new TestFranjaHoraria();
	testFranajaHoraria->iniciar();
}


const char* nombre_programa = "KDTree";

void imprime_uso() {
	cout<<"Uso: "<<nombre_programa<<" opciones [ argumentos ...] \n"<<endl;
    cout<<"    Opciones                    Comentarios"<<endl;
    cout<<"    ---------------             -------------------"<<endl;
    cout<<"    -h  --help                  Enseña esta ayuda\n"<<endl;
    cout<<"    -i  --interfaxe             Modo interfase con usuario\n"<<endl;
    cout<<"    -c  --carga                 Recibe como argumento un archivo para carga masiva\n"<<endl;
}

void iniciarInterfase() {
//	KDTreeController kdTreeController;
//	Menu* menu_principal = new MenuPrincipal(kdTreeController);
//	menu_principal->iniciar();
//	Operacion* operacion = new Operacion();
//	operacion =  menu_principal->getOperacionElejida();
//
//	//TODO el la visualizacion del menuAlta tiene que ser igual al de menuConsulta
//	//Ejecuto la operacion elejida por el menu principal
//	ManejadorDeOperacion* manejador = new ManejadorDeOperacion(operacion);
//	manejador->iniciar();
//
//	delete menu_principal;
//	delete operacion;
//	delete manejador;

		iniciartestFranajaHoraria();
}

void iniciarCargaMasiva(const char* fichero_entrada) {
    cout<<"Carga Masiva de : "<<fichero_entrada<<endl;
    ifstream in;
    in.open(fichero_entrada, ifstream::in);
    if (in.is_open()) {
    	while (!in.eof()) {
    		string registro("");
    		in>>registro;
    		if (in.good()) {
    			cout<<registro<<endl;
    		}
    	}
    }
}

int main(int argc, char** argv){


	int siguiente_opcion;

	/* Una cadena que lista las opciones cortas válidas */
	const char* const op_cortas = "hic:" ;

	/* Una estructura de varios arrays describiendo los valores largos */
	const struct option op_largas[] =
	{
	  { "help",         0,  NULL,  'h'},
	  { "interfaxe",    0,  NULL,  'i'},
	  { "carga",        1,  NULL,  'c'},
	  { NULL,           0,  NULL,   0 }
	};

	/* El nombre del fichero que recibe la salida del programa */
	const char* fichero_entrada = NULL ;

	bool activaInterfase = 0;

	/* Guardar el nombre del programa para incluirlo a la salida */
	nombre_programa = argv[0];

	/* Si se ejecuta sin parámetros ni opciones */
	if (argc == 1)
	{
	  imprime_uso();
	  exit(0);
	}



	 while (1)
	  {
	      /* Llamamos a la función getopt */
	      siguiente_opcion = getopt_long (argc, argv, op_cortas, op_largas, NULL);

	      if (siguiente_opcion == -1)
	          break; /* No hay más opciones. Rompemos el bucle */

	      switch (siguiente_opcion)
	      {
	          case 'h' : /* -h o --help */
	              imprime_uso();
	              exit(EXIT_SUCCESS);

	          case 'i' : /* -i o --interfase */
	        	  activaInterfase = true;
	              break;

	          case 'c' : /* -c 	ó --carga */

	              fichero_entrada = optarg;
	              break;

	          case '?' : /* opción no valida */
	              imprime_uso(); /* código de salida 1 */
	              exit(1);

	          case -1 : /* No hay más opciones */
	              break;

	          default : /* Algo más? No esperado. Abortamos */
	              abort();
	          }
	  }
	if (activaInterfase) {
		iniciarInterfase();
	}
	if (fichero_entrada) {
		iniciarCargaMasiva(fichero_entrada);
	}

	return 0;
}
