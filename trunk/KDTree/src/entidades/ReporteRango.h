/*
 * ReporteRango.h
 *
 *  Created on: 07/06/2012
 *      Author: ariel
 */

#ifndef REPORTERANGO_H_
#define REPORTERANGO_H_
#include "Reporte.h"

class ReporteRango: public Reporte{
public:
	ReporteRango();
	virtual ~ReporteRango();
	void inicializar(string entrada_reporte);
	int compareTo(Reporte* entidad, int dimension);
	int compareTo(IEntidad* entidad);
};

#endif /* REPORTERANGO_H_ */
