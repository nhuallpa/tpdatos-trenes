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
BNode* NodeFactory::createNodeForSearch(int level) {
	nodeCounter++;
	if (level == 1 || level == 0) {
		return createLeafNode();
	} else {
		return createKeyNode();
	}
}
BNode* NodeFactory::createSibling(int level) {
	nodeCounter++;
	if (level >= 1) {
		return createKeyNode();
	} else {
		return createLeafNode();
	}
}
Node* NodeFactory::createKeyNode() {
	nodeCounter++;
	Node* newNode = new Node();
	return newNode;
}
LeafNode* NodeFactory::createLeafNode() {
	nodeCounter++;
	LeafNode* newNode = new LeafNode();
	return newNode;
}
NodeFactory::~NodeFactory() {

}
