/*
 * Reporte.cpp
 *
 *  Created on: 23/05/2012
 *      Author: sergio
 */

#include "Reporte.h"

Reporte::Reporte() {
	this->idLinea = 0;
	this->idFormacion = 0;
	this->idFalla = 0;
	this->idAccidente = 0;
	this->franjaHoraria = new FranjaHoraria();
}

Reporte::Reporte(string tupla) {
	list<string> lista = Util::parsear(tupla);
	list<string>::iterator it;
	it = lista.begin();
	this->setIdLinea(StringUtils::convertStringToInt(*(it++)));
	this->setIdFalla(StringUtils::convertStringToInt(*(it++)));
	this->setIdAccidente(StringUtils::convertStringToInt(*(it++)));
	this->setIdFormacion(StringUtils::convertStringToInt(*(it++)));
	FranjaHoraria* fh = new FranjaHoraria(*(it++));
	this->setFranjaHoraria(fh);
//	delete fh;
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
//	this->franjaHoraria->copiar(franjaHoraria);
	this->franjaHoraria = franjaHoraria;
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

DataSize Reporte::getDataSize()
{
	return (sizeof(int)*4 + this->franjaHoraria->getDataSize());
}

std::string Reporte::toString() const{

	std::stringstream flujo;
	flujo <<"("<< this->idLinea << ", "
		  << this->idFalla <<", "
		  << this->idAccidente <<", "
		  << this->idFormacion <<", "
		  << *this->franjaHoraria <<");";
	return flujo.str();
}

ostream & operator<<(std::ostream & os, const Reporte & reporte){
		  os << reporte.toString();
		  return os;
}

