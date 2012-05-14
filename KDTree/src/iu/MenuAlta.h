/*
 * MenuAlta.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef MENUALTA_H_
#define MENUALTA_H_

#include "Menu.h"
#include "../controller/KDTreeController.h"

class MenuAlta: public Menu {

private:
	KDTreeController kdTreeController;

public:
	MenuAlta(KDTreeController& kdTreeController);
	virtual ~MenuAlta();
	void iniciar();
	void mostrar();

	KDTreeController& getController() { return this->kdTreeController;}

private:
	void insertar_elemento();
	void mostrarLista(list<string>& lista);
	string elejir_subElemento_segun(string tipo_deSubElemento, list<string>& lista);
};

#endif /* MENUALTA_H_ */
