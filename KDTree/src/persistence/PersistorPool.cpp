/*
 * PersistorPool.cpp
 *
 */

#include "PersistorPool.h"
#include "../utils/StringUtils.h"
#include "../logger/Logger.h"
STRING2PERSISTORBTREE PersistorPool::instances;

PersistorPool::PersistorPool() {

}

void PersistorPool::dropInstance(ESTRUCTURAS estructura) {
	STRING2PERSISTORBTREE::iterator mapIterator;
	mapIterator = PersistorPool::instances.find(estructura);
	string mensaje;
	mensaje.append(
			"Eliminando el persistor del pool correspondiente a la estructura: ").append(
			StringUtils::convertIntToString(estructura));
	Logger::getInstance()->debug(mensaje);
	PersistorPool::getInstance(estructura)->deleteFile();
	if (mapIterator != PersistorPool::instances.end()) {
		instances.erase(mapIterator);
	} else {
		throw ProgramException("no existe el persistor");
	}

}
PersistorBTree* PersistorPool::getInstance(ESTRUCTURAS estructura) {

	STRING2PERSISTORBTREE::iterator mapIterator;
	mapIterator = PersistorPool::instances.find(estructura);
	if (mapIterator != PersistorPool::instances.end()) {
		return (*mapIterator).second;
	} else {
		string mensaje;
		mensaje.append(
				"No se inicializo el persistor correspondiente a la estructura ").append(
				StringUtils::convertIntToString(estructura));
		throw PersistExceptions::PersistorNotInitializedException(mensaje);
	}

}
PersistorPool::~PersistorPool() {
	//TODO eliminar todas las instancias del mapa
}
/**
 * crear la instancia.
 */
void PersistorPool::init(std::string fileName, BlockSize size,
		ESTRUCTURAS estructura) {

	try {
		PersistorPool::getInstance(estructura);
		string mensaje;
		mensaje.append(
				"PersistorPool: Error al obtener el persistor para la estructura: ").
			append(StringUtils::intToString(estructura)).append(" archivo: ").
			append(fileName);
		throw PersistExceptions::PersistorInitializedException(mensaje);
	} catch (PersistExceptions::PersistorNotInitializedException e) {
		STRING2PERSISTORBTREE::iterator mapIterator;
		PersistorBTree* persistor = new PersistorBTree(fileName, size,
				estructura);
		PersistorPool::instances.insert(STRING2PERSISTORBTREE::value_type(
				estructura, persistor));
	}

}

