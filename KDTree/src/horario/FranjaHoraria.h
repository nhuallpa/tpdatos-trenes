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
#include "Horario.h"

using namespace std;

#include <iomanip>
#include <sstream>

class FranjaHoraria : public ISerializable {
private:
        Hour horaInicio;
        Hour horaFin;
        Date fecha;
public:
		FranjaHoraria();
		FranjaHoraria(Hour horaInicio, Hour horaFin, Date fecha);
		bool intersectaCon(Horario& horario);
		Hour getHoraInicio() const;
		Hour getHoraFin() const;
		Date getFecha() const;
		friend std::ostream & operator<<(std::ostream & os, const FranjaHoraria & fh);
		virtual ~FranjaHoraria();
	    bool operator<=(FranjaHoraria& unaFranjaHoraria);
	    bool operator>=(FranjaHoraria& unaFranjaHoraria);
	    bool operator==(FranjaHoraria& unaFranjaHoraria);

	void copiar(FranjaHoraria *unaFranjaHoraria);

	std::string serialize();
	void unserialize(std::string& buffer);

	/*
	* Cantidad de bytes que ocupará cuando sea serializado.
	* Es el TOTAL del elemento
	**/
	int getDataSize();
private:
	bool intersectaCompletaCon(FranjaHoraria& unaFranjaHoraria);
};

#endif /* FRANJAHORARIA_H_ */
