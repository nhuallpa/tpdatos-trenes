/*
 * SimpleSecondaryIndex.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: carlos
 */

#include "SimpleSecondaryIndex.h"
#include "../logger/Logger.h"
#include "../bplustree/exceptions/ObjectNotfoundException.h"
#include "../utils/StringUtils.h"
#include <assert.h>
SimpleSecondaryIndex::SimpleSecondaryIndex() {

}

void SimpleSecondaryIndex::agregarIdOrdenado(ID idRelacionalAInsertar) {
	vector<ID>::iterator it;
	int sizeOriginal=this->id_relacionales.size();
	if(sizeOriginal==0){
		this->id_relacionales.push_back(idRelacionalAInsertar);
		assert((sizeOriginal+1)==this->id_relacionales.size());
		return;
	}
	for (it = this->id_relacionales.begin(); it != this->id_relacionales.end(); it++) {
		ID el = *it;
		if (idRelacionalAInsertar < el) {
			id_relacionales.insert(it, idRelacionalAInsertar);
			return;
		}
	}
	id_relacionales.push_back(idRelacionalAInsertar);

}

std::string SimpleSecondaryIndex::serialize() {
	std:: string buffer;
	Logger::getInstance()->debug(
			"iniciando serializacion de SimpleSecondaryIndex");
	Logger::getInstance()->debug(
			"iniciando serializacion de SimpleSecondaryIndex.id_relacionalesTamannoVector");
	DataSize tamanioVector = this->id_relacionales.size();
	buffer.append((char*) &tamanioVector, sizeof(DataSize));
	Logger::getInstance()->debug(
			"iniciando serializacion de DistritoElecciones.id_relacionales");
	std::vector<ID>::iterator it = this->id_relacionales.begin();

	while (it != this->id_relacionales.end()) {
		ID idrelacional = *it;
		string mensaje;
		mensaje.append("Seriliazando id: ").append(StringUtils::convertIntToString(idrelacional));
		Logger::getInstance()->debug(mensaje);
		buffer.append((char*) &idrelacional, sizeof(ID));
		it++;
	}

	return buffer;

}

void SimpleSecondaryIndex::removerIdRelacional(ID idRelacional) {
	std::vector<ID>::iterator it = this->id_relacionales.begin();

	for (it = this->id_relacionales.begin(); it != this->id_relacionales.end(); it++) {
		ID el = *it;
		if (idRelacional == el) {
			id_relacionales.erase(it);
			return;
		}
	}
}

ID SimpleSecondaryIndex::findID(ID iD) {
	std::vector<ID>::iterator it = this->id_relacionales.begin();

	for (it = this->id_relacionales.begin(); it != this->id_relacionales.end(); it++) {
		ID el = *it;
		if (iD == el) {
			return el;
		}
	}
	throw ObjectNotfoundException("no se encontro el id en el indice secundaro");
}

int SimpleSecondaryIndex::getDataSize() {
	return sizeof(DataSize) + this->id_relacionales.size() * sizeof(ID);
}

SimpleSecondaryIndex::~SimpleSecondaryIndex() {
}

void SimpleSecondaryIndex::unserialize(std::string & buffer) {
	Logger::getInstance()->debug("inicio deserializacion....");
	DataSize tamanioVector;
	buffer.copy((char*) &tamanioVector, sizeof(DataSize));
	buffer.erase(0, sizeof(DataSize));

	this->id_relacionales.clear();
	ID idRelacional;
	for (int i = 0; i < tamanioVector; i++) {
		buffer.copy((char*) &idRelacional, sizeof(ID));
		buffer.erase(0,sizeof(ID));
		string mensaje;
		this->id_relacionales.push_back(idRelacional);
	}
	Logger::getInstance()->debug("fin deserializacion....");

}

