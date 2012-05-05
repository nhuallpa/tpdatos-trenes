/*
 * BPlussIStructureFactory.h
 *
 *  Created on: Oct 21, 2011
 *      Author: carlos
 */

#ifndef BPLUSSISTRUCTUREFACTORY_H_
#define BPLUSSISTRUCTUREFACTORY_H_

#include "../utils/types.h"
#include "../bplustree/exceptions/ProgramException.h"
#include "../index/IStructureBTreeSecondaryIndexImpl.h"
class BPlussIStructureFactory {
public:
	static IStrutureBTreeImpl* createIStrcutre(ESTRUCTURAS estructura) {
		return new IStrutureBTreeImpl(estructura);
	}

	static IStrutureBTreeImpl* createIndexIStructure(ESTRUCTURAS estructuraPadre, ESTRUCTURAS estructuraSecundaria) {
		return new IStructureBTreeSecondaryIndexImpl(estructuraSecundaria);
	}

	BPlussIStructureFactory();
	virtual ~BPlussIStructureFactory();
};

#endif /* BPLUSSISTRUCTUREFACTORY_H_ */
