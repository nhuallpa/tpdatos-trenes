/*
 * EntityFactory.h
 *
 *  Created on: Oct 11, 2011
 *      Author: carlos
 */

#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_
#include "../entidades/IEntidad.h"
#include "../utils/types.h"
#include "../utils/const.h"
#include "../entidades/Lista.h"
#include "../bplustree/IElement.h"
#include "../index/SimpleSecondaryIndex.h"
class EntityFactory {
public:
	EntityFactory();
	virtual ~EntityFactory();
	static SimpleSecondaryIndex* createSimpleSecondaryIndex(ESTRUCTURAS type);
	static IEntidad* createEntity(ESTRUCTURAS type);
	static IEntidad* createEntity(ESTRUCTURAS type,IElement* element);
};

#endif /* ENTITYFACTORY_H_ */
