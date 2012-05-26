/*
 * Reporte.h
 *
 *  Created on: 23/05/2012
 *      Author: sergio
 */

#ifndef REPORTE_H_
#define REPORTE_H_

#include "IEntidad.h"
#include "../horario/FranjaHoraria.h"

class Reporte: public IEntidad {
private:
	int idLinea;
	int idFormacion;
	int idFalla;
	int idAccidente;
	FranjaHoraria* franjaHoraria;
public:
	Reporte();
	Reporte(IEntidad* copy);
	virtual ~Reporte();

	int getIdLinea();
	void setIdLinea(int idLinea);

	int getIdFormacion();
	void setIdFormacion(int idFormacion);

	int getIdFalla();
	void setIdFalla(int idFalla);

	int getIdAccidente();
	void setIdAccidente(int idAccidente);

	FranjaHoraria* getFranjaHoraria();
	void setFranjaHoraria(FranjaHoraria* franjaHoraria);

	bool equals(Reporte* entidad);

	std::string serialize();
	void unserialize(std::string& buffer);

	int getDataSize();

};

#endif /* REPORTE_H_ */
