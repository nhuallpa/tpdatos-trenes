/*
 * Lista.cpp
 *
 *  Created on: Oct 11, 2011
 *      Author: carlos
 */

#include "Lista.h"
#include "../persistence/Serializacion.h"

Lista::Lista() {
	// TODO Auto-generated constructor stub
}

Lista::~Lista() {
	// TODO Auto-generated destructor stub
}

int Lista::getDataSize()
{
}

void Lista::unserialize(std::string & buffer)
{
	Serializacion serial(buffer);

	id_eleccion=serial.getID();
	nombre=serial.getString();
}

std::string Lista::serialize()
{
	Serializacion serial;

	serial.addID(id_eleccion);
	serial.addString(nombre);
	return serial.toString();
}

ID Lista::getIdEleccion() const
{
    return id_eleccion;
}

std::string Lista::getNombre() const
{
    return nombre;
}

void Lista::setIdEleccion(ID idEleccion)
{
    id_eleccion = idEleccion;
}

void Lista::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

string Lista::toString(){
	return this->nombre;
}
