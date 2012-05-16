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
	FranjaHoraria(Hour horaInicio, Hour horaFin, Date fecha){
		this->horaInicio = horaInicio;
		this->horaFin = horaFin;
		this->fecha = fecha;
	}

	bool intersectaCon(Horario& horario){
		bool intersecta = false;
		if (this->fecha == horario.getFecha() ){
			if (horario.getHora() >= this->horaInicio  && horario.getHora() <= this->horaFin){
				intersecta = true;
			}
		}
		return intersecta;
	}

	friend std::ostream & operator<<(std::ostream & os, const FranjaHoraria & fh){
		  os << setfill('0') << setw(2) << fh.horaInicio << "-" << setfill('0') << setw(2) << fh.horaFin;
		  os << " " << setfill('0') << setw(4)  << fh.fecha;
		  return os;
	}
	virtual ~FranjaHoraria();
};

#endif /* FRANJAHORARIA_H_ */
