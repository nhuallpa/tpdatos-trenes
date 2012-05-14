/*
 * MenuConsulta.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "MenuConsulta.h"

MenuConsulta::MenuConsulta()
{
	// TODO Auto-generated destructor stub
}

MenuConsulta::~MenuConsulta() {
	// TODO Auto-generated destructor stub
}

void MenuConsulta::mostrar(){
    UtilMenu::separador_menu();
    cout<<"::menu consulta::"<<endl;
    cout<<"1-crear estructura de resultado"<<endl;
    cout<<"2-crear filtro de consulta"<<endl;
    cout<<"3-mostrar formato de consulta"<<endl;
    cout<<"4-ejecutar consulta"<<endl;
    cout<<"5-salir"<<endl;
}

void MenuConsulta::mostrarMenu_estructuraResultado(){
    UtilMenu::separador_menu();
	cout<<"menu de numero campos posibles para la creacion estructura del resultado de la consulta::"<<endl;
	cout<<"1-linea"<<endl;
	cout<<"2-formacion"<<endl;
	cout<<"3-falla"<<endl;
	cout<<"4-accidente"<<endl;
	cout<<"5-franja horaria del siniestro"<<endl;
}

void MenuConsulta::crearEstructura_deResulado()
{
	////////////////////////////////////////////////////////////////////////////
	cout<<"Los campos posibles son: (";
	cout<<UtilMenu::getNombreCampo_segun(0)<<", ";
	cout<<UtilMenu::getNombreCampo_segun(1)<<", ";
	cout<<UtilMenu::getNombreCampo_segun(2)<<", ";
	cout<<UtilMenu::getNombreCampo_segun(3)<<", ";
	cout<<UtilMenu::getNombreCampo_segun(4)<<")"<<endl;

	string cant_campos;
	cout<<"Elejir la cantidad de campos utilizados en el resultado de la consulta: ";
	cin>>cant_campos;
	this->cant_campos_enResultado = atoi(cant_campos.c_str());
	UtilMenu::limpiar_pantalla();

	////////////////////////////////////////////////////////////////////////////
	this->mostrarMenu_estructuraResultado();
	int nroCampo = 0;
	char opcion_campo_elejido;
	this->estructura_resultado = new string[this->cant_campos_enResultado];

	while (nroCampo < this->cant_campos_enResultado){
		cout<<"elejir el numero de campo "<<nroCampo + 1<<" de "<<cant_campos_enResultado<<" : ";
        cin>>opcion_campo_elejido;
        switch(opcion_campo_elejido){
            case '1' :   this->estructura_resultado[nroCampo] = UtilMenu::getNombreCampo_segun(0); break;
            case '2' :   this->estructura_resultado[nroCampo] = UtilMenu::getNombreCampo_segun(1); break;
            case '3' :   this->estructura_resultado[nroCampo] = UtilMenu::getNombreCampo_segun(2); break;
            case '4' :   this->estructura_resultado[nroCampo] = UtilMenu::getNombreCampo_segun(3); break;
            case '5' :   this->estructura_resultado[nroCampo] = UtilMenu::getNombreCampo_segun(4); break;
            default : cout<<"opcion de menu invalida"<<endl; break;
        }
        nroCampo++;
	}
	UtilMenu::limpiar_pantalla();

	////////////////////////////////////////////////////////////////////////////
	cout<<"La estructura del resultado de la consulta es:"<<endl;
	UtilMenu::verEstructraResultado(this->estructura_resultado, this->cant_campos_enResultado);
	cout<<endl;
}

void MenuConsulta::crearFiltro_deConsulta()
{
	//TODO filtro en proceso de construccion
	this->cant_campos_enFiltro = 0;
	this->estructura_filtro = new string[this->cant_campos_enFiltro];
	UtilMenu::limpiar_pantalla();

	////////////////////////////////////////////////////////////////////////////
	cout<<"Crear filtro de consulta: en proceso de construccion..."<<endl;
}

void MenuConsulta::verConsulta(){
	cout<<"El formato de la consulta es(tipo MySql):"<<endl;
	cout<<"SELECT ";
	if (this->cant_campos_enResultado < 1)
		cout<<"* ";
	else
		UtilMenu::verEstructraResultado(this->estructura_resultado, this->cant_campos_enResultado);
	cout<<"FROM tabla-arbolKD WHERE ";
	if (this->cant_campos_enFiltro < 1)
		cout<<"1";
	else
		UtilMenu::verEstructuraFiltro(this->estructura_filtro, this->cant_campos_enFiltro);
	cout<<";"<<endl;
}

void MenuConsulta::ejecutar_consulta()
{
	//TODO implementar
	cout<<"Ejecutar consulta:  en proceso de construccion..."<<endl;
}

void MenuConsulta::iniciar(){
    bool salir_consulta = false;
    while(!salir_consulta)
    {
    	this->mostrar();
        char opcion_elejida = '0';
        cout<<"elejir opcion del menu: ";
        cin>>opcion_elejida;
        switch(opcion_elejida){
            case '1' :  UtilMenu::limpiar_pantalla(); this->crearEstructura_deResulado(); break;
            case '2' :  UtilMenu::limpiar_pantalla(); this->crearFiltro_deConsulta(); break;
            case '3' :  UtilMenu::limpiar_pantalla(); this->verConsulta(); break;
            case '4' :  UtilMenu::limpiar_pantalla(); this->ejecutar_consulta(); break;
            case '5' :  UtilMenu::limpiar_pantalla(); salir_consulta = true; break;
            default : cout<<"opcion de menu invalida"<<endl; break;
        }
    }

}

