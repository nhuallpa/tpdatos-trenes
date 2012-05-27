/*
 * OperacionAlta.cpp
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#include "OperacionAlta.h"

OperacionAlta::OperacionAlta(){
	this->reporte = new Reporte();
}

OperacionAlta::~OperacionAlta() {

}

void OperacionAlta::inicializar(int idLinea, int idFormacion, int idFalla, int idAccidente, FranjaHoraria* unaFranjaHoraria) {

	this->reporte->setIdLinea(idLinea);
	this->reporte->setIdFormacion(idFormacion);
	this->reporte->setIdFalla(idFalla);
	this->reporte->setIdAccidente(idAccidente);
	this->reporte->setFranjaHoraria(unaFranjaHoraria);
}

int OperacionAlta::iniciar(){

	int operacion_ok = OPERACION_ALTA_OK;

	cout<<"Alta para el KDTree: "<<*this->reporte<<endl;
	cout<<"Inicio Operacion."<<endl;
	cout<<"procesando..."<<endl;

	IElement* elementoArbol = new Element(this->reporte);
	//todo: lograr imprimir este elemento

	//todo por ahora no usar el bplustree
//	BPlusTree bplustree;
//	bplustree.insert();

	cout<<"Termino Operacion."<<endl;
	delete elementoArbol;
	return operacion_ok;
}

std::ostream & operator << ( std::ostream & os , const OperacionAlta & operacion )
{
  os <<"La Operacion Alta es:"<< *operacion.reporte;
  return os;
}
