/*
 * IElement.h
 *
 *      Author: carlos
 */

#ifndef IELEMENT_H_
#define IELEMENT_H_
#include "../utils/types.h"
#include "../persistence/ISerializable.h"
class IElement:public ISerializable {
public:
	/**
	 * Longitud del dato
	 */
	virtual Data getData()=0;
	virtual DataSize getElementSize()=0;
	virtual Key getKey()=0;
	virtual void toSrtring()=0;
	virtual void setKey(Key key)=0;
	IElement();
	virtual ~IElement();
};

#endif /* IELEMENT_H_ */
