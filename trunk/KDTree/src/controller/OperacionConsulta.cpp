/*
 * OperacionConsulta.cpp
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#include "OperacionConsulta.h"

OperacionConsulta::OperacionConsulta() {
	this->tamanio_entrada = 0;
	this->filtroEntrada = new string[0];
	this->tamanio_salida = 0;
	this->filtroSalida = new string[0];
}

OperacionConsulta::~OperacionConsulta() {
	if (this->filtroEntrada)
		delete this->filtroEntrada;
	if (this->filtroSalida)
		delete this->filtroSalida;

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

void OperacionConsulta::inicializar_filtroEntrada(string* filtroEntrada, int tamanio){
	this->tamanio_entrada = tamanio;
	this->filtroEntrada = new string[tamanio];
	for(int i=0 ; i<tamanio ; i++)
		this->filtroEntrada[i] = filtroEntrada[i];
}

void OperacionConsulta::inicializar_filtroSalida(string* filtroSalida, int tamanio){
	this->tamanio_salida = tamanio;
	this->filtroSalida = new string[tamanio];
	for(int i=0 ; i<tamanio ; i++)
		this->filtroSalida[i] = filtroSalida[i];
}

std::ostream & operator << ( std::ostream & os , const OperacionConsulta & operacionConsulta )
{
	os<<"La consulta es(tipo MySql):\n";
	os<<"SELECT ";
	if (operacionConsulta.tamanio_salida < 1)
		os<<"* ";
	else
		os<<UtilMenu::getFiltroSalida(operacionConsulta.filtroSalida, operacionConsulta.tamanio_salida);
	os<<"FROM tabla-arbolKD WHERE ";
	if (operacionConsulta.tamanio_entrada < 1)
		os<<"1";
	else
		os<<UtilMenu::getFiltroEntrada(operacionConsulta.filtroEntrada, operacionConsulta.tamanio_entrada);

  return os;
}
