/*
 * OperacionAlta.cpp
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#include "OperacionAlta.h"

OperacionAlta::OperacionAlta(){
	this->linea = "";
	this->formacion = "";
	this->falla = "";
	this->accidente = "";
	this->franjaHoraria = "";
}

OperacionAlta::~OperacionAlta() {

}

void OperacionAlta::inicializar(string linea, string formacion, string falla, string accidente, string franjaHoraria) {
	this->linea = linea;
	this->formacion = formacion;
	this->falla = falla;
	this->accidente = accidente;
	this->franjaHoraria = franjaHoraria;
}

int OperacionAlta::iniciar(){
	cout<<"Inicio Alta de: ";
	cout<<"("<<this->linea<<","<<this->formacion<<","<<this->falla<<","<<this->accidente<<","<<this->franjaHoraria<<")"<<endl;

	cout<<"procesando..."<<endl;
	//...
	int operacion_ok = OPERACION_ALTA_OK;

	return operacion_ok;
}

void OperacionAlta::mostrar(){
	cout<<"El alta es: ";
	cout<<"("<<this->linea<<","<<this->formacion<<","<<this->falla<<","<<this->accidente<<","<<this->franjaHoraria<<")"<<endl;
}
