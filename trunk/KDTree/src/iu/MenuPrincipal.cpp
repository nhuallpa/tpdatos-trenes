/*
 * MenuPrincipal.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(KDTreeController &kdTreeController):kdTreeController(kdTreeController)  {
	// TODO Auto-generated constructor stub

}

MenuPrincipal::~MenuPrincipal() {
	// TODO Auto-generated destructor stub
}

void MenuPrincipal::mostrar(){
    UtilMenu::separador_menu();
    cout<<"Menu Principal"<<endl;
    cout<<"1-alta"<<endl;
    cout<<"2-baja"<<endl;
    cout<<"3-modificacion"<<endl;
    cout<<"4-consulta"<<endl;
    cout<<"5-salir"<<endl;
}

void MenuPrincipal::iniciar()
{
	this->getKdTreeController().init();

	Menu* menu_alta          = new MenuAlta(this->getKdTreeController());
	Menu* menu_baja          = new MenuBaja();
	Menu* menu_modifcacion   = new MenuModificacion();
	Menu* menu_consulta      = new MenuConsulta();

    //primero creo la interfax de usuario cuando se tenga que operar con elementos unitarios
    //y no en conjuntos mediante archivos de configuracion

    bool salir = false;
    while(!salir)
    {
    	this->mostrar();

        char opcion_elejida = '0';
        cout<<"elejir opcion del menu: ";
        cin>>opcion_elejida;
        switch(opcion_elejida)
        {
            case '1' :  UtilMenu::limpiar_pantalla(); menu_alta->iniciar(); break;
            case '2' :  UtilMenu::limpiar_pantalla(); menu_baja->iniciar(); break;
            case '3' :  UtilMenu::limpiar_pantalla(); menu_modifcacion->iniciar(); break;
            case '4' :  UtilMenu::limpiar_pantalla(); menu_consulta->iniciar(); break;
            case '5' :  UtilMenu::limpiar_pantalla(); salir = true; break;
            default : cout<<"opcion de menu invalida"<<endl; break;
        }
    }
    delete menu_alta;
    delete menu_baja;
    delete menu_modifcacion;
    delete menu_consulta;

}
