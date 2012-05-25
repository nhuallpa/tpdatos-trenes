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

private:
	KDTreeController kdTreeController;
	Operacion* operacionElejida;
	bool operacion_fueCreada;
public:
	MenuAlta(KDTreeController& kdTreeController);
	virtual ~MenuAlta();
	void iniciar();
	void mostrar();
	KDTreeController& getController();
	Operacion* getOperacionElejida();

private:
	void insertar_elemento();
	void mostrarLista(list<string>& lista);
	string elejir_subElemento_segun(string tipo_deSubElemento, list<string>& lista);

};

#endif /* MENUALTA_H_ */
