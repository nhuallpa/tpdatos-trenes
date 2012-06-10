/*
 * TestFranja.h
 *
 *  Created on: 09/06/2012
 *      Author: ariel
 */

#ifndef TESTFRANJA_H_
#define TESTFRANJA_H_

#include "../../src/entidades/horario/Franja.h"
#include "../../src/entidades/horario/FranjaHoraria.h"
#include "../../src/entidades/horario/FranjaFecha.h"

class TestFranja {
public:
	TestFranja(){}
	virtual ~TestFranja(){}
	void iniciar(){
		Franja* franjaHoraria = new FranjaHoraria("2012030113001300");
		Franja* franjaFecha = new FranjaFecha("20120101", "20120301");
		franjaHoraria->getDataSize();
		franjaFecha->getDataSize();
//		cout<<*franjaHoraria<<endl;
	}
};

#endif /* TESTFRANJA_H_ */
