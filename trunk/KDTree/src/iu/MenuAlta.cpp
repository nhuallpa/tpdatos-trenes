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

bool MenuAlta::iniciar(){
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
							this->elejir_elemento();
							this->operacion_fueCreada = true;
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
    return this->operacion_fueCreada;
}

void MenuAlta::elejir_elemento()
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
}

int MenuAlta::elejir_subElemento(string tipo_deSubElemento, list<string>& lista)
{
    this->mostrarLista(lista);
    string idSubElemento;
    int idSubElemento_num;
    bool valida = true;
    do {
		cout<<"Insertar nro de "<<tipo_deSubElemento<<": ";
		cin>>idSubElemento;
		idSubElemento_num = Util::toInt(idSubElemento);
		valida = this->getController().validarIdSubElemento(tipo_deSubElemento, idSubElemento_num);
    } while (!valida);
    UtilMenu::limpiar_pantalla();
    return idSubElemento_num;
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
