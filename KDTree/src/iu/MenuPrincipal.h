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
#include "../controller/KDTreeController.h"

class MenuPrincipal: public Menu {

private:
	KDTreeController kdTreeController;
	//TODO actualizarlo
	Operacion* operacionElejida;

public:
	MenuPrincipal(KDTreeController& kdTreeController);
	virtual ~MenuPrincipal();
	void iniciar();
	void mostrar();
    KDTreeController& getKdTreeController();
    Operacion* getOperacionElejida();

};

#endif /* MENUPRINCIPAL_H_ */