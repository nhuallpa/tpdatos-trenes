/*
 * MenuConsulta.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "MenuConsulta.h"

MenuConsulta::MenuConsulta(KDTreeController& kdTreeController)
{
	this->kdTreeController = kdTreeController;
	this->operacionElejida = new OperacionConsulta();
}

MenuConsulta::~MenuConsulta() {
}

void MenuConsulta::mostrar(){
    UtilMenu::separador_menu();
    cout<<"::menu consulta::"<<endl;
    cout<<"1-crear filtro entrada"<<endl;
    cout<<"2-crear filtro salida"<<endl;
    cout<<"3-mostrar la consulta"<<endl;
    cout<<"4-salir"<<endl;
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

void MenuConsulta::crear_filtroSalida()
{
	////////////////////////////////////////////////////////////////////////////
	cout<<"Los campos posibles son: (";
	cout<<UtilMenu::getNombreSubElemento(0)<<", ";
	cout<<UtilMenu::getNombreSubElemento(1)<<", ";
	cout<<UtilMenu::getNombreSubElemento(2)<<", ";
	cout<<UtilMenu::getNombreSubElemento(3)<<", ";
	cout<<UtilMenu::getNombreSubElemento(4)<<")"<<endl;

	string cant_campos;
	cout<<"Elejir la cantidad de campos utilizados en el resultado de la consulta: ";
	cin>>cant_campos;
	int tamanio_filtroSalida= Util::toInt(cant_campos);
	UtilMenu::limpiar_pantalla();

	////////////////////////////////////////////////////////////////////////////
	this->mostrarMenu_estructuraResultado();
	int nroCampo = 0;
	char opcion_campo_elejido;
	string* filtroSalida = new string[tamanio_filtroSalida];

	while (nroCampo < tamanio_filtroSalida){
		cout<<"elejir el numero de campo "<<nroCampo + 1<<" de "<<tamanio_filtroSalida<<" : ";
        cin>>opcion_campo_elejido;
        switch(opcion_campo_elejido){
            case '1' :   filtroSalida[nroCampo] = UtilMenu::getNombreSubElemento(0); break;
            case '2' :   filtroSalida[nroCampo] = UtilMenu::getNombreSubElemento(1); break;
            case '3' :   filtroSalida[nroCampo] = UtilMenu::getNombreSubElemento(2); break;
            case '4' :   filtroSalida[nroCampo] = UtilMenu::getNombreSubElemento(3); break;
            case '5' :   filtroSalida[nroCampo] = UtilMenu::getNombreSubElemento(4); break;
            default : cout<<"opcion de menu invalida"<<endl; break;
        }
        nroCampo++;
	}
	UtilMenu::limpiar_pantalla();
	this->operacionElejida->inicializar_filtroSalida(filtroSalida, tamanio_filtroSalida);
}

void MenuConsulta::crear_filtroEntrada()
{
	int tamanio_filtroEntrada = 1;
	string* filtroEntrada = new string[tamanio_filtroEntrada];
	filtroEntrada[0] = "en construccion";

	UtilMenu::limpiar_pantalla();
	////////////////////////////////////////////////////////////////////////////
	this->operacionElejida->inicializar_filtroEntrada(filtroEntrada, tamanio_filtroEntrada);
}

bool MenuConsulta::iniciar(){
    bool salir_consulta = false;
    bool filtroEntrada_esCreado= false;
    bool filtroSalida_esCreado= false;
    while(!salir_consulta)
    {
    	this->mostrar();
        char opcion_elejida = '0';
        cout<<"elejir opcion del menu: ";
        cin>>opcion_elejida;
        UtilMenu::limpiar_pantalla();
        switch(opcion_elejida){
            case '1' :  {
							this->crear_filtroEntrada();
							filtroEntrada_esCreado = true;
							break;
            			}
            case '2' :  {
            				this->crear_filtroSalida();
            				filtroSalida_esCreado = true;
            				break;
            			}
            case '3' :  {
							if (filtroEntrada_esCreado && filtroSalida_esCreado){
								//TODO implementar OperacionConsulta::inicializacion
								cout<<*this->operacionElejida<<endl;
							}
							else{
								if (!filtroEntrada_esCreado)
									cout<<"debe crear el filtro de entrada"<<endl;
								if (!filtroSalida_esCreado)
									cout<<"debe crear el filtro de salida"<<endl;
								}

							break;
            			}
            case '4' :  salir_consulta = true; break;
            default : cout<<"opcion de menu invalida"<<endl; break;
        }
    }
    return (filtroEntrada_esCreado && filtroSalida_esCreado);
}

OperacionConsulta* MenuConsulta::getOperacionElejida(){
	OperacionConsulta* operacionVacia = new OperacionConsulta();
	if (this->operacion_fueCreada)
		return this->operacionElejida;
	else
		return operacionVacia;
}

