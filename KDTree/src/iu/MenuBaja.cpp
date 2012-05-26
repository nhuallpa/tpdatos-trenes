/*
 * MenuBaja.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "MenuBaja.h"

MenuBaja::MenuBaja() {
	// TODO Auto-generated constructor stub

}

MenuBaja::~MenuBaja() {
	// TODO Auto-generated destructor stub
}

void MenuBaja::mostrar(){
	cout<<"menu baja::"<<endl;
}

bool MenuBaja::iniciar(){
   this->mostrar();
   cout<<"En proceso de construccion..."<<endl;
   return true;
}

Operacion* MenuBaja::getOperacionElejida(){
	return this->operacionElejida;
}
