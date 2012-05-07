/*
 * MenuAlta.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "MenuAlta.h"

MenuAlta::MenuAlta() {
	// TODO Auto-generated constructor stub
}

MenuAlta::~MenuAlta() {
	// TODO Auto-generated destructor stub
}

void MenuAlta::mostrar(){
    UtilMenu::separador_menu();
    cout<<"menu alta::"<<endl;
    cout<<"1-insertar elemento"<<endl;
    cout<<"2-salir del menu de Altas"<<endl;
}

void MenuAlta::iniciar(){
    bool salir_alta = false;
    while(!salir_alta)
    {
    	this->mostrar();
        char opcion_elejida = '0';
        cout<<"elejir opcion del menu: ";
        cin>>opcion_elejida;
        switch(opcion_elejida){
            case '1' :  UtilMenu::limpiar_pantalla(); this->insertar_elemento(); break;
            case '2' :  UtilMenu::limpiar_pantalla(); salir_alta = true; break;
            default : cout<<"opcion de menu invalida"<<endl; break;
        }
    }
}

void MenuAlta::insertar_elemento()
{
    string linea = "";
    string formacion = "";
    string falla = "";
    string accidente = "";
    string franjaHoraria = "";

    cout<<"Insertar nombre de linea: ";
        cin>>linea;
        UtilMenu::limpiar_pantalla();
    cout<<"Insertar nombre de formacion: ";
        cin>>formacion;
        UtilMenu::limpiar_pantalla();
    cout<<"Insertar nombre de falla: ";
        cin>>falla;
        UtilMenu::limpiar_pantalla();
    cout<<"Insertar nombre de accidente: ";
        cin>>accidente;
        UtilMenu::limpiar_pantalla();
	cout<<"Insertar franja horaria del siniestro: ";
		cin>>franjaHoraria;
		UtilMenu::limpiar_pantalla();

    cout<<"::Datos Insertados::"<<endl;
    cout<<"linea: "<<linea<<endl;
    cout<<"formacion: "<<formacion<<endl;
    cout<<"falla: "<<falla<<endl;
    cout<<"accidente: "<<accidente<<endl;
    cout<<"franjaHoraria: "<<franjaHoraria<<endl;
}

