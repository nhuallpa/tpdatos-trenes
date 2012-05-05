/*
 * IEntidad.cpp
 *
 *  Created on: Oct 1, 2011
 *      Author: hordia
 */

#include "IEntidad.h"

IEntidad::IEntidad():id(0){

}

ID IEntidad::getID() const {

	return this->id;
}

void IEntidad::setID(ID id){

	this->id = id;
}

string IEntidad::toString(){
	return "Entidad";
}

IEntidad::~IEntidad(){

}

