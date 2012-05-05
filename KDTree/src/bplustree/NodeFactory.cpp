/*
 * NodeFactory.cpp
 *
 */

#include "NodeFactory.h"
#include "Node.h"
#include "LeafNode.h"
int NodeFactory::nodeCounter = 0;
#include "../utils/types.h"

NodeFactory::NodeFactory() {
}

/**
 * En caso que el nivel sea 1 el proximo sera una hoja.
 */
BNode* NodeFactory::createNodeForSearch(int level, ESTRUCTURAS estructura) {
	nodeCounter++;
	if (level == 1 || level == 0) {
		return createLeafNode(estructura);
	} else {
		return createKeyNode(estructura);
	}
}
BNode* NodeFactory::createSibling(int level, ESTRUCTURAS estructura) {
	nodeCounter++;
	if (level >= 1) {
		return createKeyNode(estructura);
	} else {
		return createLeafNode(estructura);
	}
}
Node* NodeFactory::createKeyNode(ESTRUCTURAS estructura) {
	nodeCounter++;
	Node* newNode = new Node();
	newNode->setEstructura(estructura);
	return newNode;
}
LeafNode* NodeFactory::createLeafNode(ESTRUCTURAS estructura) {
	nodeCounter++;
	LeafNode* newNode = new LeafNode();
	newNode->setEstructura(estructura);
	return newNode;
}
NodeFactory::~NodeFactory() {

}
