/*
 * IStructureBTreeSecondaryIndexImpl.h
 *
 *      Author: carlos
 */

#ifndef ISTRUCTUREBTREESECONDARYINDEXIMPL_H_
#define ISTRUCTUREBTREESECONDARYINDEXIMPL_H_

/**
 * La creo para dejar la validacion del id automatico
 */
#include "../index/IStrutureBTreeImpl.h"
class BPlussIStructureFactory;
class IStructureBTreeSecondaryIndexImpl: public IStrutureBTreeImpl{
	friend class BPlussIStructureFactory;
public:
	IStructureBTreeSecondaryIndexImpl(ESTRUCTURAS est);
	virtual ~IStructureBTreeSecondaryIndexImpl();
	virtual void allowException(string mensaje);



};

#endif /* ISTRUCTUREBTREESECONDARYINDEXIMPL_H_ */
