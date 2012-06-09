/*
 * FranjaHoraria.cpp
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#include "FranjaHoraria.h"
#include "../persistence/Serializacion.h"
#include "../utils/const.h"


FranjaHoraria::FranjaHoraria() {
	this->horaInicio = new Hour() ;
	this->horaFin = new Hour();
	this->fecha = new Date();
}

FranjaHoraria::~FranjaHoraria() {

}
// yyyymmddhhmmhhmm
FranjaHoraria::FranjaHoraria(string cadena) {

	if (cadena.compare(ELEM_VACIO) == 0){
		this->horaInicio = new Hour();
		this->horaFin = new Hour();
		this->fecha = new Date();
	}else{
		uint anio = StringUtils::convertStringToUint(cadena.substr(0, 4));
		uint mes = StringUtils::convertStringToUint(cadena.substr(4, 2));
		uint dia = StringUtils::convertStringToUint(cadena.substr(6, 2));

		uint horaInicio = StringUtils::convertStringToUint(cadena.substr(8, 2));
		uint minutoInicio = StringUtils::convertStringToUint(cadena.substr(10, 2));

		uint horaFin = StringUtils::convertStringToUint(cadena.substr(12, 2));
		uint minutoFin = StringUtils::convertStringToUint(cadena.substr(14, 2));


		this->horaInicio = new Hour(horaInicio, minutoInicio);
		this->horaFin = new Hour(horaFin, minutoFin);
		this->fecha = new Date(dia, mes, anio);

	}
}

FranjaHoraria::FranjaHoraria(uint horaInicio, uint minutoInicio,uint horaFin
								, uint minutoFin, uint dia, uint mes, uint anio)
{
	this->horaInicio = new Hour(horaInicio, minutoInicio);
	this->horaFin = new Hour(horaFin, minutoFin);
	this->fecha = new Date(dia, mes, anio);
}

Hour* FranjaHoraria::getHoraInicio() const{
	return this->horaInicio;
}

Hour* FranjaHoraria::getHoraFin() const{
	return this->horaFin;
}

Date* FranjaHoraria::getFecha() const {
	return this->fecha;
}

ostream & operator<<(std::ostream & os, const FranjaHoraria & fh){
		  os << setfill('0') << setw(2) << *fh.horaInicio << "-" << setfill('0') << setw(2) << *fh.horaFin;
		  os << "-" << setfill('0') << setw(4)  << *fh.fecha;
		  return os;
}

bool FranjaHoraria::operator==(FranjaHoraria& unaFranjaHoraria){
	bool esIgual = false;
	if (*this->fecha == *unaFranjaHoraria.getFecha() ){
		if ( *this->horaInicio >= *unaFranjaHoraria.getHoraInicio() && *this->horaFin <= *unaFranjaHoraria.getHoraFin()){
			esIgual = true;
		}
	}
	return esIgual;
}
bool FranjaHoraria::operator<(FranjaHoraria& unaFranjaHoraria){
	bool esMenor = false;
	if (*this->fecha < *unaFranjaHoraria.getFecha()){
		esMenor = true;
	}else if ( *this->fecha == *unaFranjaHoraria.getFecha()){
		if ( *this->getHoraFin() < *unaFranjaHoraria.getHoraInicio())
			esMenor = true;
	}
	return esMenor;
}

bool FranjaHoraria::operator>(FranjaHoraria& unaFranjaHoraria){
	bool esMayor = false;
	if (*this->fecha > *unaFranjaHoraria.getFecha()){
		esMayor = true;
	}else if ( *this->fecha == *unaFranjaHoraria.getFecha() ){
		if ( *this->getHoraInicio() > *unaFranjaHoraria.getHoraFin() )
			esMayor = true;
	}
	return esMayor;
}

void FranjaHoraria::copiar(FranjaHoraria *unaFranjaHoraria){
	this->fecha = unaFranjaHoraria->getFecha();
	this->horaInicio = unaFranjaHoraria->getHoraInicio();
	this->horaFin = unaFranjaHoraria->getHoraFin();
}

std::string FranjaHoraria::serialize()
{
	Serializacion serial;
	serial.addString(this->fecha->serialize());
	serial.addString(this->horaInicio->serialize());
	serial.addString(this->horaFin->serialize());

	return serial.toString();
}
void FranjaHoraria::unserialize(std::string& buffer)
{
	Serializacion serial(buffer);

	std::string fecha = serial.getString();
	this->fecha->unserialize(fecha);
	std::string horaInicio = serial.getString();
	this->horaInicio->unserialize(horaInicio);
	std::string horaFin = serial.getString();
	this->horaFin->unserialize(horaFin);

}

DataSize FranjaHoraria::getDataSize()
{
	return (sizeof(int)*3 + this->fecha->getDataSize()+this->horaInicio->getDataSize()+this->horaFin->getDataSize());
}
