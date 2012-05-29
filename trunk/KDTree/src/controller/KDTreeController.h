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
#include "../utils/utiles.h"
#include "../entidades/Reporte.h"
#include "../utils/StringUtils.h"
#include "../bplustree/KDTreeFactory.h"

using namespace std;

#include <stdlib.h>
#include <string.h>
#include "../bplustree/BPlusTree.h"
/**
 * Inicializado mediante los archivos maestros y tambien para validad el ingreso
 * del usuario en base a esos maestros
 */
class KDTreeController {

	BPlusTree* BTree;

private:
	//listas de subElementos que seran caragadas con los archivos maestros
	list<string> listLineas;
	list<string> listFormaciones;
	list<string> listFallas;
	list<string> listAccidentes;
	list<string> listFranjasHorarias;

	//para validar los numeros elejidos de los subElementos. TODO: utilizar otra tecnica
	int cantidades_enListas[CANT_SUBELEMENTOS];

public:
	KDTreeController();
	virtual ~KDTreeController();
	//TODO la logica de validacion tiene que se corregida cuando se ejecute la operacion 'eliminar' un elemento del arbol
	void inicializar();
	list<string>& getLineas();
	list<string>& getFormaciones();
	list<string>& getFallas();
	list<string>& getAccidentes();
	list<string>& getFranjasHorarias();
	bool validarIdSubElemento(string& tipo_deSubElemento, int idSubElemento);

	void insertar(string registro);
	void eliminar(string registro);
	void modificar(string registro);
	void consultar(string registro);

	void mostrarEstado();

private:
	void levantar_datosMaestros_segun(const char* fileName_entrada, list<string>* lista_salida);
};

#endif /* KDTREECONTROLLER_H_ */
