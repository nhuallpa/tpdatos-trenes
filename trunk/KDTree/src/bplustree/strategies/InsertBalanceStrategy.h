/*
 * InsertBalanceStrategy.h
 *
 */

#ifndef INSERTBALANCESTRATEGY_H_
#define INSERTBALANCESTRATEGY_H_
#include "BalanceStrategy.h"
class InsertBalanceStrategy: public BalanceStrategy {
public:
	InsertBalanceStrategy();
	virtual ~InsertBalanceStrategy();
	/*
	 * Devuelve true o false si modifico al padre o no
	 */
	bool doBalance(Node* parent, BNode* child);

	/**
	 * Devuelve el tipo de estrategia segun el archivo const.h
	 */
	int getTypeOfStrategy();
};

#endif /* INSERTBALANCESTRATEGY_H_ */
