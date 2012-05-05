/*
 * IdGenerator.cpp
 *
 *  Created on: 02/10/2011
 *      Author: rafael
 */

#include "IdGenerator.h"

#include "../bplustree/exceptions/ProgramException.h"
#include "../utils/types.h"
IdGenerator* IdGenerator::instance = 0;

IdGenerator::~IdGenerator() {

	//destruyo el mapa de secuncias
	delete this->secuencias;
}

IdGenerator::IdGenerator() {

	//creo el mapa de secuencias
	this->secuencias = new map<string, int>();
}

void IdGenerator::parseSeqFile(ifstream* seqFile){
	char buffer[MAX_LINE_LENGTH];
	char* seqName;
	int seqLastId;

	//recorro el archivo
	while(!seqFile->eof()){

		//leo una linea
		*seqFile >> buffer;

		//si no termino el archivo cargo el estado de la secuencia correspondiente a esa linea
		if(!seqFile->eof()){

			//obtengo el nombre de la secuencia
			seqName = strtok(buffer, SEQ_FILE_SEPARATOR);

			//obtengo el ultimo id que se obtuvo de la secuencia
			seqLastId = StringUtils::stringToId(strtok(NULL, SEQ_FILE_SEPARATOR));

			//actualizo la secuencia con el último id que produjo
			(*this->secuencias)[seqName] = seqLastId;
		}
	}
}

void IdGenerator::saveSequences(ofstream* seqFile){
	map<string, int>::const_iterator itSeq;

	//recorro las secuencias y por cada una guardo el ultimo id que produjo en el archivo
	for (itSeq = this->secuencias->begin(); itSeq != this->secuencias->end(); ++itSeq)
		*seqFile << itSeq->first << SEQ_FILE_SEPARATOR << itSeq->second << endl;
}

IdGenerator* IdGenerator::getInstance(){

	//si la instancia única todavía no fue creada, la creo
	if(instance == 0){
		instance = new IdGenerator();
		instance->load();
	}

	//devuelvo la instancia única
	return instance;
}

void IdGenerator::destroyInstance(){

	//destruyo la instancia única
	delete instance;

	//anulo el puntero
	instance = NULL;
}

int IdGenerator::getNextId(const string& sequenceName){

	if(sequenceName.size()<=0){
		throw ProgramException("IDGenerator: el nombre de la secuencia es vacio");
	}
	return ++(*this->secuencias)[sequenceName];
}

int IdGenerator::peekNextId(const string& sequenceName){

	//si el nombre de la secuencia esta vacio arrojo una excepcion
	if(sequenceName.size()<=0)
		throw ProgramException("el nombre de la secuencia es vacio");

	return (*this->secuencias)[sequenceName] + 1;
}


bool IdGenerator::load(const string& seqFileName){
	ifstream* seqFile;
	bool ok;

	//inicializo el flag de resultado exitoso en falso
	ok = false;

	//abro el archivo de secuencia
	seqFile = new ifstream(seqFileName.c_str());

	//si lo pude abrir, cargo las secuencias
	if(seqFile->is_open()){

		//parseo el archivo y cargo los estados de las secuencias
		parseSeqFile(seqFile);

		//cierro el archivo
		seqFile->close();

		//actualizo el flag de resultado exitoso
		ok = true;
	}

	//libero la memoria reservada para el ifstream
	delete seqFile;

	//devuelvo el flag de resultado exitoso
	return ok;
}

bool IdGenerator::load(){
	return load(ID_SEQUENCES_FILE);
}

bool IdGenerator::save(const string& seqFileName){
	ofstream* seqFile;
	bool ok;

	//inicializo el flag de resultado exitoso en falso
	ok = false;

	//abro el archivo de secuencias
	seqFile = new ofstream(seqFileName.c_str(), ios::trunc);

	//si lo pude abrir, guardo los estados de las secuencias
	if(seqFile->is_open()){

		//persisto los estados de las secuencias
		saveSequences(seqFile);

		//cierro el archivo
		seqFile->close();

		//actualizo el flag de resultado exitoso
		ok = true;
	}

	//libero la memoria reservada para el ifstream
	delete seqFile;

	//devuelvo el flag de resultado exitoso
	return ok;
}

bool IdGenerator::save(){
	return save(ID_SEQUENCES_FILE);
}

void IdGenerator::reset(const string& seqName){
	(*this->secuencias)[seqName] = 0;
}

void IdGenerator::reset(){
	map<string, int>::const_iterator itSeq;

	//recorro las secuencias y las reseteo
	for (itSeq = this->secuencias->begin(); itSeq != this->secuencias->end(); ++itSeq)
		reset(itSeq->first);
}
