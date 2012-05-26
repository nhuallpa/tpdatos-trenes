/*
 * Reporte.cpp
 *
 *  Created on: 23/05/2012
 *      Author: sergio
 */

#include "Reporte.h"

Reporte::Reporte() {
	this->franjaHoraria = new FranjaHoraria();
}

Reporte::Reporte(IEntidad* copy) {
	this->franjaHoraria = new FranjaHoraria();
	std::string buffer = copy->serialize();
	this->unserialize(buffer);
}

Reporte::~Reporte() {
	delete franjaHoraria;
}

void Reporte::setIdFalla(int idFalla)
{
	this->idFalla = idFalla;
}
int Reporte::getIdFalla()
{
	return this->idFalla;
}

void Reporte::setIdLinea(int idLinea)
{
	this->idLinea = idLinea;
}
int Reporte::getIdLinea()
{
	return this->idLinea;
}

void Reporte::setIdFormacion(int idFormacion)
{
	this->idFormacion = idFormacion;
}
int Reporte::getIdFormacion()
{
	return this->idFormacion;
}

void Reporte::setIdAccidente(int idAccidente)
{
	this->idAccidente = idAccidente;
}
int Reporte::getIdAccidente()
{
	return this->idAccidente;
}


void Reporte::setFranjaHoraria(FranjaHoraria *franjaHoraria)
{
	this->franjaHoraria->copiar(franjaHoraria);
}
FranjaHoraria* Reporte::getFranjaHoraria()
{
	return this->franjaHoraria;
}

bool Reporte::equals(Reporte* entidad){
	return false;
}

std::string Reporte::serialize()
{

	Serializacion serial;

	serial.addEntero(this->idLinea);
	serial.addEntero(this->idFormacion);
	serial.addEntero(this->idFalla);
	serial.addEntero(this->idAccidente);
	serial.addString(this->franjaHoraria->serialize());

	return serial.toString();
}
void Reporte::unserialize(std::string& buffer)
{
	Serializacion serial(buffer);

	this->idLinea = serial.getEntero();
	this->idFormacion = serial.getEntero();
	this->idFalla = serial.getEntero();
	this->idAccidente = serial.getEntero();

	std::string franjaHoraria = serial.getString();
	this->franjaHoraria->unserialize(franjaHoraria);

}

int Reporte::getDataSize()
{
	return (sizeof(int)*4 + this->franjaHoraria->getDataSize());
}
