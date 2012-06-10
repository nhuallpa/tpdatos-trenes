/*
 * FranjaFecha.cpp
 *
 *  Created on: 09/06/2012
 *      Author: ariel
 */

#include "FranjaFecha.h"

FranjaFecha::FranjaFecha() {
	// TODO Auto-generated constructor stub

}

FranjaFecha::~FranjaFecha() {
	// TODO Auto-generated destructor stub
}

FranjaFecha::FranjaFecha(string fechaDesde, string fechaHasta) {
	this->fechaDesde = new Date(fechaDesde);
	this->fechaHasta = new Date(fechaHasta);
}

bool FranjaFecha::contiene_aFranjaHoraria(FranjaHoraria* unaFranjaHoraria) {
	return false;
}

string FranjaFecha::serialize() {
	return "";
}

void FranjaFecha::unserialize(std::string& buffer) {
}

DataSize FranjaFecha::getDataSize() {
	return (sizeof(int)*2 + this->fechaDesde->getDataSize()+this->fechaHasta->getDataSize());
}



