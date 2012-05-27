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
#include "../utils/const.h"

using namespace std;

class UtilMenu {

public:
	UtilMenu();
	virtual ~UtilMenu();
	static void separador_menu();
	static void limpiar_pantalla();
	static string getNombreSubElemento(int idSubElemento);
	static void verEstructraResultado(string* filtro_salida, int cant_campos_resultado);
	static void verEstructuraFiltro(string* filtro_entrada, int cant_campos_enFiltro);
};

#endif /* UTILMENU_H_ */
