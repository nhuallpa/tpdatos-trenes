/*
 * TestFranjaHoraria.h
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#ifndef TESTFRANJAHORARIA_H_
#define TESTFRANJAHORARIA_H_
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdlib.h>
#include "../utils/const.h"

#define SIZE 64
using namespace std;

#include "FranjaHoraria.h"
#include "hour.h"
#include "date.h"

class TestFranjaHoraria {
private:
	bool verResultadoDetallado;
	list<FranjaHoraria*> franjasHorarias;

public:
	TestFranjaHoraria();
	virtual ~TestFranjaHoraria();
	void cargarFranjasHorarias_mediante(const char* arch_franjasHorarias);
	void listarFranjasHorarias();
	void iniciar();
};

#endif /* TESTFRANJAHORARIA_H_ */


