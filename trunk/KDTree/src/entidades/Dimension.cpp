/*
 * Dimension.cpp
 *
 *  Created on: 14/06/2012
 *      Author: sergio
 */

#include "Dimension.h"
#include "../utils/utiles.h"

Dimension::Dimension(int dimension, int value) {
	this->dimension = dimension;
	this->value = value;
}

Dimension::~Dimension() {
}

void Dimension::setValue(int value){
	this->value = value;
}


int Dimension::compareTo(IEntidad* entidad){
	Dimension* d = (Dimension*) entidad;
	if (d->dimension == this->dimension){
		if (d->value > this->value){
			return MENOR;
		} else if (d->value < this->value){
			return MAYOR;
		} else {
			return IGUAL;
		}
	} else {
		return NEXT;
	}
}

string Dimension::toString () const{
	std::stringstream flujo;
	flujo <<"("<< this->dimension << ", "
		  << this->value <<");";
	return flujo.str();
}

string Dimension::serialize(){

	Serializacion serial;

	serial.addEntero(this->dimension);
	serial.addEntero(this->value);

	return serial.toString();
}
void Dimension::unserialize(string& buffer){

	Serializacion serial(buffer);

	this->dimension = serial.getEntero();
	this->value = serial.getEntero();
}

DataSize Dimension::getDataSize(){
	return sizeof(int)*2;
}
