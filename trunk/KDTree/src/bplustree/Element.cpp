/*
 * Element.cpp
 *
 */

#include "Element.h"
#include "../utils/utiles.h"
#include <iostream>
#include "../logger/Logger.h"
#include "../utils/StringUtils.h"
#include <cstdlib>
//**********************************/
// * Constructores de copia
//**********************************/

Element::Element(const Element& el) {
	key = el.key;
	dataSize = el.dataSize;
	Data dataBuffer = new char[dataSize];
	memcpy(dataBuffer, (char*) el.data, dataSize);

	this->data = dataBuffer;
}
Element::Element(const Element* el) {
	key = el->key;
	dataSize = el->dataSize;
	char* dataBuffer = new char[dataSize];
	memcpy(dataBuffer, (char*) el->data, dataSize);

	this->data = dataBuffer;
}
//**********************************/
// * Fin de Constructores de copia
//**********************************/

Element::Element() {

	this->dataSize = 0;
	this->data = NULL;
}

Element::Element(Key key) {
	this->key = key;
}
/*Element::Element(ID key)
{
	this->key=StringUtils::convertIntToString(key);
}*/
/**
 * Data es un char* e internamente se copia. El que invoca este constructor debe hacer el delete, si es que corresponde.
 */
Element::Element(Key key, Data data, DataSize dataSize) {
	this->key = key;
	this->setData(data, dataSize);
	//TODO: comento esto pero hay que tener en cuenta que se copia el dato. La responsabilidad de hacer el delete es del que hizo el new
	//delete[] data;
}
/*Element::Element(ID key, Data data, DataSize dataSize)
{
	this->key=StringUtils::convertIntToString(key);
	this->setData(data, dataSize);
}*/

Element::~Element() {
	if (data != NULL)
		delete[] data;
}

void Element::setKey(Key key) {
	this->key = key;
}

Key Element::getKey() {
	return key;
}

void Element::setData(Data data, DataSize dataSize) {
	this->dataSize = dataSize;

	char* dataBuffer = new char[dataSize];
	memcpy(dataBuffer, data, dataSize);

	this->data = dataBuffer;
}

Data Element::getData() {
	return data;
}

DataSize Element::getElementSize() {
	return dataSize;
}

/**
 * El formato es:
 * KeySize|key|DataSize|data
 */
std::string Element::serialize() {
	//Logger::getInstance()->debug("iniciando serializacion de element");
	std::string buffer = "";
	//serializacion de la key
	KeySize keySize=sizeof(this->key);
	std::string message="tamnno de la clave ";
	message.append(StringUtils::intToString(sizeof(this->key)));
	//Logger::getInstance()->debug(message);

	//agregamos el tamanno de la clave
	buffer.append((char*)&keySize,sizeof(KeySize));
	//agreamos el valor de la clave
	buffer.append((char*)&key,sizeof(this->key));


	//Serializacion de la data
	buffer.append((char*) &dataSize, sizeof(DataSize));
	buffer.append(data, dataSize);

	return buffer;
}

void Element::unserialize(std::string &buffer) {
	//copia lo que hay en el buffer a key

	//unserialize de la key
	KeySize keySize;
	buffer.copy((char*)&keySize,sizeof(KeySize));
	buffer.erase(0,sizeof(KeySize));

	//char* tempData=new char[keySize];
	//buffer.copy(tempData,keySize);
	//this->key.append(tempData,keySize);
	buffer.copy((char*)&this->key,sizeof(keySize));
	//delete[] tempData;
	buffer.erase(0,keySize);

	//Unserialize de la data
	buffer.copy((char*)&dataSize,sizeof(DataSize));
	buffer.erase(0,sizeof(DataSize));
	data = new char[dataSize];
	buffer.copy(data,dataSize);
	buffer.erase(0,dataSize);

}

int Element::getDataSize() {
    return (sizeof(KeySize)+sizeof(key) + sizeof(DataSize) + dataSize);
}



Element::Element(Key key, ISerializable* serializable)
{
	this->key=key;
	string dtSerialized= serializable->serialize();
	Data dtSerializedChar = new char[dtSerialized.size()];
	memcpy(dtSerializedChar,dtSerialized.c_str(),dtSerialized.size());
	this->setData(dtSerializedChar,dtSerialized.size());
	delete[] dtSerializedChar;
	//no deleteamos el serializable, El cliente debe hacerlo.

}

/*void Element::setKey(ID key)
{
	this->setKey(StringUtils::convertIntToString(key));
}*/


ostream& operator<<(ostream& myOstream, Element& elem) {
	string data;
	if (elem.getData() != NULL) { //programacion defensiva
		data.append(elem.getData(), elem.getElementSize());
	}
	myOstream << "Key> " << elem.getKey() << " " << "Data: " << data << " ";
	return myOstream;
}
