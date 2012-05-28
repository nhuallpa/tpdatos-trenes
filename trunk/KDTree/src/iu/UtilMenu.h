/*
 * UtilMenu.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef UTILMENU_H_
#define UTILMENU_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include "../utils/const.h"
#include "../controller/KDTreeController.h"

using namespace std;

class UtilMenu {

public:
	UtilMenu();
	virtual ~UtilMenu();
	static void separador_menu();
	static void limpiar_pantalla();
	static string getNombreSubElemento(int idSubElemento);
	static string getFiltroEntrada(string* filtro_entrada, int cant_campos_enFiltro);
	static string getFiltroSalida(string* filtro_salida, int cant_campos_resultado);
	static void mostrarLista(list<string> & lista);
	static  int elejir_subElemento_(string tipo_deSubElemento, list<string>& lista, KDTreeController& kdTreeController);
};

#endif /* UTILMENU_H_ */
