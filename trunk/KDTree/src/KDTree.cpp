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
#include "controller/Operacion.h"

using std::cout;
using std::endl;
using std::ios;
using std::ifstream;
using std::string;

void imprime_uso() {
	cout<<"USAGE"<<endl;
    cout<<"    Opciones                    Comentarios"<<endl;
    cout<<"    ---------------             -------------------"<<endl;
    cout<<"    -i  --insertar              Insertar un registro. Recibe parametro con estructura (linea,falla,accidente,formacion,aaaammddhhmmhhmm)"<<endl;
    cout<<"    -r  --remover               Remueve un registro puntual. Recibe parametro con estructura (linea,falla,accidente,formacion,aaaammddhhmmhhmm)"<<endl;
    cout<<"    -m  --modificar             Modifica un registro. Recibe parametro con estructura (linea,falla,accidente,formacion,aaaammddhhmmhhmm)"<<endl;
    cout<<"    -q  --consultar             Realiza consulta. Recibe parametro con estructura (linea,falla,accidente,formacion,aaaammddhhmmhhmm)"<<endl;
    cout<<"    -v  --ver             	   Muestra el estado del arbol"<<endl;
    cout<<"    -c  --carga                 Recibe como argumento un archivo para carga masiva"<<endl;
    cout<<"    -t  --test                  Se ejecutan los test"<<endl;
    cout<<"    -u  --userinterfaxe         Modo interfase con usuario"<<endl;
    cout<<"    -h  --help                  Enseña esta ayuda"<<endl;
}

int main(int argc, char** argv){


	int siguiente_opcion;

	/* Una cadena que lista las opciones cortas válidas */
	const char* const op_cortas = "i:r:m:q:vc:tuh" ;

	/* Una estructura de varios arrays describiendo los valores largos */
	const struct option op_largas[] =
	{
	  { "insertar",    	  1,  NULL,  'i'},
	  { "remover",    	  1,  NULL,  'r'},
	  { "modificar",      1,  NULL,  'm'},
	  { "consultar",      1,  NULL,  'q'},
	  { "ver",    		  0,  NULL,  'v'},
	  { "carga",          1,  NULL,  'c'},
	  { "test",           0,  NULL,  't'},
	  { "userinterfaxe",  0,  NULL,  'u'},
	  { "help",           0,  NULL,  'h'},
	  { NULL,             0,  NULL,   0 }
	};

	/* El nombre del fichero que recibe la salida del programa */
	const char* fichero_entrada = NULL ;
	const char* registro_entrada = NULL ;


	/* Si se ejecuta sin parámetros ni opciones */
	if (argc == 1)
	{
	  imprime_uso();
	  exit(0);
	}
	KDTreeController kdTreeController;

	 while (1)
	  {
	      /* Llamamos a la función getopt */
	      siguiente_opcion = getopt_long (argc, argv, op_cortas, op_largas, NULL);

	      if (siguiente_opcion == -1)
	          break; /* No hay más opciones. Rompemos el bucle */
	      switch (siguiente_opcion)
	      {

			  case 'i' :  /* -i 	ó --insertat */
						  registro_entrada = optarg;
						  kdTreeController.insertar(registro_entrada);
						  break;

			  case 'r' :  /* -r 	ó --remover */
						  registro_entrada = optarg;
						  kdTreeController.remover(registro_entrada);
						  break;

			  case 'm' :  /* -m 	ó --modifcacion */
						  registro_entrada = optarg;
						  kdTreeController.modificar(registro_entrada);
						  break;

	          case 'q' :  /* -q 	ó --consultart */
						  registro_entrada = optarg;
						  kdTreeController.consultar(registro_entrada);
						  break;

	          case 'v' :  /* -v 	ó --ver */
	        	  	  	  kdTreeController.mostrarEstado();
						  break;

	          case 'c' :  /* -c 	ó --carga */
	          	  	  	  {
							  fichero_entrada = optarg;
							  std::ifstream in;
							  in.open(fichero_entrada, ifstream::in);
							  if (in.is_open()) {
								while (!in.eof()) {
									string registro("");
									in>>registro;
									if (in.good()) {
										kdTreeController.insertar(registro);
									}
								}
							  }
							  break;
	      	  	  	  	  }

	          case 't' :  /* -t 	ó --test */
						  TestFranjaHoraria* testFranajaHoraria = new TestFranjaHoraria();
						  testFranajaHoraria->iniciar();
						  break;

	          case 'u' :  /* -u o --interfase */
	        	  	  	  kdTreeController.iniciarUserInterfax();
						  break;

	          case 'h' :  /* -h o --help */
						  imprime_uso();
		//	              exit(EXIT_SUCCESS);
						  break;

	          case '?' :  /* opción no valida */
						  imprime_uso(); /* código de salida 1 */
						  exit(1);

	          case -1 :   /* No hay más opciones */

	        	  	  	  break;

	          default :   /* Algo más? No esperado. Abortamos */
	              	  	  abort();
	          }
	  }

	return 0;
}
