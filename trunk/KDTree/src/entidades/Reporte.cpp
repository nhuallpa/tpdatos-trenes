/*
 * Reporte.cpp
 *
 *  Created on: 23/05/2012
 *      Author: sergio
 */

#include "Reporte.h"

#define LINEA 0
#define FORMACION 1
#define FALLA 2
#define ACCIDENTE 3

Reporte::Reporte() {
	dimensions.push_back(new Dimension(1,0));
	dimensions.push_back(new Dimension(2,0));
	dimensions.push_back(new Dimension(3,0));
	dimensions.push_back(new Dimension(4,0));
	this->franjaHoraria = new FranjaHoraria();
}

Reporte::Reporte(IEntidad* copy) {
	dimensions.push_back(new Dimension(1,0));
	dimensions.push_back(new Dimension(2,0));
	dimensions.push_back(new Dimension(3,0));
	dimensions.push_back(new Dimension(4,0));
	this->franjaHoraria = new FranjaHoraria();

	std::string buffer = copy->serialize();
	this->unserialize(buffer);
}

Reporte::~Reporte() {
	delete(dimensions[LINEA]);
	delete(dimensions[FORMACION]);
	delete(dimensions[FALLA]);
	delete(dimensions[ACCIDENTE]);
	delete franjaHoraria;
}

void Reporte::setIdFalla(int idFalla)
{
	this->dimensions[FALLA]->setValue(idFalla);
}
Dimension* Reporte::getIdFalla()
{
	return this->dimensions[FALLA];
}

void Reporte::setIdLinea(int idLinea)
{
	this->dimensions[LINEA]->setValue(idLinea);
}
Dimension* Reporte::getIdLinea()
{
	return this->dimensions[LINEA];
}

void Reporte::setIdFormacion(int idFormacion)
{
	this->dimensions[FORMACION]->setValue(idFormacion);
}
Dimension* Reporte::getIdFormacion()
{
	return this->dimensions[FORMACION];
}

void Reporte::setIdAccidente(int idAccidente)
{
	this->dimensions[ACCIDENTE]->setValue(idAccidente);
}
Dimension* Reporte::getIdAccidente()
{
	return this->dimensions[ACCIDENTE];
}

void Reporte::setFranjaHoraria(FranjaHoraria *franjaHoraria)
{
	this->franjaHoraria->copiar(franjaHoraria);
}

FranjaHoraria* Reporte::getFranjaHoraria()
{
	return this->franjaHoraria;
}

std::string Reporte::serialize()
{
	Serializacion serial;

	serial.addString(this->dimensions[LINEA]->serialize());
	serial.addString(this->dimensions[FORMACION]->serialize());
	serial.addString(this->dimensions[FALLA]->serialize());
	serial.addString(this->dimensions[ACCIDENTE]->serialize());
	serial.addString(this->franjaHoraria->serialize());

	return serial.toString();
}

void Reporte::unserialize(std::string& buffer)
{
	Serializacion serial(buffer);

	std::string strBuffer = serial.getString();
	this->dimensions[LINEA]->unserialize(strBuffer);

	strBuffer = serial.getString();
	this->dimensions[FORMACION]->unserialize(strBuffer);

	strBuffer = serial.getString();
	this->dimensions[FALLA]->unserialize(strBuffer);

	strBuffer = serial.getString();
	this->dimensions[ACCIDENTE]->unserialize(strBuffer);

	strBuffer = serial.getString();
	this->franjaHoraria->unserialize(strBuffer);
}

DataSize Reporte::getDataSize()
{
	return (sizeof(int)*5 + dimensions[LINEA]->getDataSize()*4 + this->franjaHoraria->getDataSize());
}

std::string Reporte::toString() const{

	std::stringstream flujo;
	flujo <<"["<< this-> dimensions[LINEA]->toString() << ", "
		  << this-> dimensions[FORMACION]->toString() <<", "
		  << this->dimensions[FALLA]->toString() <<", "
		  << this->dimensions[ACCIDENTE]->toString() <<", "
		  << *this->franjaHoraria <<"];";
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
	idFalla_string = *(it++);
	this->setIdFalla((idFalla_string.compare(ELEM_TODO) == 0) 		? ELEM_TODO_NUM : StringUtils::convertStringToInt(idFalla_string));
	idAccidente_string = *(it++);
	this->setIdAccidente((idAccidente_string.compare(ELEM_TODO) == 0) 	? ELEM_TODO_NUM : StringUtils::convertStringToInt(idAccidente_string));

	FranjaHoraria* fh = new FranjaHoraria(*it);
	std::string franjaHoraria = fh->serialize();
	this->franjaHoraria->unserialize(franjaHoraria);

	delete fh;
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
		case 2:
		case 3:
		case 4:
		    mayor = this->dimensions[dimension-1]->compareTo(entidad->getDimension(dimension)) == MAYOR;
		    menor = this->dimensions[dimension-1]->compareTo(entidad->getDimension(dimension)) == MENOR;
		    igual = this->dimensions[dimension-1]->compareTo(entidad->getDimension(dimension)) == IGUAL;

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

bool Reporte::match(IEntidad* entidad) {
	// TODO: implementar para el filtrado
	return true;
}


Dimension* Reporte::getDimension(int dimension){
	return this->dimensions[dimension-1];
}

ostream & operator<<(std::ostream & os, const Reporte & reporte){
		  os << reporte.toString();
		  return os;
}
