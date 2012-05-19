/*
 * MenuModificacion.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef MENUMODIFICACION_H_
#define MENUMODIFICACION_H_

#include "Menu.h"

class MenuModificacion: public Menu {
private:
	KDTreeController kdTreeController;
	//TODO actualizarlo
	Operacion* operacionElejida;

public:
	MenuModificacion();
	virtual ~MenuModificacion();
	void iniciar();
	void mostrar();
	Operacion* getOperacionElejida(){ return this->operacionElejida; }
};

#endif /* MENUMODIFICACION_H_ */
