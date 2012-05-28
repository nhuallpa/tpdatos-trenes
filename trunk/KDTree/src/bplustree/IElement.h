/*
 * IElement.h
 *
 *      Author: carlos
 */

#ifndef IELEMENT_H_
#define IELEMENT_H_
#include "../utils/types.h"
#include "../persistence/ISerializable.h"
#include "../entidades/IEntidad.h"

class IElement:public ISerializable {
public:
	/**
	 * Longitud del dato
	 */
	virtual IEntidad* getData()=0;
	virtual void setData(IEntidad* data)=0;

	virtual void toString()=0;

	IElement(){}
	//~IElement(){}
};

#endif /* IELEMENT_H_ */
