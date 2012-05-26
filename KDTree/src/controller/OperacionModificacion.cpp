/*
 * OperacionModificacion.cpp
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#include "OperacionModificacion.h"

OperacionModificacion::OperacionModificacion() {

}

OperacionModificacion::~OperacionModificacion() {

}

int OperacionModificacion::iniciar(){
	cout<<"Inicia la Modificacion de: ";
	cout<<"(...)"<<endl;

	cout<<"procesando..."<<endl;
	//...
	int operacion_ok = OPERACION_MODIFICACION_OK;

	return operacion_ok;
}

void OperacionModificacion::mostrar(){
	cout<<"(...)"<<endl;
}
