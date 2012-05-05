/*
 * IStrutureBTreeImpl.cpp
 *
 *  Created on: Oct 1, 2011
 *      Author: carlos
 */

#include "IStrutureBTreeImpl.h"
#include "../../src/utils/const.h"
#include "../persistence/IdGenerator.h"
#include "../utils/StringUtils.h"
#include "../entidades/EntityFactory.h"
#include "../bplustree/ElementFactory.h"
#include "../logger/Logger.h"
#include "../utils/ConfigurationMannagerPool.h"
IStrutureBTreeImpl::IStrutureBTreeImpl(ESTRUCTURAS estructura) :
	IStructure(estructura) {
	ConfigurationMananger* c = ConfigurationMannagerPool::getInstance(
			estructura);
	this->bplusTree = new BPlusTree(c->getBufferSizeTree(), c->getFilename(),
			estructura);

	this->hojaActual = NULL;
}

IStrutureBTreeImpl::~IStrutureBTreeImpl() {
	delete this->bplusTree;
}

IEntidad *IStrutureBTreeImpl::find(ID key) {
	//Un nodo tiene muchas IEntidad. Buscamos la entidad a ver si esta
	try {
		Element* element = (Element*) this->bplusTree->findExact(key);
		IEntidad* entidad = EntityFactory::createEntity(
				element->getEstructura(), element);
		return entidad;

	} catch (ElementNotFoundException* e) {
		//todo revisar que no arroje un new
		delete e;
		return NULL;
	}
}

int IStrutureBTreeImpl::insert(IEntidad *entidad) {

	//como yo en el arbol guardo key,string, convierto la key de la entidad y el vector a string


	ConfigurationMananger* c = ConfigurationMannagerPool::getInstance(
			this->getEstructura());
	if (entidad->getID() == 0) {
		entidad->setID(IdGenerator::getInstance()->getNextId(
				c->getSequenceName()));
	} else {
		string mensaje;
		mensaje.append("IStructure BTree ").append(
				ConfigurationMannagerPool::getStructureName(
						this->getEstructura())).append(
				"esta insertando un elemento con identificador: ").append(
				StringUtils::convertIntToString(entidad->getID()));
		Logger::getInstance()->warn(mensaje);
		this->allowException(string("IStructureBTreeImpl").append(mensaje));
	}
	Element* element = ElementFactory::createElement(this->getEstructura(),
			entidad->getID(), entidad);

	try {
		this->bplusTree->insert(element);

	} catch (ElementAlreadyExists e) {
		return 1;
	}

	return 0;
}

void IStrutureBTreeImpl::allowException(string mensaje) {
	//TERRIBLE HACKKK
	//TODO FIXME!!!! Hay una entidad no autoincremental. Hay que crear IStructures con esa particularidad o configurables para soportarlo
}

int IStrutureBTreeImpl::modify(IEntidad *entidad) {

	Element* el = ElementFactory::createElement(this->getEstructura(),
			entidad->getID(), entidad);
	//todo trycatchear la exception
	this->bplusTree->modify(el);
	return 0;

}

int IStrutureBTreeImpl::remove(ID key) {

	this->bplusTree->remove(key);
	return 0;
}

void IStrutureBTreeImpl::toString() {
	this->bplusTree->exportTree();
}

/**
 * El buscar en el nodo el siguiente por id. Si no hay nodo, buscar un nuevo nodo.
 */
IEntidad* IStrutureBTreeImpl::siguiente() {
	//todo probeme!!!
	IElement * ielement = NULL;
	if (this->hojaActual == NULL) {
		this->hojaActual = this->bplusTree->next();
		ielement = this->hojaActual->nextElement();
		if (ielement == NULL) {//no hay mas elementos en esta hoja voy a la siguiente si hay
			if (this->hojaActual->getNextNode() == -1) {
				return NULL;
			}

			this->hojaActual = this->bplusTree->next();
		}
	}

	return EntityFactory::createEntity(this->getEstructura(), ielement);
}

void IStrutureBTreeImpl::dropStructure() {
	this->bplusTree->deleteTree();
}

