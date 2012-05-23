/*
 * PersistorBTree.h
 *
 */

#ifndef PERSISTORBTREE_H_
#define PERSISTORBTREE_H_

#include "PersistorBase.h"
#include "../utils/types.h"
#include "../bplustree/BNode.h"

class PersistorBTree : public PersistorBase {
protected:
	static PersistorBTree instance;
	//Sobreescribo este metodo para que cree un nodo raiz vacio
	void newFile(std::string fileName) ;

	PersistorBTree() ;
public:
	static PersistorBTree* getInstance();

	void init(std::string fileName, BlockSize size);
	virtual ~PersistorBTree();
	BNode* getNodeInBlock(int blockNumber);
	BNode* getRoot();
};

#endif /* PERSISTORBTREE_H_ */
