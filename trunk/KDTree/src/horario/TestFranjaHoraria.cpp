
/*
 * TestFranjaHoraria.cpp
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#include "TestFranjaHoraria.h"

TestFranjaHoraria::TestFranjaHoraria()
{
	this->cant_listar = 3;
}

TestFranjaHoraria::~TestFranjaHoraria()
{

}

void TestFranjaHoraria::cargarFranjasHorarias_mediante(const char* arch_franjasHorarias){
	char buffer[SIZE_LINEA_LEVANTAR];
    ifstream in;
	in.open(arch_franjasHorarias, ifstream::in);
	if (in.is_open()){
		list<FranjaHoraria*>::iterator it;
		while ( !in.eof() ){
			in.getline(buffer, SIZE_LINEA_LEVANTAR);
			if (in.good()) {
				string bufString(buffer);
				FranjaHoraria* fh  = this->deserealizarFranjaHoraria_segun(bufString);
				this->franjasHorarias.push_back(fh);
			}
		}
		in.close();
	} else{
    	cout<<"No se abrio: "<<arch_franjasHorarias<<endl;
	}
}

void TestFranjaHoraria::listarFranjasHorarias_segun(int cant_listar){
	list<FranjaHoraria*>::iterator itFranjasHorarias;
	int cont_listados = 0;
	for (itFranjasHorarias=this->franjasHorarias.begin(); itFranjasHorarias!=this->franjasHorarias.end() && cont_listados < cant_listar; itFranjasHorarias++){
		cout<<**itFranjasHorarias<<endl;
		cont_listados++;
	}
}

void TestFranjaHoraria::iniciar(){

		FranjaHoraria* franja_1 = new FranjaHoraria(12,0,13,0, 3,4,2012); //12:00-13:00-03/04/2012
		FranjaHoraria* franja_2 = new FranjaHoraria(12,0,13,0, 3,4,2012); //12:00-13:00-03/04/2012
		FranjaHoraria* franja_3 = new FranjaHoraria(12,0,12,30,3,4,2012); //12:00-12:30-03/04/2012
		FranjaHoraria* franja_4 = new FranjaHoraria(11,0,11,30,3,4,2012); //11:00-11:30-03/04/2012
		FranjaHoraria* franja_5 = new FranjaHoraria(12,0,13,0, 4,4,2012); //12:00-13:00-04/04/2012

		if ( *franja_1 == *franja_2 ) cout<<"test_1 OK"<<endl;
		if ( *franja_3 == *franja_1 ) cout<<"test_2 OK"<<endl; //franja_3 esta contenido dentro de franja_1
		if ( *franja_1 > *franja_4  ) cout<<"test_3 OK"<<endl;
		if ( *franja_4 < *franja_1  ) cout<<"test_4 OK"<<endl;
		if ( *franja_1 < *franja_5  ) cout<<"test_5 OK"<<endl;

		this->cargarFranjasHorarias_mediante((const char*)ARCH_FRANJAS_HORARIAS);

		cout<<"Primeros "<<this->cant_listar<<" del archivo franjas_horarias.org: "<<endl;
		this->listarFranjasHorarias_segun(this->cant_listar);


		delete franja_1;
		delete franja_2;
		delete franja_3;
		delete franja_4;
		delete franja_5;

		cout<<"Pruebas en post de seguir completando test_consultas.sh:"<<endl;

		FranjaHoraria* franja_6 = new FranjaHoraria(12,0,12,0, 4,4,2012);
		FranjaHoraria* franja_7 = new FranjaHoraria(12,1,12,1, 4,4,2012);
		if( ( *franja_6 < *franja_7 ) && ( *franja_7 > *franja_6 ) && !( *franja_6 == *franja_7 )) cout<<"test_6 OK"<<endl;

		delete franja_6;
		delete franja_7;
	}

FranjaHoraria* TestFranjaHoraria::deserealizarFranjaHoraria_segun(string lineaArchivo)
{
	uint offset_id = 3;
	uint anio = 			Util::toInt(lineaArchivo.substr(0+offset_id, 4));
	uint mes = 				Util::toInt(lineaArchivo.substr(4+offset_id, 2));
	uint dia = 				Util::toInt(lineaArchivo.substr(6+offset_id, 2));
	uint horaInicio = 		Util::toInt(lineaArchivo.substr(9+offset_id, 2));
	uint minutoInicio = 	Util::toInt(lineaArchivo.substr(11+offset_id,2));
	uint horaFin = 			Util::toInt(lineaArchivo.substr(14+offset_id,2));
	uint minutoFin = 		Util::toInt(lineaArchivo.substr(16+offset_id,2));

	FranjaHoraria* franjaDesformateada = new FranjaHoraria(horaInicio, minutoInicio, horaFin, minutoFin, dia, mes, anio);

	return franjaDesformateada;
}
