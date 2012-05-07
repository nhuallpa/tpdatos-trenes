/*
 * MenuBaja.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef MENUBAJA_H_
#define MENUBAJA_H_

#include "Menu.h"

class MenuBaja: public Menu {
public:
	MenuBaja();
	virtual ~MenuBaja();
	void iniciar();
	void mostrar();
};

#endif /* MENUBAJA_H_ */
