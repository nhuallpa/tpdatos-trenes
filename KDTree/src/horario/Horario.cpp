/*
 * Horario.cpp
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#include "Horario.h"

Horario::Horario() {
	// TODO Auto-generated constructor stub
}

Horario::Horario(Hour hora, Date fecha){
	this->hora = hora;
	this->fecha = fecha;
}
Date Horario::getFecha() const{
	return this->fecha;
}

Hour Horario::getHora() const{
	return this->hora;
}

Horario::~Horario() {
	// TODO Auto-generated destructor stub
}

