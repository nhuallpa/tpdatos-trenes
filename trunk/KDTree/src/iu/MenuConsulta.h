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
/**
 * produce consultas tal como(no se lo va a parser):
 * SELECT (linea,formacion,falla) FROM tabla-arbolKD WHERE (idLinea='1' formacion='2' falla='3' accidente='3' franajHoraria='2')
 */
class MenuConsulta: public Menu {
private:
	KDTreeController kdTreeController;
	OperacionConsulta* operacionElejida;
	bool operacion_fueCreada;

public:
	MenuConsulta(KDTreeController& kdTreeController);
	virtual ~MenuConsulta();
	void iniciar();
	OperacionConsulta* getOperacionElejida();
	bool getOperacion_fueCreada();
private:
	void mostrar();
	void mostrarMenu_estructuraResultado();
	void crear_filtroSalida();
	void crear_filtroEntrada();
	void elejir_cantCamposResultado();
	void elejir_losCamposResultado();
};

#endif /* MENUCONSULTA_H_ */
