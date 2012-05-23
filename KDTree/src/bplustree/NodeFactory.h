/*
 * NodeFactory.h
 *
 */

#ifndef NODEFACTORY_H_
#define NODEFACTORY_H_

#include "BNode.h"
#include "../utils/types.h"

class Node;
class LeafNode;
class NodeFactory {
public:
	static int nodeCounter;
	NodeFactory();
	/**
	 * Crea un nodo para búsqueda según en nivel de hoja en el que se encuentre
	 */
	static BNode* createNodeForSearch(int level);
	static Node* createKeyNode();
	static LeafNode* createLeafNode();
	static BNode* createSibling(int level);

	virtual ~NodeFactory();
};

#endif /* NODEFACTORY_H_ */
