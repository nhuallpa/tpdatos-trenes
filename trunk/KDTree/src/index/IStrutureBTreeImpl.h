/*
 * IStrutureBTreeImpl.h
 *
 *  Created on: Oct 1, 2011
 *      Author: carlos
 */

#ifndef ISTRUTUREBTREEIMPL_H_
#define ISTRUTUREBTREEIMPL_H_
#include "IStructure.h"
#include "../bplustree/BPlusTree.h"
#include "../bplustree/exceptions/ProgramException.h"
class BPlussIStructureFactory;
class IStrutureBTreeImpl: public IStructure {
	friend class BPlussIStructureFactory;
protected:
	IStrutureBTreeImpl(ESTRUCTURAS estructura);
public:
	virtual ~IStrutureBTreeImpl();
	virtual int insert(IEntidad* entidad);
	virtual int modify(IEntidad* entidad);
	virtual IEntidad* find(ID key);
	virtual int remove(ID key);
	void toString();
	virtual IEntidad* siguiente();

	virtual void dropStructure();
protected:
	virtual void allowException(string mensaje);

private:
	//ojo no hacer delete. No lo pongo como referencia porque necesito saber si esta inicializado
	LeafNode* hojaActual;
	BPlusTree* bplusTree;
};

#endif /* ISTRUTUREBTREEIMPL_H_ */
