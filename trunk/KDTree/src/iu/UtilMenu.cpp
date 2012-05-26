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

string UtilMenu::getNombreCampo_segun(int idNombreCampo)
{
	int cantCampos = 5;
	string nombresCampos[] = {"linea", "formacion", "falla", "accidente", "franjaHoraria" };

	string nombreCampo_elejido = "";
	for(int i=0 ; i < cantCampos ; i++){
		if (idNombreCampo == i)
			nombreCampo_elejido = nombresCampos[i];
	}

	return nombreCampo_elejido;
}

void UtilMenu::verEstructraResultado(string* estructura_resultado, int cant_campos_resultado){
	string separador = ",";
	cout<<"(";
	for(int i=0 ; i<cant_campos_resultado ; i++){
		if ((i+1) ==  cant_campos_resultado)
			separador = "";
		cout<<estructura_resultado[i]<<separador;
	}
	cout<<") ";
}

void UtilMenu::verEstructuraFiltro(string* estructura_filtro, int cant_campos_enFiltro){
	string separador = ",";
	cout<<"(";
	for(int i=0 ; i<cant_campos_enFiltro ; i++){
		if ((i+1) ==  cant_campos_enFiltro)
			separador = "";
		cout<<estructura_filtro[i]<<separador;
	}
	cout<<") ";
}
