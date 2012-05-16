/*
 * Horario.h
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#ifndef HORARIO_H_
#define HORARIO_H_

#include "hour.h"
#include "date.h"

class Horario {
private:
	Hour hora;
	Date fecha;
public:
	Horario();
	Horario(Hour hora, Date fecha){
		this->hora = hora;
		this->fecha = fecha;
	}

	Date getFecha(){
		return this->fecha;
	}

	Hour getHora(){
		return this->hora;
	}
	virtual ~Horario();
};

#endif /* HORARIO_H_ */
