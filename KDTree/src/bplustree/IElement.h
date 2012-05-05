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
	 * Estructura de datos real que se implementa.
	 * Este valor no hay que persistirlo necesariamente.
	 * Para este TP no se persiste
	 */
	virtual ESTRUCTURAS getEstructura()=0;
	virtual void setEstructura(ESTRUCTURAS estructura)=0;
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
