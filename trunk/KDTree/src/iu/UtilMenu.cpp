/*
 * UtilMenu.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "UtilMenu.h"

UtilMenu::UtilMenu() {

}

UtilMenu::~UtilMenu() {

}

void UtilMenu::separador_menu(){
    cout<<"//////////////////////////////////"<<endl;
}

void UtilMenu::limpiar_pantalla(){
    system("clear");
}

string UtilMenu::getNombreSubElemento(int idSubElemento)
{
	string nombresCampos[] = {NOMBRE_LINEA, NOMBRE_FORMACION, NOMBRE_FALLA, NOMBRE_ACCIDENTE, NOMBRE_FRANJAHORARIA };

	string nombreCampo_elejido = "";
	for(int i=0 ; i < CANT_SUBELEMENTOS ; i++){
		if (idSubElemento == i)
			nombreCampo_elejido = nombresCampos[i];
	}

	return nombreCampo_elejido;
}

string UtilMenu::getFiltroEntrada(string* filtro_entrada, int cant_campos_enFiltro){
	string os = "";
	string separador = ",";
	os.append("(");
	for(int i=0 ; i<cant_campos_enFiltro ; i++){
		if ((i+1) ==  cant_campos_enFiltro)
			separador = "";
		os.append(filtro_entrada[i]);
		os.append(separador);
	}
	os.append(") ");
	return os;
}

string UtilMenu::getFiltroSalida(string* filtro_salida, int cant_campos_resultado){
	string os = "";
	string separador = ",";
	os.append("(");
	for(int i=0 ; i<cant_campos_resultado ; i++){
		if ((i+1) ==  cant_campos_resultado)
			separador = "";
		os.append(filtro_salida[i]);
		os.append(separador);
	}
	os.append(") ");
	return os;
}

void UtilMenu::mostrarLista(list<string> & lista) {
	list<string>::iterator it;
	for (it=lista.begin(); it!=lista.end(); it++){
		cout<<*it<<endl;
	}
}
