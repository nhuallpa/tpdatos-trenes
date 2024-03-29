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

class EntityFactory {
public:
	EntityFactory();
	virtual ~EntityFactory();
	static IEntidad* createEntity();
	static IEntidad* createEntity(IEntidad* toCopy);
};

#endif /* ENTITYFACTORY_H_ */
