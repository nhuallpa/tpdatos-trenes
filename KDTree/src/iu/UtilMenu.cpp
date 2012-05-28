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
	os.append("(idLinea=\'"+filtro_entrada[0]+"' ");
	os.append("formacion=\'"+filtro_entrada[1]+"' ");
	os.append("falla=\'"+filtro_entrada[2]+"' ");
	os.append("accidente=\'"+filtro_entrada[3]+"' ");
	os.append("franajHoraria=\'"+filtro_entrada[4]+"')");

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

int UtilMenu::elejir_subElemento_(string tipo_deSubElemento, list<string>& lista, KDTreeController& kdTreeController){
	string idSubElemento;
	mostrarLista(lista);
    int idSubElemento_num;
    bool valida = true;
    do {
		cout<<"Insertar nro de "<<tipo_deSubElemento<<": ";
		cin>>idSubElemento;
		idSubElemento_num = Util::toInt(idSubElemento);
		valida = kdTreeController.validarIdSubElemento(tipo_deSubElemento, idSubElemento_num);
    } while (!valida);
    UtilMenu::limpiar_pantalla();

    return idSubElemento_num;
}
