/*
 * Horario.cpp
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#include "Horario.h"
#include "../persistence/Serializacion.h"
#include "../utils/const.h"

Horario::Horario() {
        // TODO Auto-generated constructor stub

}

Horario::~Horario() {
        // TODO Auto-generated destructor stub
}

void Horario::copiar(Horario *unHorario){
	this->fecha = unHorario->getFecha();
	this->hora = unHorario->getHora();
}

std::string Horario::serialize()
{
	Serializacion serial;
	serial.addString(this->fecha->serialize());
	serial.addString(this->hora->serialize());

	return serial.toString();
}
void Horario::unserialize(std::string& buffer)
{
	Serializacion serial(buffer);

	std::string fecha = serial.getString();
	this->fecha->unserialize(fecha);
	std::string hora = serial.getString();
	this->hora->unserialize(hora);

}

DataSize Horario::getDataSize()
{
	return (sizeof(int)*3 + this->fecha->getDataSize()+this->hora->getDataSize());
}

ostream & operator<<(std::ostream & os, const Horario & unHorario){
		  os << setfill('0') << setw(2) << *unHorario.hora << "-" << setfill('0') << setw(4)  << *unHorario.fecha;
		  return os;
}
