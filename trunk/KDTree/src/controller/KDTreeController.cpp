/*
 * KDTreeController.cpp
 *
 *  Created on: 11/05/2012
 *      Author: nestor
 */

#include "KDTreeController.h"
#include "../iu/UtilMenu.h"
#include "../controller/Operacion.h"
#include "../iu/Menu.h"
#include "../iu/MenuPrincipal.h"

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
			if (nombreSubElemento.compare(UtilMenu::getNombreSubElemento(i)) == 0)
				idSubElemento_validado = ( idSubElemento <= this->cantidades_enListas[i] );
		}
	}
	return idSubElemento_validado;
}

void KDTreeController::insertar(string registro) {
	Reporte rp(registro);
	IElement* elem = new Element(&rp);
	this->BTree->insert(elem);
}
void KDTreeController::remover(string registro) {
	Reporte rp(registro);
	this->BTree->remove(&rp);
}
void KDTreeController::modificar(string registro) {
	cout<<"en proceso de construccion"<<endl;
	//this->BTree->modify(entidad);
}
std::vector<BNode*> KDTreeController::consultar(string registro) {
	Reporte rp(registro);
	return ( this->BTree->find(&rp) );
}

void KDTreeController::mostrarEstado(){
	this->BTree->exportTree();
}

void KDTreeController::iniciarUserInterfax() {
	Operacion* operacionElejida;
	Menu* menu_principal = new MenuPrincipal(*this);

	bool salir_programa= false;
	bool operacion_fueCreada = false;

	while(!salir_programa)
	{
		UtilMenu::separador_menu();
		cout<<"1-elejir operacion para KDTree"<<endl;
		cout<<"2-mostrar operacion"<<endl;
		cout<<"3-ejecutar operacion"<<endl;
		cout<<"4-salir"<<endl;

		char opcion_elejida = '0';
		cout<<"elejir opcion: ";
		cin>>opcion_elejida;
		UtilMenu::limpiar_pantalla();
		switch(opcion_elejida){
			case '1' :  {
							menu_principal->iniciar();
							if (menu_principal->getOperacion_fueCreada()){
								operacion_fueCreada = true;
								operacionElejida = menu_principal->getOperacionElejida();
							}
							break;
						}
			case '2' :  {
							if (operacion_fueCreada){
//            					cout<<*operacionElejida<<endl;
							}
							else
								cout<<"debe elejir una operacion"<<endl;
							break;
						}

			case '3' :  {
							if (operacion_fueCreada)
								operacionElejida->iniciar();
							else
								cout<<"debe elejir una operacion"<<endl;
							break;
						}
			case '4' :  {
							salir_programa = true;
							break;
						}
			default : cout<<"opcion de menu invalida"<<endl; break;
		}
	}
//    delete operacionElejida;
//    delete menu_principal;
}
