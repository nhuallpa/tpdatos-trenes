/*
 * UnderflorRootStrategy.cpp
 *
 */

#include "UnderflorRootStrategy.h"
#include "../Node.h"
#include "../LeafNode.h"
#include "../BNode.h"
#include "../../persistence/PersistorPool.h"
#include "../../persistence/PersistorBTree.h"
#include "../NodeFactory.h"
UnderflorRootStrategy::UnderflorRootStrategy() {

}
// el root se contrae cuando TODOS sus hijos entran en una hoja y es es cuando hay 2 hijos y
//esos entran en una hoja, para ello uno debe estar en underflow y el otro no debe poder pedirle
//nada.

BNode* UnderflorRootStrategy::doBalance(BNode* root){
	PersistorBTree* p=PersistorPool::getInstance(root->getEstructura());

	if(root->isUnderflowded()){
		//aca hay que contraerlo.
		if(!root->getLevel()==0){ //si no es nodo hoja entonces se puede contraer.
			//El root solo se va a contraer cuando tiene un elemento.
			Node* myroot=(Node*)root;
			if(myroot->getRegisterCounter()==0){//si es un hijo es el unico caso en el que puedo pasar el nodo hoja a root
				BNode* newroot=NodeFactory::createNodeForSearch(myroot->getLevel(),myroot->getEstructura());
				p->load(myroot->getLeftNode(),newroot);
				Offset oldOffset=newroot->getOffset();
				newroot->setOffset(root->getOffset());
				p->removeBlock(oldOffset);
				p->modify(newroot);
				delete root;
				return newroot;
			}
		}
	}
	p->modify(root);
	return root;

}
UnderflorRootStrategy::~UnderflorRootStrategy() {
}

