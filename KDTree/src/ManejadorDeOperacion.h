/*
 * ManejadorDeOperacion.h
 *
 *  Created on: 19/05/2012
 *      Author: ariel
 */

#ifndef MANEJADORDEOPERACION_H_
#define MANEJADORDEOPERACION_H_
#include "Operacion.h"
#include <iostream>
using namespace std;

class ManejadorDeOperacion {
private:
	Operacion* operacionManejable;
public:
	ManejadorDeOperacion();
	ManejadorDeOperacion(Operacion* operacionManejar);
	virtual ~ManejadorDeOperacion();
	void iniciar();
};

#endif /* MANEJADORDEOPERACION_H_ */
