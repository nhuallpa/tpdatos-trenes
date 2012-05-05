/*
 * OverflowStrategy.h
 *
 */

#ifndef OVERFLOWSTRATEGY_H_
#define OVERFLOWSTRATEGY_H_
#include "ComposedBalanceStrategy.h"
#include "BalanceStrategy.h"
class OverflowStrategy: public ComposedBalanceStrategy  {
public:
	OverflowStrategy();
	bool doBalance(Node* parent, BNode* child,BalanceStrategy* parentStrategy);
	virtual ~OverflowStrategy();
};

#endif /* OVERFLOWSTRATEGY_H_ */
