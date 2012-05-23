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
	static Element* createElement(Key id,ISerializable* ser){
		Element* element=new Element(id,ser);
		return element;
	}
	static Element* createElement(Key i, Data data, DataSize dataSize){
		Element* element= new Element(i, data, dataSize);
		return element;
	}
	static Element* createElement(){
		Element* element=new Element();
		return element;
	}
	ElementFactory();
	virtual ~ElementFactory();
};

#endif /* ELEMENTFACTORY_H_ */
