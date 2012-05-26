/*
 * OperacionConsulta.h
 *
 *  Created on: 26/05/2012
 *      Author: ariel
 */

#ifndef OPERACIONCONSULTA_H_
#define OPERACIONCONSULTA_H_
#include "Operacion.h"
#include "../iu/UtilMenu.h"

class OperacionConsulta: public Operacion {
private:
	//TODO: tendria que ser cargado con la estructura de la data del elemento del arbol KD
	string* filtroEntrada;
	int tamanio_entrada;
	string* filtroSalida;
	int tamanio_salida;
public:
	OperacionConsulta();
	virtual ~OperacionConsulta();
	void inicializar(string linea, string formacion, string falla, string accidente, string franjaHoraria);
	void inicializar_filtroEntrada(string* filtroEntrada, int tamanio);
	void inicializar_filtroSalida(string* filtroSalida, int tamanio);
	int iniciar();
	void mostrar();
};

#endif /* OPERACIONCONSULTA_H_ */
