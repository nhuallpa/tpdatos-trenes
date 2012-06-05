/*
 * Busqueda.cpp
 *
 *  Created on: 05/06/2012
 *      Author: ariel
 */

#include "Busqueda.h"

Busqueda::Busqueda() {
	// TODO Auto-generated constructor stub

}
void encontrar(tTree t){
}
void noEncontrar(typekey key[K]){
}

void Busqueda::iniciar(typekey key[K], tTree t)
{
	int i, index, noteq;
	while(t != 0){
		index = noteq = 0;
		for(i=0 ; i < K ; i++){
			index = noteq << 1;
			if(key[i] > t.k[i]) index++;
			if(key[i] != t.k[i]) noteq++;
		}
		if (noteq) t = t.p[index];
		else {encontrar(t); return;}
	}
	noEncontrar(key);
}

Busqueda::~Busqueda() {
	// TODO Auto-generated destructor stub
}

