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
#include "../iu/UtilMenu.h"
using namespace std;

#include <stdlib.h>
#include <string.h>

class KDTreeController {

private:
	//listas de subElementos...
	list<string> listLineas;
	list<string> listFormaciones;
	list<string> listFallas;
	list<string> listAccidentes;
	list<string> listFranjasHorarias;

	//para validar los numeros elejidos de los subElementos
	int cantidades_enListas[CANT_SUBELEMENTOS];

public:
	KDTreeController();
	virtual ~KDTreeController();
	void init();

	list<string>& getLineas() { return this->listLineas;}
	list<string>& getFormaciones() { return this->listFormaciones;}
	list<string>& getFallas() { return this->listFallas;}
	list<string>& getAccidentes() { return this->listAccidentes;}
	list<string>& getFranjasHorarias() { return this->listFranjasHorarias;}

	// TODO: (Ariel) terminar de implementar la validacion...
	bool validarNroSubElemento(string& tipo_deSubElemento, string& subElemento);

private:
	void levantar_datosMaestros_segun(const char* fileName_entrada, list<string>* lista_salida);
};

#endif /* KDTREECONTROLLER_H_ */
