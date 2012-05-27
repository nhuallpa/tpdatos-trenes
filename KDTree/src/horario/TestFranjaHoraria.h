/*
 * TestFranjaHoraria.h
 *
 *  Created on: 16/05/2012
 *      Author: ariel
 */

#ifndef TESTFRANJAHORARIA_H_
#define TESTFRANJAHORARIA_H_

#include <string>
#include <list>
#include <fstream>
#include <stdlib.h>

#include "FranjaHoraria.h"
#include "hour.h"
#include "date.h"
#include "../utils/const.h"
#include "../utils/utiles.h"

class TestFranjaHoraria {
private:
	//para ver resultados detallados de las operaciones entre frangas horarias
	bool verResultadoDetallado;
	list<FranjaHoraria*> franjasHorarias;
	//cantidad de franjas horarias que se van a listar en post del Test
	int cant_listar;

public:
	TestFranjaHoraria();
	virtual ~TestFranjaHoraria();
	void iniciar();
private:
	/**
	 * cada franga horaria se deserealiza segun cada linea del archivo de franja shorarias,
	 * y se lo carga en la lista de franjasHorarias
	 */
	void cargarFranjasHorarias_mediante(const char* arch_franjasHorarias);
	/**
	 * muestra los primeros elementos de la lista de franjas horarias segun la
	 * cantidad pasada por parametro
	 */
	void listarFranjasHorarias_segun(int cant_listar);
	/**
	 * deserealiza el string pasado por parametro a un objeto FranjaHoraria
	 */
	FranjaHoraria* deserealizarFranjaHoraria_segun(string lineaArchivo);
};

#endif /* TESTFRANJAHORARIA_H_ */


