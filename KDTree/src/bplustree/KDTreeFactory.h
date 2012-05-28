/*
 * KDTree.h
 *
 *  Created on: 28/05/2012
 *      Author: sergio
 */

#ifndef KDTREE_H_
#define KDTREE_H_

#include "BPlusTree.h"

class KDTreeFactory {
public:
	static BPlusTree* createKDTree();

	KDTreeFactory(){}
	virtual ~KDTreeFactory(){}
};

#endif /* KDTREE_H_ */
