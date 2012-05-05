/*
 * ElementFactory.h
 *
 *  Created on: Oct 19, 2011
 *      Author: carlos
 */

#ifndef ELEMENTFACTORY_H_
#define ELEMENTFACTORY_H_
#include "Element.h"
#include "../utils/types.h"

class ElementFactory {
public:
	static Element* createElement(ESTRUCTURAS estructura,Key id,ISerializable* ser){
		Element* element=new Element(id,ser);
		element->setEstructura(estructura);
		return element;
	}
	static Element* createElement(ESTRUCTURAS estructura,Key i, Data data, DataSize dataSize){
		Element* element= new Element(i, data, dataSize);
		element->setEstructura(estructura);
		return element;
	}
	static Element* createElement(ESTRUCTURAS estructura){
		Element* element=new Element();
		element->setEstructura(estructura);
		return element;
	}
	ElementFactory();
	virtual ~ElementFactory();
};

#endif /* ELEMENTFACTORY_H_ */
