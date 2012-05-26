/*
 * KeyElement.cpp
 *
 */

#include "KeyElement.h"

KeyElement::KeyElement() {
	this->rightNode=-1;
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

	myOstream<<elem.getKey()<<" RightOffSet: "<<elem.getrightNode()<<" ";

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
	//Para claves enteras
	std::string buffer = "";

	buffer.append((char*)&rightNode,sizeof(Offset));

	return buffer;
}

/**
 * KeySize|key|offset|---> 4,4,4 =12
 */
void KeyElement::unserialize(std::string &buffer) {

	//unserialize del node
	buffer.copy((char*)&rightNode,sizeof(Offset));
	buffer.erase(0,sizeof(Offset));
}

int KeyElement::getDataSize(){
	return (sizeof(this->key) + sizeof(Offset));
}
