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
	this->operacion_fueCreada = false;
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

void MenuAlta::iniciar(){
    bool salir_alta = false;
    while(!salir_alta)
    {
    	this->mostrar();
        char opcion_elejida = '0';
        cout<<"elejir opcion del menu: ";
        cin>>opcion_elejida;
        UtilMenu::limpiar_pantalla();
        switch(opcion_elejida){
            case '1' :	{
							this->crearOperacion();
							break;
						}
            case '2' :  {
            				if (this->operacion_fueCreada)
            					cout<<*this->operacionElejida<<endl;
            				else
            					cout<<"debe elejir un elemento"<<endl;
            				break;
            			}
            case '3' :  salir_alta = true; break;
            default : cout<<"opcion de menu invalida"<<endl; break;
        }
    }
}

void MenuAlta::crearOperacion()
{
    int idLinea = this->elejir_subElemento(UtilMenu::getNombreSubElemento(0), this->getController().getLineas());
    int idFormacion = this->elejir_subElemento(UtilMenu::getNombreSubElemento(1), this->getController().getFormaciones());
    int idFalla = this->elejir_subElemento(UtilMenu::getNombreSubElemento(2), this->getController().getFallas());
    int idAccidente = this->elejir_subElemento(UtilMenu::getNombreSubElemento(3), this->getController().getAccidentes());
//    int idFranjaHoraria = this->elejir_subElemento(UtilMenu::getNombreSubElemento(4), this->getController().getFranjasHorarias());

    //TODO: cargar franja horaria segun su id
    FranjaHoraria* unaFranjaHoraria = new FranjaHoraria(12,0,13,0,1,1,2012);
    //...

    //cargo la operacion
    this->operacionElejida->inicializar(idLinea, idFormacion, idFalla, idAccidente, unaFranjaHoraria);
    this->operacion_fueCreada = true;
}

int MenuAlta::elejir_subElemento(string tipo_deSubElemento, list<string>& lista)
{
	int idSubElemento = UtilMenu::elejir_subElemento_(tipo_deSubElemento, lista, this->kdTreeController);

    return idSubElemento;
}

OperacionAlta* MenuAlta::getOperacionElejida(){
		return this->operacionElejida;
}

bool MenuAlta::getOperacion_fueCreada(){
	return this->operacion_fueCreada;
}

KDTreeController& MenuAlta::getController() {
	return this->kdTreeController;
}

