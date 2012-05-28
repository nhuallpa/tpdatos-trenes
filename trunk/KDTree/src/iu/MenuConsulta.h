/*
 * MenuConsulta.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef MENUCONSULTA_H_
#define MENUCONSULTA_H_

#include "Menu.h"
#include "../controller/OperacionConsulta.h"

class MenuConsulta: public Menu {
private:
	KDTreeController kdTreeController;
	OperacionConsulta* operacionElejida;
	bool operacion_fueCreada;

public:
	MenuConsulta(KDTreeController& kdTreeController);
	virtual ~MenuConsulta();
	bool iniciar();
	OperacionConsulta* getOperacionElejida();
private:
	void mostrar();
	void mostrarMenu_estructuraResultado();
	void crear_filtroSalida();
	void crear_filtroEntrada();
	void ejecutar_consulta();
	void elejir_cantCamposResultado();
	void elejir_losCamposResultado();
};

#endif /* MENUCONSULTA_H_ */
