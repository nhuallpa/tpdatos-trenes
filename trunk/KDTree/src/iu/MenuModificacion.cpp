/*
 * MenuModificacion.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "MenuModificacion.h"

MenuModificacion::MenuModificacion() {
	// TODO Auto-generated constructor stub

}

MenuModificacion::~MenuModificacion() {
	// TODO Auto-generated destructor stub
}

void MenuModificacion::mostrar(){
	cout<<"menu modificacion::"<<endl;
}
void MenuModificacion::iniciar(){
   this->mostrar();
   cout<<"En proceso de construccion..."<<endl;
}

Operacion* MenuModificacion::getOperacionElejida(){
	return this->operacionElejida;
}

bool MenuModificacion::getOperacion_fueCreada(){
	return this->operacion_fueCreada;
}
