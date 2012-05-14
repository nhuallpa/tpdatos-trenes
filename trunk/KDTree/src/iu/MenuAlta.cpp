/*
 * MenuAlta.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "MenuAlta.h"

MenuAlta::MenuAlta(KDTreeController& kdTreeController): kdTreeController(kdTreeController){
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

    linea = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(0), this->getController().getLineas());
    formacion = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(1), this->getController().getFormaciones());
    falla = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(2), this->getController().getFallas());
    accidente = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(3), this->getController().getAccidentes());
    franjaHoraria = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(4), this->getController().getFranjasHorarias());

    //TODO tengo que estructurar estos sub elementos en un elemento encapsulado por una interfax
    cout<<"::Datos Insertados::"<<endl;
    cout<<"linea: "<<linea<<endl;
    cout<<"formacion: "<<formacion<<endl;
    cout<<"falla: "<<falla<<endl;
    cout<<"accidente: "<<accidente<<endl;
    cout<<"franjaHoraria: "<<franjaHoraria<<endl;
}

string MenuAlta::elejir_subElemento_segun(string tipo_deSubElemento, list<string>& lista)
{
    this->mostrarLista(lista);
    string nroSubElemento;
    bool valida = true;
    do {
		cout<<"Insertar nro de "<<tipo_deSubElemento<<": ";
		cin>>nroSubElemento;
		valida = this->getController().validarNroSubElemento(tipo_deSubElemento, nroSubElemento);
    } while (!valida);
    UtilMenu::limpiar_pantalla();
    return nroSubElemento;
}

void MenuAlta::mostrarLista(list<string> & lista) {
	list<string>::iterator it;
	for (it=lista.begin(); it!=lista.end(); it++){
		cout<<*it<<endl;
	}
}
