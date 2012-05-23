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

void KDTreeController::levantar_datosMaestros_segun(const char* fileName_entrada, list<string>* lista_salida){
	int SIZE = 512;
	char * buffer = new char[SIZE];
	ifstream in(fileName_entrada, ios::in);
	if (in.is_open()) {
		while (!in.eof()){
			in.getline(buffer, SIZE);
			if (in.good()) {
				//cod = getCodigo(buffer);
				string linea(buffer);
				lista_salida->push_back(buffer);
			}
		}
		in.close();
	}else{
		cout<<"No puedo abrir el archivo "<<fileName_entrada<<endl;
	}
	delete(buffer);
}

void KDTreeController::init(){

	this->levantar_datosMaestros_segun((const char*)ARCH_LINEAS, &this->listLineas);
	this->levantar_datosMaestros_segun((const char*)ARCH_FORMACIONES, &this->listFormaciones);
	this->levantar_datosMaestros_segun((const char*)ARCH_FALLAS, &this->listFallas);
	this->levantar_datosMaestros_segun((const char*)ARCH_ACCIDENTES, &this->listAccidentes);
	this->levantar_datosMaestros_segun((const char*)ARCH_FRANJAS_HORARIAS, &this->listFranjasHorarias);

}

/*
 * TODO la logica de validacion tiene que se corregida cuando se ejecute la operacion 'eliminar' un elemento del arbol
 */
bool KDTreeController::validarNroSubElemento(string& tipo_deSubElemento, string& nroSubElemento)
{
	bool nroSubElemento_validado = false;
	int nroSubElem = atoi(nroSubElemento.c_str());

	if ( nroSubElem >= 1 ){
		if ( strcmp(UtilMenu::getNombreCampo_segun(0).c_str(), tipo_deSubElemento.c_str()) == 0){
			nroSubElemento_validado = nroSubElem <= (int)this->listLineas.size();

		}else if( strcmp(UtilMenu::getNombreCampo_segun(1).c_str(), tipo_deSubElemento.c_str()) == 0){
			nroSubElemento_validado = nroSubElem <= (int)this->listFormaciones.size();

		}else if( strcmp(UtilMenu::getNombreCampo_segun(2).c_str(), tipo_deSubElemento.c_str()) == 0){
			nroSubElemento_validado = nroSubElem <= (int)this->listFallas.size();

		}else if( strcmp(UtilMenu::getNombreCampo_segun(3).c_str(), tipo_deSubElemento.c_str()) == 0){
			nroSubElemento_validado = nroSubElem <= (int)this->listAccidentes.size();

		}else if( strcmp(UtilMenu::getNombreCampo_segun(4).c_str(), tipo_deSubElemento.c_str()) == 0){
			nroSubElemento_validado = nroSubElem <= (int)this->listFranjasHorarias.size();
		}else{
			cout<<"ERROR INFRAGANTI!!!"<<endl;
		}
	}
	return nroSubElemento_validado;
}

