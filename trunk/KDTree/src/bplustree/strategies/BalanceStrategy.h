/*
 * BalaceStrategy.h
 *
 */

#ifndef BALACESTRATEGY_H_
#define BALACESTRATEGY_H_

#include "../LeafNode.h"
#include "../Node.h"
#include "../BNode.h"
/**
 * Estrategia de balanceo
 */
class BalanceStrategy {
public:
	BalanceStrategy();
	virtual ~BalanceStrategy();
	/*
	 * Devuelve true o false si modifico al padre o no
	 */
	virtual bool doBalance(Node* parent, BNode* child)=0;

	virtual int getTypeOfStrategy()=0;
};

#endif /* BALACESTRATEGY_H_ */
