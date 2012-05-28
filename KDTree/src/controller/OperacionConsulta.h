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
	void inicializar(int idLinea, int idFormacion, int idFalla, int idAccidente, FranjaHoraria* franjaHoraria);
	void inicializar_filtroEntrada(string* filtroEntrada, int tamanio);
	void inicializar_filtroSalida(string* filtroSalida, int tamanio);
	int iniciar();
	friend std::ostream & operator<<( std::ostream & os, const OperacionConsulta & );

	string* getFiltroEntrada(){
		return filtroEntrada;
	}

	string* getFiltroSalida(){
		return filtroSalida;
	}

	int getTamanioEntrada(){
		return tamanio_entrada;
	}

	int getTamanioSalida(){
		return tamanio_salida;
	}

};

#endif /* OPERACIONCONSULTA_H_ */
