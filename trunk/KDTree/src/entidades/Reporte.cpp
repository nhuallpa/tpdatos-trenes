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

int Reporte::compareTo(Reporte* entidad, int numCampo){
	int resultadoComparacion = -1;
  bool mayor = false;
  bool menor = false;
  bool igual = false;
  
   if (numCampo == 1){
     mayor = this->getIdLinea() > entidad->getIdLinea();
     menor = this->getIdLinea() < entidad->getIdLinea();
     igual = this->getIdLinea() == entidad->getIdLinea();
   }else if (numCampo == 2){
     mayor =   this->getIdFormacion() > entidad->getIdFormacion();
     menor =   this->getIdFormacion() < entidad->getIdFormacion();
     igual = this->getIdFormacion() == entidad->getIdFormacion();
   }else if (numCampo == 3){
     mayor = this->getIdFalla() > entidad->getIdFalla();
     menor = this->getIdFalla() < entidad->getIdFalla();
     igual = this->getIdFalla() == entidad->getIdFalla();
   }else if (numCampo == 4){
     mayor = this->getIdAccidente() > entidad->getIdAccidente();
     menor = this->getIdAccidente() < entidad->getIdAccidente();
     igual = this->getIdAccidente() == entidad->getIdAccidente();
   }else if (numCampo == 5){
      mayor = *this->getFranjaHoraria() > *entidad->getFranjaHoraria();
      menor = *this->getFranjaHoraria() < *entidad->getFranjaHoraria();
      igual = *this->getFranjaHoraria() == *entidad->getFranjaHoraria();
   }
      
	if (mayor){
		resultadoComparacion = 	MAYOR;
	}else if (menor){
		resultadoComparacion = MENOR;
	}else if (igual){
		resultadoComparacion = IGUAL;
	}

	return resultadoComparacion;
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

