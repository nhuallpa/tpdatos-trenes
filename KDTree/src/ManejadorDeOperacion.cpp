/*
 * ManejadorDeOperacion.cpp
 *
 *  Created on: 19/05/2012
 *      Author: ariel
 */

#include "ManejadorDeOperacion.h"

ManejadorDeOperacion::ManejadorDeOperacion() {

}

ManejadorDeOperacion::~ManejadorDeOperacion() {

}

ManejadorDeOperacion::ManejadorDeOperacion(Operacion* operacionManejar)
{
	this->operacionManejable = operacionManejar;
}

void ManejadorDeOperacion::iniciar(){
	cout<<"ManejadorDeOperacion::iniciar(): En proceso de construccion..."<<endl;
	this->operacionManejable->iniciar();
}
