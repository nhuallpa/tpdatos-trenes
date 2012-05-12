/*
 * KDTreeController.h
 *
 *  Created on: 11/05/2012
 *      Author: nestor
 */

#ifndef KDTREECONTROLLER_H_
#define KDTREECONTROLLER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "../utils/const.h"
using namespace std;

class KDTreeController {

private:
	list<string> listLineas;

public:
	KDTreeController();
	virtual ~KDTreeController();
	void init();

	list<string>& getLineas() { return this->listLineas;}
	// TODO: (Nestor) falta validar el numero de la linea contra la lista
	bool validarNroLinea(string& nroLinea) ;

};

#endif /* KDTREECONTROLLER_H_ */
