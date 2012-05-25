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
	Horario(Hour hora, Date fecha);
	Date getFecha() const;
	Hour getHora() const;
	virtual ~Horario();
};

#endif /* HORARIO_H_ */
