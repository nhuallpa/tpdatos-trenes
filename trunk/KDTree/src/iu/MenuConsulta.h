/*
 * MenuConsulta.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef MENUCONSULTA_H_
#define MENUCONSULTA_H_

#include "Menu.h"

class MenuConsulta: public Menu {
private:
	KDTreeController kdTreeController;
	Operacion* operacionElejida;
	bool operacion_fueCreada;

	string* estructura_resultado;
	int cant_campos_enResultado;
	string* estructura_filtro;
	int cant_campos_enFiltro;
public:
	MenuConsulta();
	virtual ~MenuConsulta();
	void iniciar();
	Operacion* getOperacionElejida();
private:
	void mostrar();
	void mostrarMenu_estructuraResultado();
	void crearEstructura_deResulado();
	void crearFiltro_deConsulta();
	void verConsulta();
	void ejecutar_consulta();
	void elejir_cantCamposResultado();
	void elejir_losCamposResultado();
};

#endif /* MENUCONSULTA_H_ */
