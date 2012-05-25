/*
 * StringUtils.cpp
 *
 *  Created on: Oct 2, 2011
 *      Author: carlos
 */

#include "StringUtils.h"

string StringUtils::intToString(int value) {
	std::stringstream out;
	out << value;
	return out.str();
}

StringUtils::StringUtils() {}

StringUtils::~StringUtils() {}

string StringUtils::converFloatToString(float numero) {
	char* str = new char[30];

	sprintf(str, "%.4g", numero);
	return string(str);
}

string StringUtils::convertIntToString(int numero) {

	string retorno;
	int temp;
	int tempCountFiles = numero;

	while ((tempCountFiles / 10) != 0) {
		temp = tempCountFiles % 10;
		tempCountFiles = tempCountFiles / 10;
		temp = temp + 48;
		retorno = (char) temp + retorno;
	}

	tempCountFiles = tempCountFiles + 48;
	retorno = (char) tempCountFiles + retorno;
	return retorno;
}

std::string StringUtils::convertirAString(int numero) {
	std::stringstream flujo;
	flujo << numero;
	return flujo.str();
}

string StringUtils::trim(const string& str){
	string auxStr;

	//recorro los caracteres y extraigo todos los que no son espacios para copiarlos al nuevo string
	for(int i = 0; i < ((int)str.length()); i++)
		if(str[i] != SPACE_CHAR)
			auxStr += str[i];

	//devuelvo el string creado
	return auxStr;
}

list<ID>* StringUtils::extractIDs(const string& strIdSet){
	list<ID>* idList;
	char* token;
	char* auxStr;

	//creo una lista para insertar los ids
	idList = new list<ID>();

	//creo un string auxiliar en estilo c
	auxStr = new char[strIdSet.length() + 1];

	//copio el string compuesto por ids al string auxiliar
	strcpy(auxStr, strIdSet.c_str());

	//parseo el primer id
	token = strtok(auxStr, ID_SEPARATOR);

	//lo convierto a entero y lo inserto en la lista
	idList->push_front(StringUtils::stringToId(token));

	//parseo el resto de los ids
	while( ( token = strtok(NULL, ID_SEPARATOR) ) != NULL)
		idList->push_front(StringUtils::stringToId(token));

	//devuelvo la lista
	return idList;
}

string StringUtils::glueIds(const vector<ID>& ids){
	vector<ID>::const_iterator itIds;
	string gluedIds;

	//obtengo un iterador
	itIds = ids.begin();

	//inserto el primer id
	if(itIds != ids.end())
		gluedIds += StringUtils::idToString(*itIds);

	//inserto el resto de los ids
	while(++itIds != ids.end())
		gluedIds += ", " + StringUtils::idToString(*itIds);

	//devuelvo los ids pegados
	return gluedIds;
}

ID StringUtils::stringToId(const string& str){
	stringstream sStream;
	ID id;

	//paso el contenido del string al stringstream
	sStream << str;

	//paso el contenido del string stream al número
	if((sStream >> id).fail())
		id = 0;

	//devuelvo el id
	return id;
}

string StringUtils::idToString(const ID& id){
	stringstream sStream;
	string strId;

	//vuelco el id en el stringstream
	sStream << id;

	//vuelco el contenido del stringstream en un string
	sStream >> strId;

	//devuelvo el string
	return strId;
}


