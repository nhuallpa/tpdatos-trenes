/*
 * FranjaHoraria.cpp
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#include "FranjaHoraria.h"
#include "../persistence/Serializacion.h"

FranjaHoraria::FranjaHoraria() {
	this->horaInicio = new Hour(0, 0) ;
	this->horaFin = new Hour(0, 0);
	this->fecha = new Date(1, 1, 1800);
}

FranjaHoraria::~FranjaHoraria() {

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

int FranjaHoraria::getDataSize()
{
	return (this->fecha->getDataSize()+this->horaInicio->getDataSize()+this->horaFin->getDataSize());
}
