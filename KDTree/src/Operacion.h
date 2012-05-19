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

class Operacion {
public:
	Operacion();
	virtual ~Operacion();
	void iniciar(){
		cout<<"Operacion::iniciar() -> En proceso de construccion..."<<endl;
	}
};

#endif /* OPERACION_H_ */
