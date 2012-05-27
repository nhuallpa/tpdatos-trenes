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

void UtilMenu::verEstructraResultado(string* filtro_salida, int cant_campos_resultado){
	string separador = ",";
	cout<<"(";
	for(int i=0 ; i<cant_campos_resultado ; i++){
		if ((i+1) ==  cant_campos_resultado)
			separador = "";
		cout<<filtro_salida[i]<<separador;
	}
	cout<<") ";
}

void UtilMenu::verEstructuraFiltro(string* filtro_entrada, int cant_campos_enFiltro){
	string separador = ",";
	cout<<"(";
	for(int i=0 ; i<cant_campos_enFiltro ; i++){
		if ((i+1) ==  cant_campos_enFiltro)
			separador = "";
		cout<<filtro_entrada[i]<<separador;
	}
	cout<<") ";
}
