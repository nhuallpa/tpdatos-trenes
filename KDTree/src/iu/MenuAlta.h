/*
 * MenuAlta.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef MENUALTA_H_
#define MENUALTA_H_

#include "Menu.h"

class MenuAlta: public Menu {
public:
	MenuAlta();
	virtual ~MenuAlta();
	void iniciar();
	void mostrar();
private:
	void insertar_elemento();
};

#endif /* MENUALTA_H_ */
