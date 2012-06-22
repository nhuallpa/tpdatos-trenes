/*
 * Reporte.h
 *
 *  Created on: 23/05/2012
 *      Author: sergio
 */

#ifndef REPORTE_H_
#define REPORTE_H_

#include "../entidades/IEntidad.h"
#include "horario/FranjaHoraria.h"
#include "../utils/StringUtils.h"
#include "../utils/utiles.h"
#include "Dimension.h"

class Reporte: public IEntidad {
private:
	std::vector<Dimension*> dimensions;
	FranjaHoraria* franjaHoraria;
public:
	Reporte();
	Reporte(IEntidad* copy);
	void inicializar(string entrada_reporte);
	int compareTo(IEntidad* entidad);

	virtual ~Reporte();

	Dimension* getDimension(int dimension);

	Dimension* getIdLinea();
	void setIdLinea(int idLinea);

	Dimension* getIdFormacion();
	void setIdFormacion(int idFormacion);

	Dimension* getIdFalla();
	void setIdFalla(int idFalla);

	Dimension* getIdAccidente();
	void setIdAccidente(int idAccidente);

	FranjaHoraria* getFranjaHoraria();
	void setFranjaHoraria(FranjaHoraria* franjaHoraria);

  /**
   * compara con la entidad segun la dimension pasada por parametro. 
   * Las dimensiones posibles son:
   * 1: para la linea
   * 2: para la formacion
   * 3: para la falla
   * 4: para la accidente
   * 5: para la franaja horaria
   *
   * @return
   * 	MAYOR, MENOR, IGUAL indicando segun su nombre valga la redundancia
   */
	int compareTo(Reporte* entidad, int dimension);

	/**
	 * @author nestor
	 * @return devuelve true, si coinciden cada dimension valida una de la otra.
	 *
	 * Ejemplo: (1,2,0,1,0) con (1,2,4,1,8), hay match
	 * */
	bool match(IEntidad* entidad);

	string toString () const;
	
	string serialize();
	void unserialize(string& buffer);

	DataSize getDataSize();

	friend std::ostream & operator<<(std::ostream & os, const Reporte &);

};

#endif /* REPORTE_H_ */
