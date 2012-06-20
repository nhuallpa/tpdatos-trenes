#include "TestFranjaHoraria.h"

TestFranjaHoraria::TestFranjaHoraria(){

}

void TestFranjaHoraria::iniciar(){
	cout<<"Inicia TestFranjaHoraria"<<endl;
//	yyyymmddhhmmhhmm
	FranjaHoraria franja_1("2012040312001300"); //12:00-13:00-03/04/2012
	FranjaHoraria franja_2("2012040312001300"); //12:00-13:00-03/04/2012
	FranjaHoraria franja_3("2012040312001230"); //12:00-12:30-03/04/2012
	FranjaHoraria franja_4("2012040311001130"); //11:00-11:30-03/04/2012
	FranjaHoraria franja_5("2012040412001300"); //12:00-13:00-04/04/2012

	if ( franja_1 == franja_2 ) cout<<"test_1 OK"<<endl;
	if ( franja_3 == franja_1 ) cout<<"test_2 OK"<<endl; //franja_3 esta contenido dentro de franja_1
	if ( franja_1 > franja_4  ) cout<<"test_3 OK"<<endl;
	if ( franja_4 < franja_1  ) cout<<"test_4 OK"<<endl;
	if ( franja_1 < franja_5  ) cout<<"test_5 OK"<<endl;

	FranjaHoraria franja_6("2012040412001200"); //12:00-12:00-04/04/2012
	FranjaHoraria franja_7("2012040412011201"); //12:01-12:01-04/04/2012
	if( ( franja_6 < franja_7 ) && ( franja_7 > franja_6 ) && !( franja_6 == franja_7 ))
		cout<<"test_6 OK"<<endl;
}

TestFranjaHoraria::~TestFranjaHoraria(){

}
