/*
 * KDTreeController.cpp
 *
 *  Created on: 11/05/2012
 *      Author: nestor
 */

#include "KDTreeController.h"

KDTreeController::KDTreeController() {
	// TODO Auto-generated constructor stub

}

KDTreeController::~KDTreeController() {
	// TODO Auto-generated destructor stub
}

void KDTreeController::init(){
	// levantar lineas
	// TODO: (Nestor)	Refactorizar en otro lugar, luego...
	int SIZE = 512;
	char buffer[SIZE];
	ifstream in(ARCH_LINEAS, ios::in);
	if (in.is_open()) {
		while (!in.eof()){
			in.getline(buffer, SIZE);
			if (in.good()) {
				//cod = getCodigo(buffer);
				string linea(buffer);
				this->listLineas.push_back(buffer);
			}
		}
		in.close();
	}
}

bool KDTreeController::validarNroLinea(string& nroLinea) {
	return true;
}

