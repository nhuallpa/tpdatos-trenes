/*
 * OperacionAlta.h
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#ifndef OPERACIONALTA_H_
#define OPERACIONALTA_H_
#include "Operacion.h"

class OperacionAlta: public Operacion {
private:
	//TODO: tendria que ser cargado con la estructura de la data del elemento del arbol KD
	string linea;
	string formacion;
	string falla;
	string accidente;
	string franjaHoraria;

public:
	OperacionAlta();
	virtual ~OperacionAlta();
	void inicializar(string linea, string formacion, string falla, string accidente, string franjaHoraria);
	int iniciar();
	void mostrar();
};

#endif /* OPERACIONALTA_H_ */
