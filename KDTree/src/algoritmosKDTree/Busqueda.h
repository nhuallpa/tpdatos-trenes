/*
 * Busqueda.h
 *
 *  Created on: 05/06/2012
 *      Author: ariel
 */

#ifndef BUSQUEDA_H_
#define BUSQUEDA_H_
typedef unsigned int typekey;
const int K = 5;
typedef struct tree;

typedef struct tree{
	typekey k[K];
	tTree p[K];
} tTree;

class Busqueda {

public:
	Busqueda();
	void iniciar(typekey key[K], tTree t);
	virtual ~Busqueda();
};

#endif /* BUSQUEDA_H_ */
