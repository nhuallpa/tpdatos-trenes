/*
 * ComposedBalanceStrategy.h
 *
 */

#ifndef COMPOSEDBALANCESTRATEGY_H_
#define COMPOSEDBALANCESTRATEGY_H_
#include "../../utils/const.h"
#include "BalanceStrategy.h"
#include "../Node.h"
#include "../BNode.h"
/**
 * Estrategia de balanceo que tiene que ser llamada por otra estrategia.
 * Estas no pueden ser llamadas solas.
 */
class ComposedBalanceStrategy {
public:
	ComposedBalanceStrategy();
	virtual ~ComposedBalanceStrategy();
	virtual bool doBalance(Node* parent, BNode* child,BalanceStrategy* parentStrategy)=0;

};

#endif /* COMPOSEDBALANCESTRATEGY_H_ */
