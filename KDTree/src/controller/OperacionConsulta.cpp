/*
 * OperacionConsulta.cpp
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#include "OperacionConsulta.h"

OperacionConsulta::OperacionConsulta() {

}

OperacionConsulta::~OperacionConsulta() {

}

void OperacionConsulta::inicializar(int idLinea, int idFormacion, int idFalla,
		int idAccidente, FranjaHoraria* franjaHoraria) {
}

int OperacionConsulta::iniciar(){
	cout<<"Inicia la Consulta de: ";
	cout<<"(...)"<<endl;

	cout<<"procesando..."<<endl;
	//...
	int operacion_ok = OPERACION_CONSULTA_OK;

	return operacion_ok;
}
//
//void OperacionConsulta::mostrar(){
//	cout<<"La consulta es(tipo MySql):"<<endl;
//	cout<<"SELECT ";
//	if (this->tamanio_salida < 1)
//		cout<<"* ";
//	else
//		UtilMenu::verEstructraResultado(this->filtroSalida, this->tamanio_salida);
//	cout<<"FROM tabla-arbolKD WHERE ";
//	if (this->tamanio_entrada < 1)
//		cout<<"1";
//	else
//		UtilMenu::verEstructuraFiltro(this->filtroEntrada, this->tamanio_entrada);
//	cout<<";"<<endl;
//}

void OperacionConsulta::inicializar_filtroEntrada(string* filtroEntrada, int tamanio){
	for(int i=0 ; i<tamanio ; i++)
		this->filtroEntrada[i] = filtroEntrada[i];
	this->tamanio_entrada = tamanio;
}

void OperacionConsulta::inicializar_filtroSalida(string* filtroSalida, int tamanio){
	for(int i=0 ; i<tamanio ; i++)
		this->filtroSalida[i] = filtroSalida[i];
	this->tamanio_salida = tamanio;
}
