/*
 * OperacionAlta.h
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#ifndef OPERACIONALTA_H_
#define OPERACIONALTA_H_
#include "Operacion.h"
#include "../bplustree/Element.h"
#include "../utils/utiles.h"
#include "../horario/FranjaHoraria.h"

class OperacionAlta: public Operacion {
private:
	Reporte* reporte;

public:
	OperacionAlta();
	virtual ~OperacionAlta();
	void inicializar(int idLinea, int idFormacion, int idFalla, int idAccidente, FranjaHoraria* franjaHoraria);
	int iniciar();
	friend std::ostream & operator<<( std::ostream & os, const OperacionAlta & );
};

#endif /* OPERACIONALTA_H_ */
