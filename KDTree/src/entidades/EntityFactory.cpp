/*
 * EntityFactory.cpp
 *
 *  Created on: Oct 11, 2011
 *      Author: carlos
 */

#include "EntityFactory.h"
#include "../bplustree/exceptions/ProgramException.h"
#include "../utils/StringUtils.h"
EntityFactory::EntityFactory() {

}

EntityFactory::~EntityFactory() {
}


IEntidad* EntityFactory::createEntity(ESTRUCTURAS estructura) {
	IEntidad* entidad = NULL;
	switch (estructura) {
	default:
		string mensaje;

		mensaje.append(
				"Entity Factory No esta configurada la creacion de entidades para la entidad ").append(
				StringUtils::intToString(estructura));
		throw ProgramException(mensaje);
		break;

	}
	return entidad;
}

//Este metodo es solo para el arbol. Lo dejo asi por andar haciendo funciones amigos. Si lo usan mal lo saco.
IEntidad* EntityFactory::createEntity(ESTRUCTURAS type, IElement* element) {
	IEntidad* entidad =NULL;

	entidad=EntityFactory::createEntity(type);
	string serializedElement;

	serializedElement.append(element->getData(), element->getDataSize());// += element->getData();
	entidad->setID(element->getKey());
	entidad->unserialize(serializedElement);
	return entidad;
}
