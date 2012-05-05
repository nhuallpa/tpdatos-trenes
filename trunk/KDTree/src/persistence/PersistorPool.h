/*
 * PersistorPool.h
 *  author carlos
 *  Devuelve un persisotr de su pool
 */

#ifndef PERSISTORPOOL_H_
#define PERSISTORPOOL_H_

#include "PersistorBTree.h"
#include <map>
#include <string>
#include "../utils/types.h"
#include "../bplustree/exceptions/ProgramException.h"
using namespace std;
typedef map<ESTRUCTURAS, PersistorBTree*> STRING2PERSISTORBTREE;
class PersistorPool{
private:
	static STRING2PERSISTORBTREE instances;

	/* Constructor privado */

public:
	PersistorPool();
	virtual ~PersistorPool();

	/* Captura la instancia del Persistor */
	static PersistorBTree* getInstance(ESTRUCTURAS estructura);
	static void dropInstance(ESTRUCTURAS estructura);

	/* Define la información principal del Persistor
	 * Solo permite definirlos si la instancia no fue iniciada.
	 * de caso contrario, lanzara PersistorInitializedException. */
	static void init(std::string fileName, BlockSize size, ESTRUCTURAS estrucutra) ;
};

#endif /* PERSISTOR_H_ */
