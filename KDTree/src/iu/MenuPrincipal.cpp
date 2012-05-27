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

bool MenuPrincipal::iniciar()
{
	Menu* menu_alta          = new MenuAlta(this->getKdTreeController());
	Menu* menu_baja          = new MenuBaja();
	Menu* menu_modifcacion   = new MenuModificacion();
	Menu* menu_consulta      = new MenuConsulta(this->getKdTreeController());

    bool salir = false;
    bool operacion_esElejida = false;
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
            				operacion_esElejida = menu_alta->iniciar();
            				this->operacionElejida = new OperacionAlta();
							this->operacionElejida = menu_alta->getOperacionElejida();
							break;
            			}

            case '2' :  {
            				operacion_esElejida = menu_baja->iniciar();
            				this->operacionElejida = menu_baja->getOperacionElejida();
            				break;
            			}
            case '3' :  {
            				operacion_esElejida = menu_modifcacion->iniciar();
            				this->operacionElejida = menu_modifcacion->getOperacionElejida();
            				break;
            			}
            case '4' :  {
            				operacion_esElejida = menu_consulta->iniciar();
            				this->operacionElejida = menu_consulta->getOperacionElejida();
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

    return operacion_esElejida;
}

KDTreeController& MenuPrincipal::getKdTreeController() {
	return this->kdTreeController;
}

Operacion* MenuPrincipal::getOperacionElejida()
{
	return this->operacionElejida;
}
