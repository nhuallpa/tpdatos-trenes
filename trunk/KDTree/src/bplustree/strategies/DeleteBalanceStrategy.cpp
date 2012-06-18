/*
 * DeleteBalanceStrategy.cpp
 *
 */

#include "DeleteBalanceStrategy.h"
#include "../../utils/const.h"
#include "BalanceStrategyFactory.h"
DeleteBalanceStrategy::DeleteBalanceStrategy() {

}

//Devuelve true si parent ha cambiado
bool DeleteBalanceStrategy::doBalance(Node* parent, BNode* child){
	//verificamos si hay underflow.

	ComposedBalanceStrategy* strategy=BalanceStrategyFactory::createComposedBalanceStrategy(UNDERFLOW);
	bool haschange = strategy->doBalance(parent,child,this);
	delete strategy;

	return haschange;
}


int DeleteBalanceStrategy::getTypeOfStrategy(){
	return DELETE;
}
DeleteBalanceStrategy::~DeleteBalanceStrategy() {
}
