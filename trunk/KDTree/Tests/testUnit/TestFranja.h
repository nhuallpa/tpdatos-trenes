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
		cout<<"paso_ariel_0"<<endl;
		Franja* franjaFecha = new FranjaFecha("20120101", "20120301");
		cout<<"paso_ariel_1"<<endl;
		franjaHoraria->getDataSize();
		franjaFecha->getDataSize();
		cout<<"paso_ariel_2"<<endl;
//		cout<<*franjaHoraria<<endl;
	}
};

#endif /* TESTFRANJA_H_ */
