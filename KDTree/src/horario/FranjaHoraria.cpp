/*
 * FranjaHoraria.cpp
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#include "FranjaHoraria.h"
#include "../persistence/Serializacion.h"

FranjaHoraria::FranjaHoraria() {

}

FranjaHoraria::~FranjaHoraria() {

}

FranjaHoraria::FranjaHoraria(Hour horaInicio, Hour horaFin, Date fecha){
        this->horaInicio = horaInicio;
        this->horaFin = horaFin;
        this->fecha = fecha;
}

bool FranjaHoraria::intersectaCon(Horario& horario){
	bool intersecta = false;
	if (this->fecha == horario.getFecha() ){
		if (horario.getHora() >= this->horaInicio && horario.getHora() <= this->horaFin){
			intersecta = true;
		}
	}
	return intersecta;
}

bool FranjaHoraria::intersectaCompletaCon(FranjaHoraria& unaFranjaHoraria){
	bool intersecta = false;
	if (this->fecha == unaFranjaHoraria.getFecha() ){
		if ( this->horaInicio >= unaFranjaHoraria.getHoraInicio() && this->horaFin <= unaFranjaHoraria.getHoraFin()){
			intersecta = true;
		}
	}
	return intersecta;
}

Hour FranjaHoraria::getHoraInicio() const{
	return this->horaInicio;
}

Hour FranjaHoraria::getHoraFin() const{
	return this->horaFin;
}

Date FranjaHoraria::getFecha() const {
	return this->fecha;
}

ostream & operator<<(std::ostream & os, const FranjaHoraria & fh){
		  os << setfill('0') << setw(2) << fh.horaInicio << "-" << setfill('0') << setw(2) << fh.horaFin;
		  os << "-" << setfill('0') << setw(4)  << fh.fecha;
		  return os;
}

void FranjaHoraria::copiar(FranjaHoraria *unaFranjaHoraria){
	this->fecha = unaFranjaHoraria->getFecha();
	this->horaInicio = unaFranjaHoraria->getHoraInicio();
	this->horaFin <= unaFranjaHoraria->getHoraFin();
}

std::string FranjaHoraria::serialize()
{
	Serializacion serial;
	serial.addString(this->fecha.serialize());
	serial.addString(this->horaInicio.serialize());
	serial.addString(this->horaFin.serialize());

	return serial.toString();
}
void FranjaHoraria::unserialize(std::string& buffer)
{
	Serializacion serial(buffer);

	std::string fecha = serial.getString();
	this->fecha.unserialize(fecha);
	std::string horaInicio = serial.getString();
	this->horaInicio.unserialize(horaInicio);
	std::string horaFin = serial.getString();
	this->horaFin.unserialize(horaFin);

}

int FranjaHoraria::getDataSize()
{
	return (this->fecha.getDataSize()+this->horaInicio.getDataSize()+this->horaFin.getDataSize());
}
