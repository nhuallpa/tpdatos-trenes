/*
 * Operacion.h
 *
 *  Created on: 19/05/2012
 *      Author: ariel
 */

#ifndef OPERACION_H_
#define OPERACION_H_
#include <iostream>
using namespace std;
#include "../utils/const.h"
#include "../entidades/Reporte.h"

class Operacion {
public:
	Operacion();
	virtual ~Operacion();
	void inicializar(string linea, string formacion, string falla, string accidente, string franjaHoraria);
	/**
	 * TODO: con los datos inicilizados implementar segun las estrategias de operatorias del KDTree
	 * return: condicion de error de la operacion
	 */
	virtual int iniciar() = 0;
	virtual void mostrar() = 0;
};

#endif /* OPERACION_H_ */
