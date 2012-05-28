/*
 * Menu.h
 *
 *  Created on: 06/05/2012
 *      Author: ariel
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#include "UtilMenu.h"
#include "../controller/KDTreeController.h"
#include "../controller/Operacion.h"
#include "../utils/utiles.h"

class Menu {
public:
	Menu();
	virtual ~Menu();
	virtual void iniciar() = 0;
	virtual Operacion* getOperacionElejida() = 0;
	virtual bool getOperacion_fueCreada() = 0;
private:
	virtual void mostrar() = 0;
};

#endif /* MENU_H_ */
