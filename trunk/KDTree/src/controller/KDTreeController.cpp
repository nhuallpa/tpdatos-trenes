/*
 * KDTreeController.cpp
 *
 *  Created on: 11/05/2012
 *      Author: nestor
 */

#include "KDTreeController.h"
#include "../entidades/EntityFactory.h"

using std::cout;
using std::endl;
KDTreeController::KDTreeController() {
	this->BTree = KDTreeFactory::createKDTree();
}

KDTreeController::~KDTreeController() {
	delete this->BTree;
}

void KDTreeController::inicializar()
{
	this->levantar_datosMaestros_segun((const char*)ARCH_LINEAS, &this->listLineas);
	this->levantar_datosMaestros_segun((const char*)ARCH_FORMACIONES, &this->listFormaciones);
	this->levantar_datosMaestros_segun((const char*)ARCH_FALLAS, &this->listFallas);
	this->levantar_datosMaestros_segun((const char*)ARCH_ACCIDENTES, &this->listAccidentes);
	this->levantar_datosMaestros_segun((const char*)ARCH_FRANJAS_HORARIAS, &this->listFranjasHorarias);

	//cargo los tamanios de cada lista
	this->cantidades_enListas[0] = (int)this->listLineas.size();
	this->cantidades_enListas[1] = (int)this->listFormaciones.size();
	this->cantidades_enListas[2] = (int)this->listFallas.size();
	this->cantidades_enListas[3] = (int)this->listAccidentes.size();
	this->cantidades_enListas[4] = (int)this->listFranjasHorarias.size();
}

void KDTreeController::levantar_datosMaestros_segun(const char* fileName_entrada, list<string>* lista_salida)
{
	char * buffer = new char[SIZE_LINEA_LEVANTAR];
    ifstream in;
	in.open(fileName_entrada, ifstream::in);
	if (in.is_open()) {
		while (!in.eof()){
			in.getline(buffer, SIZE_LINEA_LEVANTAR);
			if (in.good()) {
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

list<string>& KDTreeController::getLineas(){ return this->listLineas;}
list<string>& KDTreeController::getFormaciones(){ return this->listFormaciones;}
list<string>& KDTreeController::getFallas(){ return this->listFallas;}
list<string>& KDTreeController::getAccidentes(){ return this->listAccidentes;}
list<string>& KDTreeController::getFranjasHorarias(){ return this->listFranjasHorarias;}

bool KDTreeController::validarIdSubElemento(string& nombreSubElemento, int idSubElemento)
{
	bool idSubElemento_validado = false;
	if ( idSubElemento >= 1 ){
		for(int i = 0; i < CANT_SUBELEMENTOS ; i++){
			if (nombreSubElemento.compare(Util::getNombreSubElemento(i)) == 0)
				idSubElemento_validado = ( idSubElemento <= this->cantidades_enListas[i] );
		}
	}
	return idSubElemento_validado;
}

void KDTreeController::insertar(string registro) {
	Reporte* reporteSimple = (Reporte*)EntityFactory::createEntity();
	reporteSimple->inicializar(registro);
	IElement* elem = new Element(reporteSimple);
	this->BTree->insert(elem);
}
void KDTreeController::remover(string registro) {
	Reporte* reporteSimple = (Reporte*)EntityFactory::createEntity();
	reporteSimple->inicializar(registro);
	this->BTree->remove(reporteSimple);
}
void KDTreeController::modificar(string registro) {
	cout<<"en proceso de construccion"<<endl;
	//this->BTree->modify(entidad);
}

std::vector<BNode*> KDTreeController::consultar(string registro)
{
	cout<<"registro: "<<registro<<endl;
	Reporte* unReporte = (Reporte*)EntityFactory::createEntity();
	bool esConRango = Util::tienenParametroConRango(registro);
	if (esConRango){
		cout<<"en construccion(ReporteRango)..."<<endl;
		unReporte = (Reporte*)EntityFactory::createEntity();
//		unReporte.inicializar(registro);
	}else{
//		cout<<"paso ariel 2 "<<endl;
		unReporte->inicializar(registro);
//		cout<<*unReporte<<endl;
	}

	return ( this->BTree->find(unReporte) );
}

void KDTreeController::mostrarEstado(){
	this->BTree->exportTree();
}
