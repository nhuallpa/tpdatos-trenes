/*
 * KDTree.cpp
 *
 *  Created on: 28/05/2012
 *      Author: sergio
 */

#include "KDTreeFactory.h"

BPlusTree* KDTreeFactory::createKDTree() {
	ConfigurationMananger* config = ConfigurationMananger::getInstance();
	BPlusTree* bp = new BPlusTree(config->getBufferSizeTree(), config->getFilename());
	return bp;
}
