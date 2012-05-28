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
};

#endif /* UTILMENU_H_ */
