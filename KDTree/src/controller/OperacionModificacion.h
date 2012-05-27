/*
 * OperacionModificacion.h
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#ifndef OPERACIONMODIFICACION_H_
#define OPERACIONMODIFICACION_H_
#include "Operacion.h"

class OperacionModificacion: public Operacion {
public:
	OperacionModificacion();
	virtual ~OperacionModificacion();
	void inicializar(string linea, string formacion, string falla, string accidente, string franjaHoraria);
	int iniciar();
};

#endif /* OPERACIONMODIFICACION_H_ */
