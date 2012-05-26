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

void iniciarTestFranjaHoraria(){
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

void iniciarInterfase()
{
	Operacion* operacionElejida;
	Menu* menu_principal;
	bool operacion_esElejida = false;
    bool salir_programa= false;
    while(!salir_programa)
    {
        UtilMenu::separador_menu();
        cout<<"1-elejir operacion para KDTree"<<endl;
        cout<<"2-mostrar operacion"<<endl;
        cout<<"3-ejecutar operacion"<<endl;
        cout<<"4-salir"<<endl;

        char opcion_elejida = '0';
        cout<<"elejir opcion: ";
        cin>>opcion_elejida;
        UtilMenu::limpiar_pantalla();
        switch(opcion_elejida){
            case '1' :  {
            				KDTreeController kdTreeController;
            				menu_principal = new MenuPrincipal(kdTreeController);
            				operacion_esElejida = menu_principal->iniciar();
            				operacionElejida =  menu_principal->getOperacionElejida();
            				break;
            			}
            case '2' :  {
            				if (operacion_esElejida)
            					operacionElejida->mostrar();
            				else
            					cout<<"debe elejir una operacion"<<endl;
							break;
            			}

            case '3' :  {
							if (operacion_esElejida)
								operacionElejida->iniciar();
							else
								cout<<"debe elejir una operacion"<<endl;
							break;
        				}
            case '4' :  {
            				operacionElejida->iniciar();
            				salir_programa = true;
            				UtilMenu::limpiar_pantalla();
            				delete menu_principal;
							break;
        				}
            default : cout<<"opcion de menu invalida"<<endl; break;
        }

        delete operacionElejida;
    }

//		iniciarTestFranjaHoraria();
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
    }else{
    	cout<<"No se pudo abrir "<<fichero_entrada<<endl;
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
