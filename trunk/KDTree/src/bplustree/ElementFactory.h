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
#include "../persistence/ISerializable.h"

class ElementFactory {
public:
	static Element* createElement(ISerializable* ser){
		Element* element=new Element((IEntidad*)ser);
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
