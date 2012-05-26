/*
 * EntityFactory.cpp
 *
 *  Created on: Oct 11, 2011
 *      Author: carlos
 */

#include "EntityFactory.h"
#include "Reporte.h"
#include "../bplustree/exceptions/ProgramException.h"
#include "../utils/StringUtils.h"

EntityFactory::EntityFactory() {

}

EntityFactory::~EntityFactory() {
}


IEntidad* EntityFactory::createEntity() {
	IEntidad* entidad = new Reporte();
	return entidad;
}


IEntidad* EntityFactory::createEntity(IEntidad* toCopy) {
	IEntidad* entidad = new Reporte(toCopy);
	return entidad;
}
