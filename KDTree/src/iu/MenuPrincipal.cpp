/*
 * MenuPrincipal.cpp
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(KDTreeController &kdTreeController) {
	this->kdTreeController = kdTreeController;
	this->kdTreeController.inicializar();
	this->operacion_fueCreada = false;
}

MenuPrincipal::~MenuPrincipal() {

}

void MenuPrincipal::mostrar(){
    UtilMenu::separador_menu();
    cout<<"Menu Principal(Operaciones)"<<endl;
    cout<<"1-alta"<<endl;
    cout<<"2-baja"<<endl;
    cout<<"3-modificacion"<<endl;
    cout<<"4-consulta"<<endl;
    cout<<"5-salir del menu Principal"<<endl;
}

void MenuPrincipal::iniciar()
{
	Menu* menu_alta          = new MenuAlta(this->getKdTreeController());
	Menu* menu_baja          = new MenuBaja();
	Menu* menu_modifcacion   = new MenuModificacion();
	Menu* menu_consulta      = new MenuConsulta(this->getKdTreeController());

    bool salir = false;
    while(!salir)
    {
    	this->mostrar();

        char opcion_elejida = '0';
        cout<<"elejir opcion del menu: ";
        cin>>opcion_elejida;
        UtilMenu::limpiar_pantalla();
        switch(opcion_elejida)
        {
            case '1' :  {
            				menu_alta->iniciar();
            				if ( menu_alta->getOperacion_fueCreada() )
            					this->operacionElejida = menu_alta->getOperacionElejida();
							this->operacion_fueCreada = menu_alta->getOperacion_fueCreada();
							break;
            			}

            case '2' :  {
            				menu_baja->iniciar();
            				if (menu_baja->getOperacion_fueCreada())
            					this->operacionElejida = menu_baja->getOperacionElejida();
            				this->operacion_fueCreada = menu_baja->getOperacion_fueCreada();
            				break;
            			}
            case '3' :  {
            				menu_modifcacion->iniciar();
            				if ( menu_modifcacion->getOperacion_fueCreada() )
            					this->operacionElejida = menu_modifcacion->getOperacionElejida();
            				this->operacion_fueCreada = menu_modifcacion->getOperacion_fueCreada();
            				break;
            			}
            case '4' :  {
            				menu_consulta->iniciar();
            				if ( menu_consulta->getOperacion_fueCreada() )
            						this->operacionElejida = menu_consulta->getOperacionElejida();
            				this->operacion_fueCreada = menu_consulta->getOperacion_fueCreada();
            				break;
            			}
            case '5' :  {
            				salir = true;
            				break;
            			}
            default : cout<<"opcion de menu invalida"<<endl; break;
        }
    }

    delete menu_alta;
    delete menu_baja;
    delete menu_modifcacion;
    delete menu_consulta;
}

KDTreeController& MenuPrincipal::getKdTreeController() {
	return this->kdTreeController;
}

Operacion* MenuPrincipal::getOperacionElejida(){
	return this->operacionElejida;
}

bool MenuPrincipal::getOperacion_fueCreada(){
	return this->operacion_fueCreada;
}
