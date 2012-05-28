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
#include "../utils/StringUtils.h"
#include "../utils/utiles.h"

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
	Reporte(string tupla);
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

	//TODO estudiar criterios de compararcion!!! (¡¡¡muy importante!!!)
  /**
   * compara segun 'numCampo'
   */ 
	int compareTo(Reporte* entidad, int numCampo);

	std::string toString () const;
	
	std::string serialize();
	void unserialize(std::string& buffer);

	DataSize getDataSize();

	friend std::ostream & operator<<(std::ostream & os, const Reporte &);

};

#endif /* REPORTE_H_ */
