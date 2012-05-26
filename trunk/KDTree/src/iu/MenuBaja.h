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
private:
	KDTreeController kdTreeController;
	//TODO actualizarlo
	Operacion* operacionElejida;

public:
	MenuBaja();
	virtual ~MenuBaja();
	bool iniciar();
	void mostrar();
	Operacion* getOperacionElejida();
};

#endif /* MENUBAJA_H_ */