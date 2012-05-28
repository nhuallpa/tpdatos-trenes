/*
 * MenuAlta.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef MENUALTA_H_
#define MENUALTA_H_

#include "Menu.h"
#include "../controller/OperacionAlta.h"

class MenuAlta: public Menu {

private:
	KDTreeController kdTreeController;
	OperacionAlta* operacionElejida;
	bool operacion_fueCreada;

public:
	MenuAlta(KDTreeController& kdTreeController);
	virtual ~MenuAlta();
	void iniciar();
	void mostrar();
	KDTreeController& getController();
	OperacionAlta* getOperacionElejida();
	bool getOperacion_fueCreada();

private:
	/**
	 * elije segun los archivos maestros cargados por el controlador del KDTree
	 */
	void crearOperacion();
	int elejir_subElemento(string tipo_deSubElemento, list<string>& lista);
};

#endif /* MENUALTA_H_ */