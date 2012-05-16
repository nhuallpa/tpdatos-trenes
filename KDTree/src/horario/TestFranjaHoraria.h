/*
 * TestFranjaHoraria.h
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#ifndef TESTFRANJAHORARIA_H_
#define TESTFRANJAHORARIA_H_
#include <iostream>

using namespace std;

#include "FranjaHoraria.h"

class TestFranjaHoraria {
public:
	TestFranjaHoraria();
	virtual ~TestFranjaHoraria();

	void iniciar(){
		cout<<"inicia TestFranjaHoraria:"<<endl;

		Hour* horaInicio_siniestro_1 = new Hour(0, 0);
		Hour* horaFin_siniestro_1 = new Hour(0, 30);
		Date* fecha_siniestro_1 = new Date(21, 2, 2012);
		FranjaHoraria* fh_1 = new FranjaHoraria(*horaInicio_siniestro_1, *horaFin_siniestro_1, *fecha_siniestro_1);
		cout<<*fh_1<<endl;

		Hour* horaInicio_siniestro_2 = new Hour(19, 30);
		Hour* horaFin_siniestro_2 = new Hour(20, 0);
		Date* fecha_siniestro_2 = new Date(3, 4, 2012);
		FranjaHoraria* fh_2 = new FranjaHoraria(*horaInicio_siniestro_2, *horaFin_siniestro_2, *fecha_siniestro_2);
		cout<<*fh_2<<endl;

		Date* fecha_1 = new Date(21, 2, 2012);
		Hour* hora_1 = new Hour(0, 25);
		Horario* unHorario = new Horario(*hora_1, *fecha_1);
		if (fh_1->intersectaCon(*unHorario)){
			cout<<"test OK"<<endl;
		}else{
			cout<<"test ERROR"<<endl;
		}
		//TODO cargar

	}
};

#endif /* TESTFRANJAHORARIA_H_ */

