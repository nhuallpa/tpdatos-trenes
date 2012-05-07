/*
 * MenuPrincipal.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef MENUPRINCIPAL_H_
#define MENUPRINCIPAL_H_

#include "Menu.h"
#include "MenuAlta.h"
#include "MenuBaja.h"
#include "MenuModificacion.h"
#include "MenuConsulta.h"
#include "UtilMenu.h"

class MenuPrincipal: public Menu {
public:
	MenuPrincipal();
	virtual ~MenuPrincipal();
	void iniciar();
	void mostrar();
};

#endif /* MENUPRINCIPAL_H_ */
