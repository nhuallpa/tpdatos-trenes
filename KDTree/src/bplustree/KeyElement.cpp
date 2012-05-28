/*
 * KeyElement.cpp
 *
 */

#include "KeyElement.h"
#include "../entidades/EntityFactory.h"

KeyElement::KeyElement() {
	this->rightNode=-1;
	this->key = EntityFactory::createEntity();
}

KeyElement::KeyElement(IEntidad* key,Offset rightNode) {
	this->key = key;
	this->rightNode = rightNode;
}

KeyElement::~KeyElement() {

}

void KeyElement::setRightNode(Offset rightNode) {
	this->rightNode = rightNode;
}

Offset KeyElement::getrightNode(){
	return rightNode;
}

void KeyElement::setKey(IEntidad* key) {
	this->key = key;
}

IEntidad* KeyElement::getKey(){

	return this->key;
}

ostream& operator<<(ostream& myOstream, KeyElement& elem){

	myOstream << elem.getKey()->toString()<<" RightOffSet: "<<elem.getrightNode()<<" ";

	return myOstream;
}


/******************************************************
 * 					PERSISTENCIA
 *
 ****************************************************/


/**
 * KeySize|key|offset|
 */
std::string KeyElement::serialize() {
	Serializacion serial;
	serial.addEntero(this->rightNode);
	std::string buffer = this->key->serialize();
	serial.addString(buffer);

	return serial.toString();
}

/**
 * KeySize|key|offset|---> 4,4,4 =12
 */
void KeyElement::unserialize(std::string &buffer) {

	Serializacion serial(buffer);

	rightNode = serial.getEntero();
	std::string tmpBuffer;
	tmpBuffer.append(serial.getString());

	this->key->unserialize(tmpBuffer);
}

DataSize KeyElement::getDataSize(){
	return (this->key->getDataSize()+ sizeof(int) + sizeof(Offset));
}
