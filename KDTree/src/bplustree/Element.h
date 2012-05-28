/*
 * Element.h
 *
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include "../utils/types.h"
#include "IElement.h"
#include "../persistence/ISerializable.h"
#include <string.h>
#include <iostream>

using namespace std;
class Element: public IElement {
private:
	IEntidad* data;

public:

	Element();

	//constructor de copia
	Element(const Element& el);
	Element(const Element* el);

	Element(IEntidad* data);

	virtual ~Element();

	virtual void setData(IEntidad* data);
	virtual IEntidad* getData();
	virtual IEntidad* getConstData() const;

	virtual std::string serialize();
	virtual void unserialize(std::string &buffer);
	virtual DataSize getDataSize();

	/**
	 * Element deberia ser definido como const, pero para que compile
	 * Los accesores tambien deberian ser definidos como const.
	 */
	friend ostream& operator<<(ostream&, Element&);

	virtual void toString(){
		cout<<"Data: "<<data->toString()<<" ";
	}

};

#endif /* ELEMENT_H_ */
