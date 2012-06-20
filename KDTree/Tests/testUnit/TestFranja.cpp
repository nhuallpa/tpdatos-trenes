#include "TestFranja.h"
#include "TestFranjaHoraria.h"

TestFranja::TestFranja(){

}

void TestFranja::iniciar(){

	TestFranjaHoraria testFranjaHoraria;
	testFranjaHoraria.iniciar();

	cout<<"Inicia TestFranja"<<endl;
	Franja* franjaHoraria = new FranjaHoraria("2012030113001300");
	Franja* franjaFecha = new FranjaFecha("20120101", "20120630");
	franjaHoraria->getDataSize();
	franjaFecha->getDataSize();
	cout<<*((FranjaHoraria*)franjaHoraria)<<endl; //TODO: lograr no hacer este casteo

	//TODO(ariel): realizar algunas operaciones de comparaciones entre franjas
	//de tipo horario y fecha para filtrar los resultados de la consulta que devuelve el arbol
	//...luego esto concretarlo en KDTreeController::consultar...

	delete franjaHoraria;
	delete franjaFecha;
}

TestFranja::~TestFranja(){

}
