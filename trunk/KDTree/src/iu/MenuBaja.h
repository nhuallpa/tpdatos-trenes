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
	bool operacion_fueCreada;

public:
	MenuBaja();
	virtual ~MenuBaja();
	void iniciar();
	void mostrar();
	Operacion* getOperacionElejida();
	bool getOperacion_fueCreada();
};

#endif /* MENUBAJA_H_ */
