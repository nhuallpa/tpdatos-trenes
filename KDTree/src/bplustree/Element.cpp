/*
 * Element.cpp
 *
 */

#include "Element.h"
#include "../utils/utiles.h"
#include "../logger/Logger.h"
#include "../utils/StringUtils.h"
#include "../persistence/Serializacion.h"
#include "../entidades/EntityFactory.h"
#include <iostream>
#include <cstdlib>

//**********************************/
// * Constructores de copia
//**********************************/
Element::Element(const Element& el) {
	data = EntityFactory::createEntity(el.getConstData());
}
Element::Element(const Element* el) {
	data = EntityFactory::createEntity(el->getConstData());
}
//**********************************/
// * Fin de Constructores de copia
//**********************************/

Element::Element() {
	this->data = EntityFactory::createEntity();
}

/**
 * Data es un char* e internamente se copia. El que invoca este constructor debe hacer el delete, si es que corresponde.
 */
Element::Element(IEntidad* copy) {
	data = EntityFactory::createEntity(copy);
}

Element::~Element() {
	delete(data);
}

IEntidad* Element::getData() {
	return data;
}

IEntidad* Element::getConstData() const {
	return data;
}

/**
 * El formato es:
 * KeySize|key|DataSize|data
 */
std::string Element::serialize() {

	std::string buffer = data->serialize();

	Serializacion serial;
	serial.addString(buffer);

	return serial.toString();
}

void Element::unserialize(std::string &buffer) {
	Serializacion serial(buffer);

	std::string tmpBuffer;
	tmpBuffer.append(serial.getString());

	data->unserialize(tmpBuffer);
}

DataSize Element::getDataSize() {
    return ( sizeof(int) + data->getDataSize());
}

ostream& operator<<(ostream& myOstream, Element& elem) {
	string data;
	if (elem.getData() != NULL) { //programacion defensiva
		data.append(elem.serialize());
	}
	myOstream << "Data: " << data << " ";
	return myOstream;
}
