/*
 * IEntidad.cpp
 *
 *  Created on: Oct 1, 2011
 *      Author: hordia
 */

#include "IEntidad.h"

IEntidad::IEntidad(){

}

string IEntidad::toString(){
	return "Entidad";
}

IEntidad::~IEntidad(){
}

std::string IEntidad::serialize(){
	throw "Esta clase no deberia ser instanciada nunca";
	return "";
}

void IEntidad::unserialize(std::string& buffer) {

}
