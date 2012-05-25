/*
 * FranjaHoraria.cpp
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#include "FranjaHoraria.h"

FranjaHoraria::FranjaHoraria() {
	// TODO Auto-generated constructor stub

}

FranjaHoraria::~FranjaHoraria() {
	// TODO Auto-generated destructor stub
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
