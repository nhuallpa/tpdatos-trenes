/*
 * KeyElement.cpp
 *
 */

#include "KeyElement.h"

KeyElement::KeyElement() {
	this->rightNode=-1;
}

KeyElement::KeyElement(Key key,Offset rightNode) {
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

void KeyElement::setKey(Key key) {
	this->key = key;
}

Key KeyElement::getKey(){

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

	KeySize keySize=sizeof(this->key);

	buffer.append((char*)&keySize,sizeof(KeySize));

	buffer.append((char*)&key,keySize);
	buffer.append((char*)&rightNode,sizeof(Offset));

	return buffer;
}

/**
 * KeySize|key|offset|---> 4,4,4 =12
 */
void KeyElement::unserialize(std::string &buffer) {

	//unserialize de la key
	KeySize keySize;
	buffer.copy((char*)&keySize,sizeof(KeySize));
	buffer.erase(0,sizeof(KeySize));

	//char* tempKey=new char[keySize];
	//buffer.copy(tempKey,keySize);
	//delete[] tempKey;
	buffer.copy((char*)&this->key,keySize );
	buffer.erase(0,keySize);

	//unserialize del node
	buffer.copy((char*)&rightNode,sizeof(Offset));
	buffer.erase(0,sizeof(Offset));
}

int KeyElement::getDataSize(){
	return (sizeof(KeySize)+ sizeof(this->key) + sizeof(Offset));
}
