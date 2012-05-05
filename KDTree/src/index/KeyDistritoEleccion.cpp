/*
 * KeyEleccionDistrito.cpp
 *
 *      Author: carlos
 */

#include "KeyDistritoEleccion.h"
#include "../bplustree/exceptions/ProgramException.h"
KeyDistritoEleccion::KeyDistritoEleccion(){}
KeyDistritoEleccion::KeyDistritoEleccion(ID keyDistrito, ID keyEleccion) {
	if(keyDistrito>4200){
		throw ProgramException("Maximo posible de distritos=4200");
	}
	if(keyEleccion>967296){
		throw ProgramException("maximo posible para eleccion 967296");
	}
	this->KeyEleccion = keyEleccion;
	this->keyDistrito = keyDistrito;
}

void KeyDistritoEleccion::unserialize(std::string & buffer) {
	buffer.copy((char*) &(this->keyDistrito), sizeof(this->keyDistrito));
	buffer.erase(0, sizeof(this->keyDistrito));

	buffer.copy((char*) &(this->KeyEleccion), sizeof(this->KeyEleccion));
	buffer.erase(0, sizeof(this->KeyEleccion));
}

std::string KeyDistritoEleccion::serialize() {

	std::string buffer="";
	buffer.append((char*) &(this->keyDistrito), sizeof(this->keyDistrito));
	buffer.append((char*) &(this->KeyEleccion), sizeof(this->KeyEleccion));
	return buffer;
}

int KeyDistritoEleccion::getDataSize() {
	return sizeof(this->KeyEleccion) + sizeof(this->keyDistrito);
}

KeyDistritoEleccion::~KeyDistritoEleccion() {
}

