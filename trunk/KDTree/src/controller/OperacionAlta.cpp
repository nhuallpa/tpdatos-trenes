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

	int idLinea_elejida = Util::toInt(this->linea);
	int idFormacion_elejida = Util::toInt(this->formacion);
	int idFalla_elejida = Util::toInt(this->falla);
	int idAccidente_elejida = Util::toInt(this->accidente);
//	int idFranjaHoraria_elejida = Util::toInt(this->franjaHoraria);

	int operacion_ok = OPERACION_ALTA_OK;

	FranjaHoraria* unaFranjaHoraria = new FranjaHoraria();

	Reporte* unReporte = new Reporte();
	unReporte->setIdLinea(idLinea_elejida);
	unReporte->setIdFalla(idFalla_elejida);
	unReporte->setIdAccidente(idAccidente_elejida);
	unReporte->setIdFormacion(idFormacion_elejida);
	unReporte->setFranjaHoraria(unaFranjaHoraria);

	cout<<"Alta para el KDTree: "<<*unReporte<<endl;
	cout<<"Inicio Operacion."<<endl;
	cout<<"procesando..."<<endl;

	IElement* elementoArbol = new Element(unReporte);
	//todo: lograr imprimir este elemento

	//todo por ahora no usar el bplustree
//	BPlusTree bplustree;
//	bplustree.insert();

	cout<<"Termino Operacion."<<endl;
	delete unReporte;
	delete elementoArbol;
	return operacion_ok;
}

void OperacionAlta::mostrar(){
	cout<<"Operacion Alta: ";
	cout<<"("<<this->linea<<","<<this->formacion<<","<<this->falla<<","<<this->accidente<<","<<this->franjaHoraria<<")"<<endl;
}
