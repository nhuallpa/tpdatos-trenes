/*
 * Element.h
 *
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include "../utils/types.h"
#include "IElement.h"
#include <string.h>
#include <iostream>

using namespace std;
class Element: public IElement {
private:
	Key key;
	DataSize dataSize;
	Data data;

public:
	/**
	 * Ojo que el Serializable no debe serializar el ID
	 */
	Element(Key key,ISerializable* serializable);
	Element(Key key);
/*	Element(ID key);*/
	Element();
	//constructor de copia
	Element(const Element& el);
	Element(const Element* el);
	Element(Key key, Data data, DataSize dataSize);
/*	Element(ID key, Data data, DataSize dataSize);*/
	virtual ~Element();

	virtual void setData(Data data, DataSize dataSize);
	virtual Data getData();

	/*virtual void setKey(ID key);*/
	virtual void setKey(Key key);
	virtual Key getKey() ;
	virtual DataSize getElementSize();

	virtual std::string serialize();
	virtual void unserialize(std::string &buffer);
	virtual int getDataSize();

	bool operator==(const Element& k) { // sobrecarga operador ==
		return this->key == k.key;
	}
	bool operator>(const Element& k) { // sobrecarga operador >
		return this->key > k.key;
	}
	bool operator<(const Element& k) { // sobrecarga operador <
		return this->key < k.key;
	}

	/**
	 * Element deberia ser definido como const, pero para que compile
	 * Los accesores tambien deberian ser definidos como const.
	 */
	friend ostream& operator<<(ostream&, Element&);

	virtual void toSrtring(){
		string data(getData(),getElementSize());
		cout<<"Key : "<<getKey()<<" "<<"Data: "<<data<<" ";
	}
};

#endif /* ELEMENT_H_ */
