/*
 * OperacionBaja.cpp
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#include "OperacionBaja.h"

OperacionBaja::OperacionBaja() {

}

OperacionBaja::~OperacionBaja() {

}

int OperacionBaja::iniciar(){
	cout<<"Inicio la Baja de: ";
	cout<<"(...)"<<endl;

	cout<<"procesando..."<<endl;
	//...
	int operacion_ok = OPERACION_BAJA_OK;

	return operacion_ok;
}

void OperacionBaja::mostrar(){
	cout<<"(...)"<<endl;
}
