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

using namespace std;

class UtilMenu {

public:
	UtilMenu();
	virtual ~UtilMenu();
	static void separador_menu();
	static void limpiar_pantalla();
	static string getNombreCampo_segun(int idNombreCampo);
	static void verEstructraResultado(string* estructura_resultado, int cant_campos_resultado);
	static void verEstructuraFiltro(string* estructura_filtro, int cant_campos_enFiltro);
};

#endif /* UTILMENU_H_ */
