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
		bool intersectaCompletaCon(FranjaHoraria& unaFranjaHoraria);
		Hour getHoraInicio() const;
		Hour getHoraFin() const;
		Date getFecha() const;
		friend std::ostream & operator<<(std::ostream & os, const FranjaHoraria & fh);
		virtual ~FranjaHoraria();
	    bool operator<=( const FranjaHoraria& unaFranjaHoraria) const;
	    bool operator>=( const FranjaHoraria& unaFranjaHoraria) const;
	    bool operator==( const FranjaHoraria& unaFranjaHoraria) const;

	void copiar(FranjaHoraria *unaFranjaHoraria);

	std::string serialize();
	void unserialize(std::string& buffer);

	/*
	* Cantidad de bytes que ocupará cuando sea serializado.
	* Es el TOTAL del elemento
	**/
	int getDataSize();
};

#endif /* FRANJAHORARIA_H_ */
