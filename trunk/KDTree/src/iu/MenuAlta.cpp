/*
 * MenuAlta.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "MenuAlta.h"

MenuAlta::MenuAlta(KDTreeController& kdTreeController){
	this->kdTreeController = kdTreeController;
	this->operacionElejida = new OperacionAlta();
	this->operacion_fueCreada = true;
}

MenuAlta::~MenuAlta() {

}

void MenuAlta::mostrar(){
    UtilMenu::separador_menu();
    cout<<"Menu Alta::"<<endl;
    cout<<"1-elejir elemento para el Alta"<<endl;
    cout<<"2-mostrar el alta"<<endl;
    cout<<"3-salir del menu de Altas"<<endl;
}

bool MenuAlta::iniciar(){
    bool salir_alta = false;
    bool elemento_esElejido = false;
    while(!salir_alta)
    {
    	this->mostrar();
        char opcion_elejida = '0';
        cout<<"elejir opcion del menu: ";
        cin>>opcion_elejida;
        UtilMenu::limpiar_pantalla();
        switch(opcion_elejida){
            case '1' :	{
							this->elejir_elemento();
							elemento_esElejido = true;
							break;
						}
            case '2' :  {
            				if (elemento_esElejido)
            					this->verAlta();
            				else
            					cout<<"debe elejir un elemento"<<endl;
            				break;
            			}
            case '3' :  UtilMenu::limpiar_pantalla(); salir_alta = true; break;
            default : cout<<"opcion de menu invalida"<<endl; break;
        }
    }
    return elemento_esElejido;
}

void MenuAlta::elejir_elemento()
{
    string linea = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(0), this->getController().getLineas());
    string formacion = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(1), this->getController().getFormaciones());
    string falla = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(2), this->getController().getFallas());
    string accidente = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(3), this->getController().getAccidentes());

    // todo: pasar a objeto, sin usar Ids
    string franjaHoraria = this->elejir_subElemento_segun(UtilMenu::getNombreCampo_segun(4), this->getController().getFranjasHorarias());

    //cargo la operacion
    this->operacionElejida->inicializar(linea, formacion, falla, accidente, franjaHoraria);
}

string MenuAlta::elejir_subElemento_segun(string tipo_deSubElemento, list<string>& lista)
{
    this->mostrarLista(lista);
    string nroSubElemento = "";
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

OperacionAlta* MenuAlta::getOperacionElejida(){
	OperacionAlta* operacionVacia = new OperacionAlta();
	if (this->operacion_fueCreada)
		return this->operacionElejida;
	else
		return operacionVacia;
}

KDTreeController& MenuAlta::getController() {
	return this->kdTreeController;
}

void MenuAlta::verAlta(){
	this->operacionElejida->mostrar();
}
