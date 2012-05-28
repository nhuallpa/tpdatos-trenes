/*
 * FranjaHoraria.h
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#ifndef FRANJAHORARIA_H_
#define FRANJAHORARIA_H_

#include "../persistence/ISerializable.h"
#include "hour.h"
#include "date.h"
#include "../utils/types.h"
#include "../utils/StringUtils.h"

#include <iomanip>
#include <sstream>
using namespace std;

/**
 * Comparacion considerando fechas iguales, segun lo que esta en parentesis es una franja horaria y
 * lo que esta entre corchetes es otra franja horaria:
 * [  ( )  ]  esta interseccion indica: ==
 * [   ] ( )  esta interseccion indica: >
 * ( ) [   ]  esta interseccion indica: <
 * [   ( ] )  esta interseccion indica: ==
 * (  [ )  ]  esta interseccion indica: ==
 * (  [  ] )  esta interseccion indica: ==
 * y considerando fechas distintas se usa la fecha para comparar
 *
 */

class FranjaHoraria : public ISerializable {
private:
	Hour* horaInicio;
	Hour* horaFin;
	Date* fecha;
public:
	FranjaHoraria();
	FranjaHoraria(string cadena);
	FranjaHoraria(uint horaInicio, uint minutoInicio,uint horaFin, uint minutoFin, uint dia, uint mes, uint anio);
	Hour* getHoraInicio() const;
	Hour* getHoraFin() const;
	Date* getFecha() const;
	bool operator==(FranjaHoraria& unaFranjaHoraria);
	bool operator<(FranjaHoraria& unaFranjaHoraria);
	bool operator>(FranjaHoraria& unaFranjaHoraria);
	void copiar(FranjaHoraria *unaFranjaHoraria);
	string serialize();
	void unserialize(std::string& buffer);
	//Cantidad de bytes que ocupará cuando sea serializado.Es el TOTAL del elemento
	DataSize getDataSize();

	friend std::ostream & operator<<(std::ostream & os, const FranjaHoraria & fh);
	virtual ~FranjaHoraria();
};

#endif /* FRANJAHORARIA_H_ */
