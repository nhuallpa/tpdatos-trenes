/*
 * FranjaFecha.h
 *
 *  Created on: 09/06/2012
 *      Author: ariel
 */

#ifndef FRANJAFECHA_H_
#define FRANJAFECHA_H_
#include "Franja.h"
#include "date.h"
#include "FranjaHoraria.h"

class FranjaFecha : public Franja{
private:
	Date* fechaDesde;
	Date* fechaHasta;
public:
	FranjaFecha();
	FranjaFecha(string fechaDesde, string fechaHasta);
	virtual ~FranjaFecha();

	Date* getFechaDesde() const {return fechaDesde;}
	void setFechaDesde(Date* fechaDesde) {this->fechaDesde = fechaDesde;}
	Date* getFechaHasta() const {return fechaHasta;}
	void setFechaHasta(Date* fechaHasta) {this->fechaHasta = fechaHasta;}
	//la interpretacion  del resultado es segun lo que esta en el axima de FranjaHoraria
	bool contiene_aFranjaHoraria(FranjaHoraria* unaFranjaHoraria);

	bool operator==(FranjaHoraria& unaFranjaHoraria);
	bool operator<(FranjaHoraria& unaFranjaHoraria);
	bool operator>(FranjaHoraria& unaFranjaHoraria);
	void copiar(FranjaHoraria *unaFranjaHoraria);
	string serialize();
	void unserialize(std::string& buffer);
	//Cantidad de bytes que ocupará cuando sea serializado.Es el TOTAL del elemento
	DataSize getDataSize();

	friend std::ostream & operator<<(std::ostream & os, const FranjaFecha & fh);
};

#endif /* FRANJAFECHA_H_ */
