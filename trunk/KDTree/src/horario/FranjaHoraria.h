/*
 * FranjaHoraria.h
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#ifndef FRANJAHORARIA_H_
#define FRANJAHORARIA_H_

#include "hour.h"
#include "date.h"
#include "Horario.h"

#include <iostream>
using namespace std;

#include <iomanip>
#include <sstream>

using std::cerr;
using std::endl;
using std::setw;
using std::setfill;
using std::ostream;
using std::ofstream;
using std::fstream;
using std::string;

class FranjaHoraria {
private:
        Hour horaInicio;
        Hour horaFin;
        Date fecha;
public:
        FranjaHoraria();
        FranjaHoraria(Hour horaInicio, Hour horaFin, Date fecha);
	bool intersectaCon(Horario& horario);
	bool intersectaCompletaCon(FranjaHoraria& unaFranjaHoraria);
	Hour getHoraInicio() const;
	Hour getHoraFin() const;
	Date getFecha() const;
	friend std::ostream & operator<<(std::ostream & os, const FranjaHoraria & fh);
	virtual ~FranjaHoraria();
};

#endif /* FRANJAHORARIA_H_ */
