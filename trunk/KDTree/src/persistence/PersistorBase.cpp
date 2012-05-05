/*
 * PersistorBase.cpp
 *
 */

#include "PersistorBase.h"
#include <iostream>
#include "../logger/Logger.h"
#include "../utils/StringUtils.h"
#include "../bplustree/exceptions/ProgramException.h"
PersistorBase::PersistorBase() {
}

PersistorBase::PersistorBase(std::string fileName, BlockSize size) {

	/* Validacion de que este iniciado */
	if (fileName.length() == 0 || size == 0) {
		string mensaje;
		mensaje.append("el nombre del archivo tiene longitud ").append(
				StringUtils::intToString(fileName.length())).append(
				" y el tamanno es de ").append(StringUtils::convertIntToString(
				size)).append(" por lo tanto esta inicializado el persistor : ").append(
				fileName);
		throw new PersistExceptions::PersistorNotInitializedException(mensaje);
	}

	/* Abre el archivo para lectura - escritura binario */
	this->archivo.open(fileName.c_str(), std::ios::in | std::ios::out
			| std::ios::binary);
	this->blockSize = size;
	this->fileName = fileName;

	if (!this->archivo.is_open()) {
		this->archivo.clear();
		this->newFile(fileName);
	}

	/* Levanta el bloque header */
	char charBuffer[HEADER_SIZE];
	this->archivo.read(charBuffer, HEADER_SIZE);

	BlockSize test;
	memcpy(&test, &charBuffer, sizeof(BlockSize));

	if (test != size)
		throw new PersistExceptions::WrongBlockSize();

	freeSpaceManager = new FreeSpaceManager(fileName + ".fs");
}

PersistorBase::~PersistorBase() {
	this->archivo.close();

	delete freeSpaceManager;
}

void PersistorBase::newFile(std::string fileName) {
	/* crea el archivo */
	archivo.open(fileName.c_str(), std::ios::out | std::ios::binary);
	archivo.close();

	/* reabre el archivo para lectura - escritura binario */
	archivo.open(fileName.c_str(), std::ios::in | std::ios::out
			| std::ios::binary);

	/* verifica que haya podido crear el archivo
	 * de caso contrario arroja una excepción */
	if (!archivo.is_open())
		throw new PersistExceptions::FileNotFoundexception();

	/* Se inicializa el header del archivo. */
	std::string buffer = "";
	buffer.append((char*) &this->blockSize, sizeof(BlockSize));
	buffer.append(HEADER_SIZE - sizeof(BlockSize), '\0');

	/* Se escribe el archivo */
	this->archivo.write(buffer.c_str(), HEADER_SIZE);
	this->archivo.flush();

	this->archivo.seekg(0, std::ios::beg);
}

void PersistorBase::add(Block* block) {
	Offset offset = -1;

	offset = freeSpaceManager->pop();
	block->setOffset(offset);
	string mensaje;
	mensaje.append("PersistorBase.add: agregando el bloque en el offset ").append(
			StringUtils::convertIntToString(offset));
	Logger::getInstance()->debug(mensaje);
	this->modify(block);
}

void PersistorBase::modify(Block* block) {
	/**
	 * verifica que el archivo esta abierto y
	 * arroja una excepcion si no lo esta.
	 * */
	if (!this->archivo.is_open())
		throw new PersistExceptions::FileNotFoundexception();

	/* Se Posiciona en en inicio del Block */
	archivo.seekg((block->getOffset() * blockSize) + HEADER_SIZE);

	/* Obtiene la serializacion y la escibe en el archivo*/
	std::string buffer = block->serialize();

	if (blockSize < buffer.length()) {
		string mensaje;
		mensaje.append(
				"El buffer que se eta intentando guardar supera la capacidad configurada");
		mensaje.append(" blockSize: ").append(StringUtils::convertIntToString(
				blockSize)).append(" bufferSize ").append(
				StringUtils::convertIntToString(buffer.length()));
		throw ProgramException(mensaje);
	}
	buffer.append(blockSize - buffer.length(), '0');

	this->archivo.write(buffer.c_str(), blockSize);
	this->archivo.flush();

	/* chequea si se ha producido un error
	 * arroja una excepción ante la imposibilidad de escribir el reg */
	if (this->archivo.fail())
		throw new PersistExceptions::FailFileWriteException();

	string mensaje;
	mensaje.append("Persisotor Base.modify: persistiendo el bloque ").append(
			StringUtils::convertIntToString(block->getOffset()));
	Logger::getInstance()->debug(mensaje);
}

void PersistorBase::load(Offset key, Block* block) {
	string mensaje;
	mensaje.append("leyendo nodo ").append(StringUtils::convertIntToString(key));
	Logger::getInstance()->info(mensaje);
	std::string temp = this->load(key);
	block->unserialize(temp);
	block->setOffset(key);
}

std::string PersistorBase::load(Offset key) {
	/**
	 * verifica que el archivo esta abierto y
	 * arroja una excepcion si no lo esta.
	 * */
	if (!this->archivo.is_open())
		throw new PersistExceptions::FileNotFoundexception();

	/* Se Posiciona en en inicio del Block */
	if (!freeSpaceManager->isBlockUsed(key))
		throw new PersistExceptions::ElementNotFoundException();

	archivo.seekg((key * blockSize) + HEADER_SIZE);

	/* Levanta el bloque en un string*/
	char* charBuffer = new char[blockSize];
	this->archivo.read(charBuffer, blockSize);

	/* Pasa el charBuffer a un string buffer */
	std::string buffer(charBuffer, blockSize);

	delete[] charBuffer;
	return buffer;
}

void PersistorBase::removeBlock(Offset offset) {
	string mensaje;
	mensaje.append("Nodo macado como libre ").append(
			StringUtils::convertIntToString(offset));
	Logger::getInstance()->info(mensaje);
	freeSpaceManager->push(offset);
}

void PersistorBase::deleteFile() {
	string mensaje;
	mensaje.append(
			"Eliminando el archivo fisico: ").append(fileName);
	Logger::getInstance()->debug(mensaje);
	/* Se limpian los flags y se cierra el archivo*/
	archivo.clear();
	archivo.close();

	/* Se elimina el archivo actual */
	remove(this->fileName.c_str());
	this->freeSpaceManager->deleteFile();
}

void PersistorBase::empty() {
	this->deleteFile();
	this->newFile(this->fileName);
}

unsigned int PersistorBase::size() {
	unsigned int posActual = archivo.tellg();
	archivo.seekg(0, std::ios::end);
	unsigned int result = archivo.tellg();
	archivo.seekg(posActual, std::ios::beg);
	return result;
}

unsigned int PersistorBase::blocks() {
	//return ( (this->size()- HEADER_SIZE) / this->blockSize);
	return this->freeSpaceManager->getUseBlockCount();
}
