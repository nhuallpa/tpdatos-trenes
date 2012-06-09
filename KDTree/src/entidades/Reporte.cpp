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
	return (sizeof(int)*4 + sizeof(int) +this->franjaHoraria->getDataSize());
}

std::string Reporte::toString() const{

	std::stringstream flujo;
	flujo <<"("<< this->idLinea << ", "
		  << this->idFormacion <<", "
		  << this->idFalla <<", "
		  << this->idAccidente <<", "
		  << *this->franjaHoraria <<");";
	return flujo.str();
}

void Reporte::inicializar(string entrada_reporte) {
	list<string> lista = Util::parsear(entrada_reporte);
	list<string>::iterator it = lista.begin();
	string idLinea_string, idFormacion_string, idFalla_string, idAccidente_string;

	idLinea_string = *(it++);
	this->setIdLinea((idLinea_string.compare(ELEM_TODO) == 0) 		? ELEM_TODO_NUM : StringUtils::convertStringToInt(idLinea_string));
	idFormacion_string = *(it++);
	this->setIdFormacion((idFormacion_string.compare(ELEM_TODO) == 0) 	? ELEM_TODO_NUM : StringUtils::convertStringToInt(idFormacion_string));
	idFalla_string = *(it++);\
	this->setIdFalla((idFalla_string.compare(ELEM_TODO) == 0) 		? ELEM_TODO_NUM : StringUtils::convertStringToInt(idFalla_string));
	idAccidente_string = *(it++);
	this->setIdAccidente((idAccidente_string.compare(ELEM_TODO) == 0) 	? ELEM_TODO_NUM : StringUtils::convertStringToInt(idAccidente_string));

	FranjaHoraria* fh = new FranjaHoraria(*it);
	this->setFranjaHoraria(fh);
//	delete fh;
}

int Reporte::compareTo(IEntidad* entidad) {
	Reporte* reporte = (Reporte*)entidad;
	int resultadoComparacion = -1;

	for (int i = 1; i <= 5; i++) {
		resultadoComparacion = this->compareTo(reporte, i);

		if (resultadoComparacion != IGUAL){
			break;
		}
	}

	return resultadoComparacion;
}

/*todo: hacer Reporte consulta para que pueda comparar 'Horarios'(otra clase del tipo interfax Reporte)
 * por no hacer que hora desde este definida como una franja horaria con horaInicio y horaFin iguales.
 * */
int Reporte::compareTo(Reporte* entidad, int dimension) {
	int resultadoComparacion = -1;
	bool mayor = false;
	bool menor = false;
	bool igual = false;

	switch(dimension){
		case 1:
			 mayor = this->getIdLinea() > entidad->getIdLinea();
			 menor = this->getIdLinea() < entidad->getIdLinea();
			 igual = this->getIdLinea() == entidad->getIdLinea();
			 break;
		case 2:
			mayor = this->getIdFormacion() > entidad->getIdFormacion();
			menor = this->getIdFormacion() < entidad->getIdFormacion();
			igual = this->getIdFormacion() == entidad->getIdFormacion();
			break;
		case 3:
			mayor = this->getIdFalla() > entidad->getIdFalla();
			menor = this->getIdFalla() < entidad->getIdFalla();
			igual = this->getIdFalla() == entidad->getIdFalla();

			break;
		case 4:
		    mayor = this->getIdAccidente() > entidad->getIdAccidente();
		    menor = this->getIdAccidente() < entidad->getIdAccidente();
		    igual = this->getIdAccidente() == entidad->getIdAccidente();

		    break;
		case 5:
			mayor = *this->getFranjaHoraria() > *entidad->getFranjaHoraria();
			menor = *this->getFranjaHoraria() < *entidad->getFranjaHoraria();
			igual = *this->getFranjaHoraria() == *entidad->getFranjaHoraria();

			break;
		default:
			mayor = false;
			menor = false;
			igual = false;
			break;
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

ostream & operator<<(std::ostream & os, const Reporte & reporte){
		  os << reporte.toString();
		  return os;
}
