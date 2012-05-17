/*
 * TestFranjaHoraria.h
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#ifndef TESTFRANJAHORARIA_H_
#define TESTFRANJAHORARIA_H_
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdlib.h>
#include "../utils/const.h"

#define SIZE 64
using namespace std;

#include "FranjaHoraria.h"

class TestFranjaHoraria {
private:
	bool verResultadoDetallado;
	list<FranjaHoraria*> franjasHorarias;

public:
	TestFranjaHoraria();

	virtual ~TestFranjaHoraria();

	void cargarFranjasHorarias_mediante(const char* arch_franjasHorarias){
		char buffer[SIZE];
	    string cod;
	    ifstream in(arch_franjasHorarias, ios::in);
	    if (in)
	    	cout<<"abrio bien"<<endl;
	    list<FranjaHoraria*>::iterator it; //20120320-1200-2400
	    int cont = 0;
	    while (!in.eof() && cont < 2){
	    	cont++;
			in.getline(buffer, SIZE);
			//TODO corregir por aca ya que no entra a este if
			if (in.good()) {
				//logica  de desformateo de la franja Horaria
				string bufString(buffer);
				int anio = atoi(bufString.substr(0,3).c_str());
				int mes = atoi(bufString.substr(4,5).c_str());
				int dia = atoi(bufString.substr(6,7).c_str());
				int horaInicio_ = atoi(bufString.substr(9,10).c_str());
				int minutoInicio = atoi(bufString.substr(11,12).c_str());
				int horaFin_ = atoi(bufString.substr(14,15).c_str());
				int minutoFin = atoi(bufString.substr(16,17).c_str());

				Hour* horaInicio = new Hour(horaInicio_, minutoInicio);
				Hour* horaFin = new Hour(horaFin_, minutoFin);
				Date* fecha = new Date(dia, mes, anio);
				FranjaHoraria* fh = new FranjaHoraria(*horaInicio, *horaFin, *fecha);

				this->franjasHorarias.push_back(fh);
			}
		}
	    in.close();
	}

	void listarFranjasHorarias(){
		list<FranjaHoraria*>::iterator itFranjasHorarias;
		for (itFranjasHorarias=this->franjasHorarias.begin(); itFranjasHorarias!=this->franjasHorarias.end(); itFranjasHorarias++){
			cout<<*itFranjasHorarias<<endl;
		}
	}
	void iniciar(){

		this->verResultadoDetallado = true;

		cout<<"inicia TestFranjaHoraria:"<<endl;
		///////////////////////////////////////////////////////////////////////////////
		Hour* horaInicio_siniestro_1 = new Hour(0, 0);
		Hour* horaFin_siniestro_1 = new Hour(0, 30);
		Date* fecha_siniestro_1 = new Date(21, 2, 2012);
		FranjaHoraria* fh_1 = new FranjaHoraria(*horaInicio_siniestro_1, *horaFin_siniestro_1, *fecha_siniestro_1);

		Date* fecha_1 = new Date(21, 2, 2012);
		Hour* hora_1 = new Hour(0, 25);
		Horario* unHorario = new Horario(*hora_1, *fecha_1);
		if (fh_1->intersectaCon(*unHorario)){
			cout<<"test_1 OK"<<endl;
		}else{
			cout<<"test_1 ERROR"<<endl;
		}

		///////////////////////////////////////////////////////////////////////////////
		Hour* horaInicio_siniestro_3 = new Hour(12, 0);
		Hour* horaInicio_siniestro_4 = new Hour(12, 0);
		Hour* horaFin_siniestro_3 = new Hour(12, 30);
		Hour* horaFin_siniestro_4 = new Hour(13, 0);
		Date* fecha_siniestro_3 = new Date(3, 4, 2012);
		Date* fecha_siniestro_4 = new Date(3, 4, 2012);
		FranjaHoraria* fh_3 = new FranjaHoraria(*horaInicio_siniestro_3, *horaFin_siniestro_3, *fecha_siniestro_3);
		FranjaHoraria* fh_4 = new FranjaHoraria(*horaInicio_siniestro_4, *horaFin_siniestro_4, *fecha_siniestro_4);

		if (fh_3->intersectaCompletaCon(*fh_4)){
			cout<<"test_2 OK"<<endl;
			if (this->verResultadoDetallado){
				cout<<"franja horaria contenida: \t"<<*fh_3<<endl;
				cout<<"franja horaria contenedora: \t"<<*fh_4<<endl;
			}
		}else{
			cout<<"test_2 ERROR"<<endl;
		}

		///////////////////////////////////////////////////////////////////////////////
		horaInicio_siniestro_3 = new Hour(12, 0);
		horaInicio_siniestro_4 = new Hour(12, 0);
		horaFin_siniestro_3 = new Hour(13, 0);
		horaFin_siniestro_4 = new Hour(13, 0);
		fecha_siniestro_3 = new Date(3, 3, 2012);
		fecha_siniestro_4 = new Date(4, 4, 2012);
		fh_3 = new FranjaHoraria(*horaInicio_siniestro_3, *horaFin_siniestro_3, *fecha_siniestro_3);
		fh_4 = new FranjaHoraria(*horaInicio_siniestro_4, *horaFin_siniestro_4, *fecha_siniestro_4);

		if (fh_3->intersectaCompletaCon(*fh_4)){
			cout<<"test_3 ERROR"<<endl;
		}else{
			cout<<"test_3 ok"<<endl;
			if (this->verResultadoDetallado){
				cout<<"franja horaria contenida: \t"<<*fh_3<<endl;
				cout<<"franja horaria contenedora: \t"<<*fh_4<<endl;
			}
		}

		///////////////////////////////////////////////////////////////////////////////
		horaInicio_siniestro_3 = new Hour(12, 0);
		horaInicio_siniestro_4 = new Hour(12, 30);
		horaFin_siniestro_3 = new Hour(13, 0);
		horaFin_siniestro_4 = new Hour(13, 30);
		fecha_siniestro_3 = new Date(3, 3, 2012);
		fecha_siniestro_4 = new Date(3, 3, 2012);
		fh_3 = new FranjaHoraria(*horaInicio_siniestro_3, *horaFin_siniestro_3, *fecha_siniestro_3);
		fh_4 = new FranjaHoraria(*horaInicio_siniestro_4, *horaFin_siniestro_4, *fecha_siniestro_4);

		if (fh_3->intersectaCompletaCon(*fh_4)){
			cout<<"test_4 ERROR"<<endl;
		}else{
			cout<<"test_4 ok"<<endl;
			if (this->verResultadoDetallado){
				cout<<"franja horaria contenida: \t"<<*fh_3<<endl;
				cout<<"franja horaria contenedora: \t"<<*fh_4<<endl;
			}
		}

		//para probar la cargar desde el archivo
		this->cargarFranjasHorarias_mediante((const char*)ARCH_FRANJAS_HORARIAS);
		this->listarFranjasHorarias();

	}
};

#endif /* TESTFRANJAHORARIA_H_ */

