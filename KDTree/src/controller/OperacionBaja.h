/*
 * OperacionBaja.h
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#ifndef OPERACIONBAJA_H_
#define OPERACIONBAJA_H_
#include "Operacion.h"

class OperacionBaja: public Operacion {
public:
	OperacionBaja();
	virtual ~OperacionBaja();
	void inicializar(string linea, string formacion, string falla, string accidente, string franjaHoraria);
	int iniciar();
	void mostrar();
};

#endif /* OPERACIONBAJA_H_ */
