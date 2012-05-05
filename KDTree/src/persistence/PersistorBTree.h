/*
 * PersistorBTree.h
 *
 */

#ifndef PERSISTORBTREE_H_
#define PERSISTORBTREE_H_

#include "PersistorBase.h"
#include "../utils/types.h"
#include "../bplustree/BNode.h"
#include "../utils/types.h"
class PersistorBTree : public PersistorBase {
protected:
	ESTRUCTURAS estructura;
	//Sobreescribo este metodo para que cree un nodo raiz vacio
	void newFile(std::string fileName,ESTRUCTURAS estructura) ;

public:
	PersistorBTree(std::string fileName, BlockSize size,ESTRUCTURAS estructura) ;
	virtual ~PersistorBTree();
	BNode* getNodeInBlock(int blockNumber);
	BNode* getRoot();

};

#endif /* PERSISTORBTREE_H_ */
